#ifndef HELLOWORLDPLUGIN_H
#define HELLOWORLDPLUGIN_H
#include <ExtensionSystem/iplugin.h>
#include <QObject>

class HelloWorldPlugin : public ExtensionSystem::IPlugin {
    Q_OBJECT
public:
    explicit HelloWorldPlugin();
    virtual bool Initialize(const QStringList& cmdArgs);
signals:

public slots:

};

#endif                                            // HELLOWORLDPLUGIN_H
