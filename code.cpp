#include <windows.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "VK_keys.h"

std::ofstream outfile{"log.txt", std::ios::app};

std::string currentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_t = std::chrono::system_clock::to_time_t(now);
    std::tm localTime = *std::localtime(&now_t);

    std::ostringstream timeStream;
    timeStream << std::put_time(&localTime, "[%Y-%m-%d %H:%M:%S] ");
    return timeStream.str();
}

void logg(std::string s) {
    if (outfile.is_open()) {
        outfile << currentTime() << s << std::endl;
        std::cout << currentTime() << s << std::endl;
    }
}

int main() {
    int prevCaps = GetKeyState(VK_CAPITAL) & 0x0001 != 0;
    int prevNum = GetKeyState(VK_NUMLOCK) & 0x0001 != 0;
    int prevScroll = GetKeyState(VK_SCROLL) & 0x0001 != 0;
    while (true) {
        //CAPS toggle
        int nowCaps = GetKeyState(VK_CAPITAL) & 0x0001 != 0;
        if (prevCaps != nowCaps) {
            if (nowCaps) logg("{Caps ON}");
            else logg("{CAPS off}");
            prevCaps = nowCaps;
        }
        //NUM toggle
        int nowNum = GetKeyState(VK_NUMLOCK) & 0x0001 != 0;
        if (prevNum != nowNum) {
            if (nowNum) logg("{NUM ON}");
            else logg("{NUM off}");
            prevNum = nowNum;
        }
        //Scroll toggle
        int nowScroll = GetKeyState(VK_SCROLL) & 0x0001 != 0;
        if (prevScroll != nowScroll) {
            if (nowScroll) logg("{Scroll ON}");
            else logg("{Scroll off}");
            prevScroll = nowScroll;
        }
        // Everything Else
        std::ostringstream st; st << "{";
        for (auto x: vkPriority) {

            int keyStat = GetAsyncKeyState(x) & 0x8000;
            UINT scanCode = MapVirtualKey(x, MAPVK_VK_TO_VSC);
            char keyName[128] = {0};
            GetKeyNameTextA((scanCode << 16) | (1 << 24), keyName, sizeof(keyName));

            if (keyStat) st <<  ((st.str().size() > 1)? "+":"") << std::string(keyName) << ((x == VK_LSHIFT)? "Left Shift":"") << ((x == VK_RSHIFT)? "Right Shift":"");
        }
        st << "}";
        if (st.str().size() > 2) logg(st.str());
        Sleep(50);
    }
    return 0;
}