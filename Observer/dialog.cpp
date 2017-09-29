#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),m_pManager(nullptr)
{
    ui->setupUi(this);
    m_pManager = new InputManager(ui->InputBox);
    connect(m_pManager,&InputManager::valueChanged,this,&Dialog::showData);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showData(QString send,QString input)
{
    QString info = send+":"+input;
    ui->textEdit->append(info);
}
