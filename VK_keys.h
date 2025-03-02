// myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

extern std::vector<int> vkPriority = {
    // Modifier Keys (Highest Priority)
    VK_LWIN, VK_RWIN,  // Windows/Super Key
    VK_LCONTROL, VK_RCONTROL,  // Ctrl
    VK_LSHIFT, VK_RSHIFT,  // Shift
    VK_LMENU, VK_RMENU,  // Alt

    // System Keys
    VK_ESCAPE, VK_TAB, VK_CAPITAL,  // Esc, Tab, Caps Lock

    // Function Keys
    VK_F12, VK_F11, VK_F10, VK_F9, VK_F8, VK_F7, 
    VK_F6, VK_F5, VK_F4, VK_F3, VK_F2, VK_F1,

    // Navigation Keys
    VK_INSERT, VK_DELETE, VK_HOME, VK_END, 
    VK_PRIOR, VK_NEXT,  // Page Up, Page Down
    VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT,  // Arrow keys

    // Special Character Keys
    VK_RETURN, VK_BACK, VK_SPACE,  // Enter, Backspace, Space

    // Common Character Keys (A-Z)
    'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 
    'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A',

    // Number Keys (0-9)
    '9', '8', '7', '6', '5', '4', '3', '2', '1', '0',

    // Symbol Keys (Common ones)
    VK_OEM_3, // ` ~
    VK_OEM_MINUS, VK_OEM_PLUS, // - +
    VK_OEM_4, VK_OEM_6, // [ ]
    VK_OEM_5, // \ |
    VK_OEM_1, // ; :
    VK_OEM_7, // ' "
    VK_OEM_COMMA, VK_OEM_PERIOD, VK_OEM_2, // , . /

    // Numpad Keys
    VK_NUMPAD9, VK_NUMPAD8, VK_NUMPAD7, VK_NUMPAD6, VK_NUMPAD5, 
    VK_NUMPAD4, VK_NUMPAD3, VK_NUMPAD2, VK_NUMPAD1, VK_NUMPAD0,
    VK_DECIMAL, VK_DIVIDE, VK_MULTIPLY, VK_SUBTRACT, VK_ADD,

    // Multimedia and Special Keys (Lowest Priority)
    VK_VOLUME_MUTE, VK_VOLUME_DOWN, VK_VOLUME_UP,
    VK_MEDIA_NEXT_TRACK, VK_MEDIA_PREV_TRACK, VK_MEDIA_STOP, VK_MEDIA_PLAY_PAUSE
};
#endif
