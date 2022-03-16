#ifndef KEYHOOK_H
#define KEYHOOK_H

#include <QObject>
#include <windows.h>

class KeyHook : public QObject
{
    Q_OBJECT

signals:
    emit void keyDown();
};

static HHOOK hook;
extern KeyHook* keyHook;
int setKeyHook();
LRESULT CALLBACK keyHookProc(int nCode,WPARAM wParam,LPARAM lParam);
void unloadKeyHook();


#endif // KEYHOOK_H
