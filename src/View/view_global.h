#ifndef VIEWGLOBAL_H
#define VIEWGLOBAL_H

#include <QtCore/qglobal.h>

#ifdef EXPORT_VIEW_MODULE
#define VIEW_EXPORT Q_DECL_EXPORT
#else
#define VIEW_EXPORT Q_DECL_IMPORT
#endif

#endif // VIEWGLOBAL_H