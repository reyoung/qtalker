#ifndef HELLOWORLDPLUGIN_H
#define HELLOWORLDPLUGIN_H
#include <iplugin.h>
#include <QObject>

class HelloWorldPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
public:
    explicit HelloWorldPlugin();
    virtual bool Initialize(QStringList& cmdArgs);
signals:

public slots:

};

#endif // HELLOWORLDPLUGIN_H