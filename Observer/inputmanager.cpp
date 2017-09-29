#include "inputmanager.h"

InputManager::InputManager(QGroupBox *groupBox)
{
    QObjectList children = groupBox->children();
    foreach (auto child , children) if(child->inherits("QSpinBox") || child->inherits("QLineEdit") || child->inherits("QComboBox") || child->inherits("QTimeEdit"))
    {
        InputEdit *input = new InputEdit(dynamic_cast<QWidget *>(child));
        m_inputData[input->objectName()] = input;
        qDebug() << input;
        connect(input,&InputEdit::valueChanged,this,&InputManager::childWidgetValueChange);
    }
}

void InputManager::childWidgetValueChange()
{
    InputEdit *send = dynamic_cast<InputEdit* >(sender());
    emit valueChanged(send->getName(),send->getValue());
}
