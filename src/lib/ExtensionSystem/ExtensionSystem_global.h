#ifndef EXTENSIONSYSTEM_GLOBAL_H
#define EXTENSIONSYSTEM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined ( EXTENSIONSYSTEM_LIBRARY )
#  define EXTENSIONSYSTEMSHARED_EXPORT Q_DECL_EXPORT
#else
#  define EXTENSIONSYSTEMSHARED_EXPORT Q_DECL_IMPORT
#endif
#endif                                            // EXTENSIONSYSTEM_GLOBAL_H
