#ifndef DBUSIMPL_H_LNRSIP31
#define DBUSIMPL_H_LNRSIP31

#include <QMetaClassInfo>
#include <QObject>
#include <QString>

// This macro will be useful, the interface implementer should provide a easy
// way to get the interface.
#define DBUS_INTERFACE_CUSTMIZE(name)                                          \
  const char *name() const {                                                   \
    auto meta = metaObject();                                                  \
    auto idx = meta->indexOfClassInfo("D-Bus Interface");                      \
                                                                               \
    if (idx == -1) {                                                           \
      return nullptr;                                                          \
    }                                                                          \
                                                                               \
    auto info = meta->classInfo(idx);                                          \
                                                                               \
    return info.value();                                                       \
  }

#define DBUS_INTERFACE() DBUS_INTERFACE_CUSTMIZE(interface)

// NB: moc will not handle *.cpp file automaticlly
class X : public QObject {
  Q_OBJECT

  Q_CLASSINFO("D-Bus Interface", "cn.kosl90.dbus.Test")

public:
  DBUS_INTERFACE();

  X(QObject *parent = nullptr) : QObject{parent} {}

  Q_SLOT QString Get() { return QStringLiteral("x"); }
};

#endif /* end of include guard: DBUSIMPL_H_LNRSIP31 */
