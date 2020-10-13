#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setWindowTitle("请登录");
}

login::~login()
{
    delete ui;
}

void login::on_loginBtn_clicked()
{
    // 判断用户名和密码是否正确，
    // 如果错误则弹出警告对话框
        if(ui->usrLineEdit->text() == tr("reuben") &&
               ui->pwdLineEdit->text() == tr("123456"))
        {
           accept();
        } else {
           QMessageBox::warning(this, tr("Waring"),
                                 tr("user name or password error!"),
                                 QMessageBox::Yes);

           ui->pwdLineEdit->clear();
           ui->pwdLineEdit->setFocus();
        }
}
