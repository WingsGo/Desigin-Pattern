#ifndef INPUTEDIT_H
#define INPUTEDIT_H

#include <QObject>
#include <QLineEdit>
#include <QTimeEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QDebug>

class InputEdit : public QObject
{
    Q_OBJECT
public:
    explicit InputEdit(QWidget *input);
    QString getValue();
    QString getName();
signals:
    void valueChanged();

public slots:
private:
    QLineEdit *m_pLineEdit;
    QComboBox *m_pComboBox;
    QTimeEdit *m_pTimeEdit;
    QSpinBox *m_pSpinBox;
    QString m_InputValue;
};

#endif // INPUTEDIT_H
