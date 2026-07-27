#include <QApplication>
#include <QTimer>
#include "birdtrayapp.h"
#ifdef Q_OS_WIN
#  include <windows.h>
#  include <cstdio>
#else
#  include <unistd.h>
#  include <cstring>
#endif /* Q_OS_WIN  */

int main(int argc, char *argv[]) {
#ifndef Q_OS_WIN
    bool detach = false;
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--detach") == 0 || std::strcmp(argv[i], "-d") == 0 || std::strcmp(argv[i], "--daemon") == 0) {
            detach = true;
            break;
        }
    }
    if (detach) {
        if (daemon(1, 0) != 0) {
            // ignore failure
        }
    }

    qputenv("QT_DBUS_SYSTEMTRAY_DISABLED", "1");
    QByteArray originalDbus = qgetenv("DBUS_SESSION_BUS_ADDRESS");
    if (!originalDbus.isEmpty()) {
        qputenv("ORIG_DBUS_SESSION_BUS_ADDRESS", originalDbus);
    }
    qputenv("DBUS_SESSION_BUS_ADDRESS", "disabled");
#endif
#ifdef Q_OS_WIN
    if (AttachConsole(ATTACH_PARENT_PROCESS)) {
        // reopen the std I/O streams to redirect I/O to the parents console.
        FILE* newFile = nullptr;
        freopen_s(&newFile, "CON", "w", stdout);
        freopen_s(&newFile, "CON", "w", stderr);
        freopen_s(&newFile, "CON", "r", stdin);
    }
#endif /* Q_OS_WIN */
    BirdtrayApp app(argc, argv);
    return QApplication::exec();
}
