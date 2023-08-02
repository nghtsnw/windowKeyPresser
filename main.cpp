#include <iostream>
#include <windows.h>

using namespace std;
int d1,d2,d3,d4;
void pressKey(int key);
int intToKey(int i);

int main()
{
    Sleep(5000);
    for (int psw = 0; psw < 10000; psw++)
    {
        d1 = psw/1000%10;
        d2 = psw/100%10;
        d3 = psw/10%10;
        d4 = psw%10;
        cout << psw << endl;
        //enter number
        pressKey(intToKey(d1));
        pressKey(intToKey(d2));
        pressKey(intToKey(d3));
        pressKey(intToKey(d4));
        //press enter
        pressKey(VK_RETURN);
        //wait
        Sleep(300);
        //backspace
        pressKey(VK_BACK);
        pressKey(VK_BACK);
        pressKey(VK_BACK);
        pressKey(VK_BACK);
    }

    cout << "Exit" << endl;
    return 0;
}

void pressKey(int key)
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;


// Press key
    ip.ki.wVk = key;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

// Release key
    ip.ki.wVk = key;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

int intToKey(int i) //from 0 to 9
{
    switch (i)
    {
        case 0:
            return VK_NUMPAD0;
            break;
        case 1:
            return VK_NUMPAD1;
            break;
        case 2:
            return VK_NUMPAD2;
            break;
        case 3:
            return VK_NUMPAD3;
            break;
        case 4:
            return VK_NUMPAD4;
            break;
        case 5:
            return VK_NUMPAD5;
            break;
        case 6:
            return VK_NUMPAD6;
            break;
        case 7:
            return VK_NUMPAD7;
            break;
        case 8:
            return VK_NUMPAD8;
            break;
        case 9:
            return VK_NUMPAD9;
            break;
        default:
            break;
    }
    return 0;
}
