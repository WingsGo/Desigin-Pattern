#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "inputmanager.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
private slots:
    void showData(QString send, QString input);
private:
    Ui::Dialog *ui;
    InputManager *m_pManager;
};

#endif // DIALOG_H
