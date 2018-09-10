# test DBus configration

## Intro

Test dbus configuration file.


## Howto

Install this file into $(sysconfig)/dbus-1/session.d/, usually /etc/dbus-1/session.d.

Changing the group name is the simplest way to test it.

Use d-feet or something like it to invoke the `cn.kosl90.dbus.Test.Get` method in the `/` path of `cn.kosl90.dbus.Test` service.


## Ref

- man dbus-daemon
- QMetaClassInfo/QMetaObject/Q\_CLASSINFO
- [kde's dbus tutorial](https://techbase.kde.org/Development/Tutorials/D-Bus)
