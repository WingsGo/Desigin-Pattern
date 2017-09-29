#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <QObject>
#include <QGroupBox>
#include <QMap>
#include <QDebug>
#include "inputedit.h"

typedef QMap<QString,InputEdit*> InputMapper;

class InputManager : public QObject
{
    Q_OBJECT
public:
    explicit InputManager(QGroupBox *groupBox);

signals:
    void valueChanged(QString sender,QString input);
public slots:
    void childWidgetValueChange();
private:
    InputMapper m_inputData;
};

#endif // INPUTMANAGER_H
