#include "inputedit.h"

InputEdit::InputEdit(QWidget *input) : QObject(input),
    m_pComboBox(nullptr),
    m_pSpinBox(nullptr),
    m_pLineEdit(nullptr),
    m_pTimeEdit(nullptr)
{
    if(input->inherits("QComboBox"))
    {
        m_pComboBox = dynamic_cast<QComboBox* >(input) ;
        connect(m_pComboBox,&QComboBox::currentTextChanged,this,&InputEdit::valueChanged);
    }
    if(input->inherits("QSpinBox"))
    {
        m_pSpinBox = dynamic_cast<QSpinBox* > (input);
        connect(m_pSpinBox,&QSpinBox::editingFinished,this,&InputEdit::valueChanged);
    }

    if(input->inherits("QLineEdit"))
    {
        m_pLineEdit = dynamic_cast<QLineEdit* > (input);
        connect(m_pLineEdit,&QLineEdit::editingFinished,this,&InputEdit::valueChanged);
    }

    if(input->inherits("QTimeEdit"))
    {
        m_pTimeEdit = dynamic_cast<QTimeEdit* > (input);
        connect(m_pTimeEdit,&QTimeEdit::dateTimeChanged,this,&InputEdit::valueChanged);
    }
}

QString InputEdit::getValue()
{
    if(m_pComboBox)
        return m_pComboBox->currentText();
    if(m_pLineEdit)
        return m_pLineEdit->text();
    if(m_pSpinBox)
        return m_pSpinBox->text();
    if(m_pTimeEdit)
        return m_pTimeEdit->text();
    return QString("");
}

QString InputEdit::getName()
{
    if(m_pComboBox)
        return m_pComboBox->objectName();
    if(m_pLineEdit)
        return m_pLineEdit->objectName();
    if(m_pSpinBox)
        return m_pSpinBox->objectName();
    if(m_pTimeEdit)
        return m_pTimeEdit->objectName();
    return QString("");
}
