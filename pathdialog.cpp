#include <QtGui>

#include "pathdialog.h"
#include "ui_pathdialog.h"

PathDialog::PathDialog(QString curPro, QWidget *parent)
		: QDialog(parent), ui(new Ui::PathDialogClass)
{
	ui->setupUi(this);

	currentProject = curPro;

	connect(ui->pushButton_browse, SIGNAL(clicked()),
			this, SLOT(addRootPath()));
	connect(ui->pushButton_cancel, SIGNAL(clicked()),
			this, SLOT(close()));
	connect(ui->pushButton_indexer, SIGNAL(clicked()),
			this, SLOT(traverse()));

	QRegExp regExp("([A-Za-z]+|[*])[.][A-Za-z]+([|]([A-Za-z]+|[*])[.][A-Za-z]+)*");
	ui->lineEdit_filter->setValidator(new QRegExpValidator(regExp, this));
}

PathDialog::~PathDialog()
{
	delete ui;
}

void PathDialog::closeEvent(QCloseEvent *event)
{
	parentWidget()->close();
	event->accept();
}

void PathDialog::init()
{
	ui->lineEdit_path->clear();
	ui->lineEdit_filter->clear();

	rootPath.clear();
	filters.clear();
	allPath.clear();
}

void PathDialog::traverse()
{
	if(!rootPath.isEmpty()) {
		QDir dir;

		if(!dir.mkpath(QString("project") + QDir::separator() + projectName)) {
			QMessageBox::information(this, "错误", "工程创建失败");
			return;
		}

		QFile file(QString("project") + QDir::separator() + projectName + QDir::separator() + "dcpt.txt");
		if (!file.open(QIODevice::WriteOnly)) {
			QMessageBox::information(this, "错误", "写入描述错误");
			return;
		}

		QTextStream out(&file);
		out << projectDcpt;

		getPath(rootPath);

		QMessageBox::warning(this, "文件总数", "共找到" + QString::number(allPath.size()) + "个满足条件的文件");
		writePath();
	}
	else
		QMessageBox::warning(this, "提示", "请先导入目录");
}

void PathDialog::getPath(const QString &path)
{
	QDir dir(path);

	if (filters.count() == 0)
	{
		if(ui->checkBox_h->isChecked())
			filters += "*.h";
		if(ui->checkBox_hpp->isChecked())
			filters += "*.hpp";
		if(ui->checkBox_s->isChecked())
			filters += "*.s";
		if(ui->checkBox_c->isChecked())
			filters += "*.c";
		if(ui->checkBox_cpp->isChecked())
			filters += "*.cpp";
		if(ui->checkBox_S->isChecked())
			filters += "*.S";
	}

	if ( ! ui->lineEdit_filter->text().isEmpty())
	{
		QStringList ff = ui->lineEdit_filter->text().split("|");
		filters += ff;
	}

	std::string s;
	foreach (QString file, dir.entryList(filters, QDir::Files)) {
		s = (QDir::toNativeSeparators(QFileInfo(dir, file).path() + QDir::separator() + file)).toLocal8Bit().data();
		allPath.push_back(s);
	}

	if(ui->checkBox_digui->isChecked())
		foreach (QString subDir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
			getPath(path + QDir::separator() + subDir);
}

void PathDialog::writePath()
{
	QFile file(QString("project") + QDir::separator() + currentProject + QDir::separator() + "path.txt");
	if (!file.open(QIODevice::WriteOnly)) {
		QMessageBox::warning(this, tr("Error"), tr("Cannot open file for writing"));
		return;
	}

	QTextStream out(&file);

	Indexer indexer;
	indexer.ctrl_search((QString("project")  + QDir::separator() + currentProject).toLocal8Bit().data(), allPath);

	out << rootPath << "\r\n";
	out << filters.join("|") << "\r\n";
	if(ui->checkBox_digui->isChecked())
		out << "recursive" << "\r\n";
	else
		out << "norecursive" << "\r\n";
	for(unsigned int i = 0; i < allPath.size(); i++)
		out << QString(allPath.at(i).c_str()).replace("\\", "/") << "\r\n";

	QMessageBox::warning(this, "完成", "工程\"" + projectName + "\"已经成功建立");
	close();
}



void PathDialog::addRootPath()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
													"/home",
													QFileDialog::ShowDirsOnly
													| QFileDialog::DontResolveSymlinks);
	if(!dir.isEmpty()) {
		ui->lineEdit_path->setText(dir.replace("/", QDir::separator()));
		rootPath = dir;
	}
}

void PathDialog::setProject(QString name, QString dcpt)
{
	projectName = name;
	projectDcpt = dcpt;
	currentProject = name;
}
