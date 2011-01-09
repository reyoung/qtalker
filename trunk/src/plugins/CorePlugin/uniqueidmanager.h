#ifndef UNIQUEIDMANAGER_H
#define UNIQUEIDMANAGER_H
#include "CorePlugin_global.h"
#include <QtCore>
namespace CorePlugin
{
    class UniqueIDManager;
    class COREPLUGINSHARED_EXPORT ID
    {
    public:
        ID(){}
        ID(const char * str):m_data(str){}
        ID(const QByteArray& str):m_data(str){}
        operator QString()const{return m_data;}
        bool isValid()const{return !m_data.isEmpty();}
        bool operator == (const ID& other)const{return this->m_data==other.m_data;}
        bool operator != (const ID& other)const{return this->m_data!=other.m_data;}
    private:
        QString m_data;
        friend class UniqueIDManager;
    };


    class COREPLUGINSHARED_EXPORT UniqueIDManager
    {
    private:
        UniqueIDManager();
        ~UniqueIDManager();
    public:
        static UniqueIDManager* instance(){return m_instance;}
        static void init();
        bool hasUID(const ID& id);
        int getUID(const ID& id);
        QString uidToString(const int i);
    private:
        QHash<ID,int> m_uids;


        static UniqueIDManager* m_instance;
    };
}
#endif // UNIQUEIDMANAGER_H
