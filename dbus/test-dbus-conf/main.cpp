#include <QString>
#include <QDBusConnection>
#include <QCoreApplication>
#include "test_adaptor.h"
#include "DBusImpl.h"

constexpr char* kServiceName = "cn.kosl90.dbus.Test";

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QDBusConnection bus = QDBusConnection::sessionBus();

    if (!bus.isConnected()) {
        fprintf(stderr, "dbus is not connected");
        exit(1);
    }

    if (!bus.registerService(kServiceName)) {
        fprintf(stderr, "register service failed");
        exit(1);
    }

    auto d = new X{&app};
    new TestAdaptor{d};

    if (!bus.registerObject("/", d->interface(), d)) {
        fprintf(stderr, "register object failed");
    }

    return app.exec();
}
