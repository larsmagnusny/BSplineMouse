#include "include/BSM/bsplinemouse.h"
#include "include/BSM/bspline.h"
#include <windows.h>
#include <chrono>
#include <cmath>
#include <iostream>

namespace BSplineMouse
{
    Vec2 moveMouseTo(Vec2 mousePos)
    {
        POINT currentMousePosition;
        Vec2 vCurrentMousePosition;
        BSpline curve;
        double time{0}, deltaTime{0};

        chrono::system_clock::time_point nowClock, prevClock;
        chrono::duration<double> delta;

        GetCursorPos(&currentMousePosition);
        vCurrentMousePosition = Vec2(static_cast<double>(currentMousePosition.x), static_cast<double>(currentMousePosition.y));

        //std::cout << "Current position is: " << vCurrentMousePosition.x << ", " << vCurrentMousePosition.y << std::endl;

        curve.makeRandomSplineBetweenTwoPoints(Vec2(), mousePos - vCurrentMousePosition);

        prevClock = chrono::system_clock::now();
        while(time <= 1.0)
        {
            nowClock = chrono::system_clock::now();
            delta = nowClock-prevClock;
            deltaTime = delta.count();

            INPUT input;
            ZeroMemory(&input, sizeof(INPUT));
            input.type = INPUT_MOUSE;

            mousePos = vCurrentMousePosition + curve.evaluateSpline(3, 3, curve.whichInterval(time), time);

            input.mi.dx = static_cast<LONG>(round(mousePos.x))*65536 / GetSystemMetrics(SM_CXSCREEN);
            input.mi.dy = static_cast<LONG>(round(mousePos.y))*65536 / GetSystemMetrics(SM_CYSCREEN);

            input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

            SendInput(1, &input, sizeof(INPUT));

            Sleep(1);

            prevClock = nowClock;
            time += deltaTime * (1.5*sin(time*M_PI)+0.025);
        }

        return mousePos;
    }

    double randRange(double min, double max)
    {
        return((max-min)*(static_cast<double>(rand()) / RAND_MAX)+min);
    }

    void leftMouseClick()
    {
        POINT mousePos;
        GetCursorPos(&mousePos);

        INPUT input;

        ZeroMemory(&input, sizeof(INPUT));

        input.type = INPUT_MOUSE;
        input.mi.dx = mousePos.x*65536 / GetSystemMetrics(SM_CXSCREEN);
        input.mi.dy = mousePos.y*65536 / GetSystemMetrics(SM_CYSCREEN);
        input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP);
        input.mi.mouseData = 0;
        input.mi.dwExtraInfo = 0;
        input.mi.time=0;
        SendInput(1, &input, sizeof(INPUT));
    }

    void rightMouseClick()
    {
        POINT mousePos;
        GetCursorPos(&mousePos);

        INPUT input;

        ZeroMemory(&input, sizeof(INPUT));

        input.type = INPUT_MOUSE;
        input.mi.dx = mousePos.x*65536 / GetSystemMetrics(SM_CXSCREEN);
        input.mi.dy = mousePos.y*65536 / GetSystemMetrics(SM_CYSCREEN);
        input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_RIGHTDOWN|MOUSEEVENTF_RIGHTUP);
        input.mi.mouseData = 0;
        input.mi.dwExtraInfo = 0;
        input.mi.time=0;
        SendInput(1, &input, sizeof(INPUT));
    }

    void scrollMouseClick()
    {
        POINT mousePos;
        GetCursorPos(&mousePos);

        INPUT input;

        ZeroMemory(&input, sizeof(INPUT));

        input.type = INPUT_MOUSE;
        input.mi.dx = mousePos.x*65536 / GetSystemMetrics(SM_CXSCREEN);
        input.mi.dy = mousePos.y*65536 / GetSystemMetrics(SM_CYSCREEN);
        input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_MIDDLEDOWN|MOUSEEVENTF_MIDDLEUP);
        input.mi.mouseData = 0;
        input.mi.dwExtraInfo = 0;
        input.mi.time=0;
        SendInput(1, &input, sizeof(INPUT));
    }
}
