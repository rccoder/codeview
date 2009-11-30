#include <QtGui/QPainter>
#include <QtGui/QTextBlock>
#include <QtGui/QFileDialog>
#include <QtGui/QMessageBox>

#include <QtCore/QTextStream>
#include <QApplication>

#include "linenumberarea.h"
#include "indenter.h"

#define TAB_SIZE 4

typedef SharedTools::Indenter<QStringList::const_iterator> Indenter;

CodeEditer::CodeEditer(QTabWidget *parent) : QPlainTextEdit(parent), parent(parent)
{
	lineNumberArea = new LineNumberArea(this);

	connect(this, SIGNAL(blockCountChanged(int)),
			this, SLOT(updateLineNumberAreaWidth(int)));
	connect(this, SIGNAL(updateRequest(const QRect &, int)),
			this, SLOT(updateLineNumberArea(const QRect &, int)));
	connect(this, SIGNAL(cursorPositionChanged()),
			this, SLOT(highlightCurrentLine()));
	connect(this, SIGNAL(textChanged ()),
			this, SLOT(setTab()));
	connect(document(), SIGNAL(modificationChanged (bool)),
			this, SLOT(setFileChange(bool)));

	updateLineNumberAreaWidth(0);
	highlightCurrentLine();

	QFont font("Courier");
	font.setPointSize(10);
	setFont(font);
	setTab();
}

void CodeEditer::setTab()
{
	QFont font = this->font();
	QFontMetrics fm(font);
	int pixelsWide = fm.width("x");
	setTabStopWidth(TAB_SIZE * pixelsWide);
}

int CodeEditer::lineNumberAreaWidth()
{
	int digits = 1;
	int max = qMax(1, blockCount());
	while (max >= 10) {
		max /= 10;
		++digits;
	}

	int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

	return space;
}



void CodeEditer::updateLineNumberAreaWidth(int /* newBlockCount */)
{
	setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}



void CodeEditer::updateLineNumberArea(const QRect &rect, int dy)
{
	if (dy)
		lineNumberArea->scroll(0, dy);
	else
		lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

	if (rect.contains(viewport()->rect()))
		updateLineNumberAreaWidth(0);
}

QSize CodeEditer::sizeHint() const
{
	return QSize(72 * fontMetrics().width('x'),
				 25 * fontMetrics().lineSpacing());
}

void CodeEditer::highlightCurrentLine()
{
	/*QList<QTextEdit::ExtraSelection> extraSelections;

	if (!isReadOnly()) {
		QTextEdit::ExtraSelection selection;

		QColor lineColor = QColor(Qt::yellow).lighter(160);

		selection.format.setBackground(lineColor);
		selection.format.setProperty(QTextFormat::FullWidthSelection, true);
		selection.cursor = textCursor();
		selection.cursor.clearSelection();
		extraSelections.append(selection);
	}

	setExtraSelections(extraSelections);*/
}

void CodeEditer::lineNumberAreaPaintEvent(QPaintEvent *event)
{
	QPainter painter(lineNumberArea);
	painter.fillRect(event->rect(), Qt::lightGray);


	QTextBlock block = firstVisibleBlock();
	int blockNumber = block.blockNumber();
	int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
	int bottom = top + (int) blockBoundingRect(block).height();

	while (block.isValid() && top <= event->rect().bottom()) {
		if (block.isVisible() && bottom >= event->rect().top()) {
			QString number = QString::number(blockNumber + 1);
			painter.setPen(Qt::black);
			painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
							 Qt::AlignRight, number);
		}

		block = block.next();
		top = bottom;
		bottom = top + (int) blockBoundingRect(block).height();
		++blockNumber;
	}
}

void CodeEditer::resizeEvent(QResizeEvent *e)
{
	QPlainTextEdit::resizeEvent(e);

	QRect cr = contentsRect();
	lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

bool CodeEditer::save()
{
	if (isUntitled) {
		return saveAs();
	} else {
		return saveFile(fileName);
	}
}

bool CodeEditer::saveAs()
{
	QString fName =
			QFileDialog::getSaveFileName(this, "Áí´æÎª", fileName);
	if (fName.isEmpty())
		return false;

	return saveFile(fName);
}

bool CodeEditer::saveFile(const QString &fileName)
{
	if (writeFile(fileName)) {
		setCurrentFile(fileName);
		return true;
	} else {
		return false;
	}
}

void CodeEditer::setCurrentFile(const QString &fName)
{
	fileName = fName;
	isUntitled = false;
	document()->setModified(false);
	parent->setTabText(parent->currentIndex(), QFileInfo(fileName).fileName());
}

bool CodeEditer::readFile(const QString &fileName)
{
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QMessageBox::warning(this, tr("CodeView"),
							 tr("Cannot read file %1:\n%2.")
							 .arg(file.fileName())
							 .arg(file.errorString()));
		return false;
	}

	QTextStream in(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	setPlainText(in.readAll());
	QApplication::restoreOverrideCursor();
	return true;
}

bool CodeEditer::writeFile(const QString &fileName)
{
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		QMessageBox::warning(this, tr("CodeView"),
							 tr("Cannot write file %1:\n%2.")
							 .arg(file.fileName())
							 .arg(file.errorString()));
		return false;
	}

	QTextStream out(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	out << toPlainText();
	QApplication::restoreOverrideCursor();
	return true;
}

QString CodeEditer::strippedName(const QString &fullFileName)
{
	return QFileInfo(fullFileName).fileName();
}

int CodeEditer::format()
{
	const QString code = this->toPlainText();
	//const QString code = this->textCursor().selectedText();
	if (code == QString::null)
		return 1;

	QStringList program = code.split(QLatin1Char('\n'), QString::KeepEmptyParts);
	while (!program.isEmpty()) {
		if (!program.back().trimmed().isEmpty())
			break;
		program.pop_back();
	}

	QStringList p;
	QString out;

	const QChar colon = QLatin1Char(':');
	const QChar blank = QLatin1Char(' ');
	const QChar newLine = QLatin1Char('\n');

	QStringList::const_iterator cend = program.constEnd();
	for (QStringList::const_iterator it = program.constBegin(); it != cend; ++it) {
		p.push_back(*it);
		QString &line = p.back();

		QChar typedIn = Indenter::instance().firstNonWhiteSpace(line);
		if (p.last().endsWith(colon))
			typedIn = colon;

		const int indent = Indenter::instance().indentForBottomLine(it, p.constBegin(), p.constEnd(), typedIn);

		const QString trimmed = line.trimmed();
		// Indent the line in the list so that the formatter code sees the indented line.
		if (!trimmed.isEmpty()) {
			line = QString(indent, blank);
			line += trimmed;
		}
		out += line;
		out += newLine ;
	}

	while (out.endsWith(newLine))
		out.truncate(out.length() - 1 );

	//fputs(out.toUtf8().constData(), stdout);
	this->setPlainText(out);
	return 0;
}

void CodeEditer::keyPressEvent(QKeyEvent *e)
{
	if (e == QKeySequence::InsertParagraphSeparator
		|| e == QKeySequence::InsertLineSeparator) {
		QTextCursor cursor = textCursor();
		//if (d->m_inBlockSelectionMode)
		//cursor.clearSelection();
		//if (d->m_document->tabSettings().m_autoIndent) {
		cursor.beginEditBlock();
		cursor.insertBlock();
		indent(document(), cursor, QChar::Null);
		cursor.endEditBlock();
		//} else {
		//cursor.insertBlock();
		//}
		e->accept();
		setTextCursor(cursor);
		return;
	}

	e->accept();
	QPlainTextEdit::keyPressEvent(e);
}

void CodeEditer::indent(QTextDocument *doc, const QTextCursor &cursor, QChar typedChar)
{
	if (cursor.hasSelection()) {
		QTextBlock block = doc->findBlock(qMin(cursor.selectionStart(), cursor.selectionEnd()));
		const QTextBlock end = doc->findBlock(qMax(cursor.selectionStart(), cursor.selectionEnd())).next();
		do {
			indentBlock(doc, block, typedChar);
			block = block.next();
		} while (block.isValid() && block != end);
	} else {
		indentBlock(doc, cursor.block(), typedChar);
	}
}

void CodeEditer::indentBlock(QTextDocument *doc, QTextBlock block, QChar typedChar)
{
	Q_UNUSED(typedChar);

	// At beginning: Leave as is.
	if (block == doc->begin())
		return;

	const QTextBlock previous = block.previous();
	const QString previousText = previous.text();
	// Empty line indicates a start of a new paragraph. Leave as is.
	if (previousText.isEmpty() || previousText.trimmed().isEmpty())
		return;

	// Just use previous line.
	// Skip non-alphanumerical characters when determining the indentation
	// to enable writing bulleted lists whose items span several lines.
	int i = 0;
	while (i < previousText.size()) {
		if (previousText.at(i).isLetterOrNumber() ||
			previousText.at(i) == '{' ||
			previousText.at(i) == '}' ||
			previousText.at(i) == '#') {
			//const TextEditor::TabSettings &ts = tabSettings();
			indentLine(block, columnAt(previousText, i));
			break;
		}
		++i;
	}
}

void CodeEditer::indentLine(QTextBlock block, int newIndent) const
{
	const QString text = block.text();
	const int oldBlockLength = text.size();

	// Quickly check whether indenting is required.
	if (oldBlockLength == 0 && newIndent == 0)
		return;

	const QString indentString = indentationString(0, newIndent);
	newIndent = indentString.length();

	if (oldBlockLength == indentString.length() && text == indentString)
		return;

	if (oldBlockLength > indentString.length() &&
		text.startsWith(indentString) &&
		!text.at(indentString.length()).isSpace()) {
		return;
	}

	QTextCursor cursor(block);
	cursor.beginEditBlock();
	cursor.movePosition(QTextCursor::StartOfBlock);
	cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, firstNonSpace(text));
	cursor.removeSelectedText();
	cursor.insertText(indentString);
	cursor.endEditBlock();
}

QString CodeEditer::indentationString(int startColumn, int targetColumn) const
{
	targetColumn = qMax(startColumn, targetColumn);
	//if (m_spacesForTabs)
	//return QString(targetColumn - startColumn, QLatin1Char(' '));

	QString s;
	int alignedStart = startColumn - (startColumn % TAB_SIZE) + TAB_SIZE;
	if (alignedStart > startColumn && alignedStart <= targetColumn) {
		s += QLatin1Char('\t');
		startColumn = alignedStart;
	}
	if (int columns = targetColumn - startColumn) {
		int tabs = columns / TAB_SIZE;
		s += QString(tabs, QLatin1Char('\t'));
		s += QString(columns - tabs * TAB_SIZE, QLatin1Char(' '));
	}
	return s;
}

int CodeEditer::columnAt(const QString &text, int position) const
{
	int column = 0;
	for (int i = 0; i < position; ++i) {
		if (text.at(i) == QLatin1Char('\t'))
			column = column - (column % TAB_SIZE) + TAB_SIZE;
		else
			++column;
	}
	return column;
}

int CodeEditer::firstNonSpace(const QString &text) const
{
	int i = 0;
	while (i < text.size()) {
		if (!text.at(i).isSpace())
			return i;
		++i;
	}
	return i;
}

void CodeEditer::wheelEvent(QWheelEvent *e)
{
	//d->clearVisibleCollapsedBlock();
	if (e->modifiers() & Qt::ControlModifier) {
		const int delta = e->delta();
		if (delta < 0)
			zoomOut();
		else if (delta > 0)
			zoomIn();
		return;
	}
	QPlainTextEdit::wheelEvent(e);
}

void CodeEditer::zoomIn(int range)
{
	//d->clearVisibleCollapsedBlock();
	QFont f = font();
	const int newSize = f.pointSize() + range;
	if (newSize <= 0)
		return;
	f.setPointSize(newSize);
	setFont(f);
}

void CodeEditer::zoomOut(int range)
{
	zoomIn(-range);
}

void CodeEditer::setFileChange(bool changed)
{
//	QString fn = parent->tabText(parent->currentIndex());
//	if(document()->isModified() && fn.at(fn.length() - 1) != '*')
//		parent->setTabText(parent->currentIndex(), fn + "*");
	if(changed)
		parent->setTabText(parent->currentIndex(), QFileInfo(fileName).fileName() + "*");
	else
		parent->setTabText(parent->currentIndex(), QFileInfo(fileName).fileName());
}
