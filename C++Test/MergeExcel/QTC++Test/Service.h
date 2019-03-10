#ifndef SERVICE_H
#define SERVICE_H
#include <QObject>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QDir>
#include<QDialog>
#include<QComboBox>
#include<QTableWidget>
#include<QHBoxLayout>
#include<QMessageBox>

class Service : public QDialog
{
    Q_OBJECT
public:
    Service(QWidget *parent = 0);

    static void updateComboBox(QComboBox *comboBox);

public slots:
    void browse();
    void find();
    void find1();
    void find2();
//    void openFile(int row, int col);
    void getTablePathContent(int row, int col);
    void acceptTransferPythonMsgIsFinished(const std::string&);
    void acceptTransferPythonMsgIsError(const std::string&);

signals:
    void notifyPythonClass(const QString &After, const QString &Before);

private:
    QStringList findFilesByContent(const QStringList &files, const QString &text);
    void showFiles(const QStringList &files);
    QPushButton *createButton(const QString &text, const char *member);
    QComboBox *createComboBox(const QString &text = QString());
    void createFilesTable();

    QString getConText();
    QString getQLineEditAfter();
    QString getQLineEditBefore();

    QComboBox *qComboBoxFile;  // file name search
    QLineEdit *qLineEditAfter;
    QLineEdit *qLineEditBefore;
    QLabel *qFileLabel;
    QLabel *qTextLabel;
    QLabel *qDirectoryLabel;
    QLabel *qFilesFoundLabel;

    QPushButton *qFindButtonBrowse;
    QPushButton *qFindButtonSelect;
    QPushButton *qFindButtonafter;
    QPushButton *qFindButtonBefore;
    QTableWidget *qfilesTable;   //表格类
    QDir qDir;

    QString qFilePathSearch;
    QString conText;
};
#endif // SERVICE_H
