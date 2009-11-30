#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H

//#include "linenumberarea.h"
//textEdit = new

#include <QtGui/QTabWidget>
#include <QtGui/QPlainTextEdit>

class LineNumberArea;


class CodeEditer : public QPlainTextEdit
{
	Q_OBJECT

public:
	CodeEditer(QTabWidget *parent = 0);

	QSize sizeHint() const;

	void lineNumberAreaPaintEvent(QPaintEvent *event);
	int lineNumberAreaWidth();
	bool save();
	bool saveAs();
	bool readFile(const QString &fileName);
	bool writeFile(const QString &fileName);
	int format();

	bool isUntitled;
	QString fileName;

protected:
	void resizeEvent(QResizeEvent *event);
	void keyPressEvent(QKeyEvent *e);
	void wheelEvent(QWheelEvent *e);

private slots:
	void updateLineNumberAreaWidth(int newBlockCount);
	void highlightCurrentLine();
	void updateLineNumberArea(const QRect &, int);

	void zoomIn(int range = 1);
	void zoomOut(int range = 1);

	void setTab();
	void setFileChange(bool);
	
private:
	bool saveFile(const QString &fileName);
	void setCurrentFile(const QString &fileName);
	QString strippedName(const QString &fullFileName);

	void indent(QTextDocument *doc, const QTextCursor &cursor, QChar typedChar);
	void indentBlock(QTextDocument *doc, QTextBlock block, QChar typedChar);
	void indentLine(QTextBlock block, int newIndent) const;
	QString indentationString(int startColumn, int targetColumn) const;
	int columnAt(const QString &text, int position) const;
	int firstNonSpace(const QString &text) const;

	QString curFile;
	QAction *action;

	QWidget *lineNumberArea;
	QTabWidget *parent;
};


class LineNumberArea : public QWidget
{
public:
	LineNumberArea(CodeEditer *editor) : QWidget(editor) {
		codeEditer = editor;
	}

	QSize sizeHint() const {
		return QSize(codeEditer->lineNumberAreaWidth(), 0);
	}

protected:
	void paintEvent(QPaintEvent *event) {
		codeEditer->lineNumberAreaPaintEvent(event);
	}

private:
	CodeEditer *codeEditer;
};


#endif // LINENUMBERAREA_H
