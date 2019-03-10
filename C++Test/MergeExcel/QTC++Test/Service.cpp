#include"Service.h"
#include<QProgressDialog>
#include<QtCore>
#include<QTextStream>
#include<QCoreApplication>
#include<QFileDialog>
#include<QDesktopServices>
#include<iostream>
#include"CommunicationClass.h"
#include"ProjectDef.h"

using namespace std;

Service::Service(QWidget *parent) :
    QDialog(parent),
    conText("")
{
    qFindButtonBrowse = createButton(tr(QFINDBUTTONTARGET_NAME), SLOT(browse()));

    qFindButtonafter = createButton(tr(QFINDBUTTON_AFTER_NAME), SLOT(find()));
    qFindButtonSelect = createButton(tr(QFINDBUTTON_BEFOER_NAME), SLOT(find1()));
    qFindButtonBefore = createButton(tr(QFINDBUTTON_BUILD_NAME), SLOT(find2()));

    QDir::setCurrent(MERGEEXCELPATH);
    qComboBoxFile = createComboBox(QDir::currentPath());
    qLineEditAfter = new QLineEdit(this);
    qLineEditBefore = new QLineEdit(this);

    qFileLabel = new QLabel(tr(QFILELABLE_NAME));
    qTextLabel = new QLabel(tr(QTEXTLABLE_NAME));
    qDirectoryLabel = new QLabel(tr(QDIRLABLE_NAME));
    qFilesFoundLabel = new QLabel;

    createFilesTable();
    CommunicationClass::QSignalSlotsBindService(this);

    QHBoxLayout * qHBox = new QHBoxLayout;
    qHBox->addStretch();
    qHBox->addWidget(qFindButtonBrowse);

    QGridLayout *qGL = new QGridLayout;  //控件布局
    qGL->addWidget(qFileLabel, 0, 0);
    qGL->addWidget(qComboBoxFile, 0, 1);
    qGL->addWidget(qFindButtonSelect, 0, 2);
    qGL->addWidget(qTextLabel, 1, 0);
    qGL->addWidget(qLineEditAfter, 1, 1);
    qGL->addWidget(qFindButtonafter, 1, 2);
    qGL->addWidget(qDirectoryLabel, 2, 0);
    qGL->addWidget(qLineEditBefore, 2, 1);
    qGL->addWidget(qFindButtonBefore, 2, 2);
    qGL->addWidget(qfilesTable, 3, 0, 1, 3);
    qGL->addWidget(qFilesFoundLabel, 4, 0, 1, 3);
    qGL->addLayout(qHBox, 5, 0, 1, 3);
    setLayout(qGL);

    setWindowTitle(QFINDFILES_NAME);
    resize(950, 550);
}

QPushButton *Service::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

QComboBox *Service::createComboBox(const QString &text)
{
    QComboBox *qCb = new QComboBox;
    qCb->setEditable(true); //is edit
    qCb->addItem(text);
    qCb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred); //This property holds the default layout behavior of the widge
    return qCb;
}

void Service::createFilesTable()
{
    qfilesTable = new QTableWidget(0, 2);  //新建一0行2列的表格
    qfilesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList labels;
    labels << tr("File Name") << tr("Size");
    qfilesTable->setHorizontalHeaderLabels(labels);  //设置表格行标题
    qfilesTable->setShowGrid(false);
//    connect(qfilesTable, SIGNAL(cellActivated(int,int)), this, SLOT(openFile(int, int)));
    connect(qfilesTable, SIGNAL(cellActivated(int,int)), this, SLOT(getTablePathContent(int, int)));
}

void Service::browse()
{
    QString after = qLineEditAfter->text();
    QString before = qLineEditBefore->text();
    emit notifyPythonClass(after, before);
}

void Service::find1()
{
    qfilesTable->setRowCount(0);
    QString path = qComboBoxFile->currentText();

    updateComboBox(qComboBoxFile);

    qDir = QDir(path);
    QStringList files;

    files = qDir.entryList(QStringList(), QDir::Files | QDir::NoSymLinks);  //by path search
    showFiles(files);
}

void Service::find()
{
    qLineEditAfter->setText(getConText());
    qLineEditAfter->setReadOnly(true);
}

void Service::find2()
{
    qLineEditBefore->setText(getConText());
    qLineEditBefore->setReadOnly(true);
}

void Service::showFiles(const QStringList &files)
{
    for (int i = 0; i < files.size(); ++i) {
        std::cout<<files[i].toStdString()<<std::endl; //log

        QFile file(qDir.absoluteFilePath(files[i]));
        qint64 size = QFileInfo(file).size();

        QTableWidgetItem *fileNameItem = new QTableWidgetItem(files[i]);
        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *sizeItem = new QTableWidgetItem(tr("%1 KB").arg(int((size + 1023) / 1024)));

        sizeItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        sizeItem->setFlags(sizeItem->flags() ^ Qt::ItemIsEditable);

        int row = qfilesTable->rowCount();
        qfilesTable->insertRow(row);
        qfilesTable->setItem(row, 0, fileNameItem);
        qfilesTable->setItem(row, 1, sizeItem);
    }
    qFilesFoundLabel->setText(tr("%1 file(s) found").arg(files.size()) +
                                 (" (Double click on a file to open it)"));
}

void Service::getTablePathContent(int row, int col) {
    QTableWidgetItem *Item = qfilesTable->item(row, 0);
    std::cout<<qDir.absoluteFilePath(Item->text()).toStdString()<<std::endl;
    conText = qDir.absoluteFilePath(Item->text());
}

QString Service::getConText() {
    return conText;
}

QString Service::getQLineEditAfter()
{
    return qLineEditAfter->text();
}

QString Service::getQLineEditBefore()
{
    return qLineEditBefore->text();
}

//void Service::openFile(int row, int col)
//{
//    QTableWidgetItem *item = qfilesTable->item(row, 0);
//    QDesktopServices::openUrl(QUrl::fromLocalFile(qDir.absoluteFilePath(item->text())));
//}

void Service::updateComboBox(QComboBox *comboBox)
{
    if (comboBox->findText(comboBox->currentText()) == -1) {
        comboBox->addItem(comboBox->currentText()); //This property holds the current text
    }
}

void Service::acceptTransferPythonMsgIsFinished(const std::string& msg)
{
    if(msg == QPROJECT_FINISHED) {
        QMessageBox::StandardButtons reply;
        reply = QMessageBox::information(this, tr("Finished"),tr("Merge Excel is finished!"));
    }
}

void Service::acceptTransferPythonMsgIsError(const std::string& msg)
{
    if(msg == QPROJECT_ERROR) {
        QMessageBox::StandardButtons reply;
        reply = QMessageBox::information(this, tr("Error"),tr("please select sheet!"));
    }
}
