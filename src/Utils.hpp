#pragma once

#include <string>
#include <ctime>
#include <unordered_map>
#include <linux/input.h> // For key codes

class Utils {
  public:
    Utils() = delete; // Prevent instantiation
    ~Utils() = delete; // Prevent instantiation

    static std::string get_timestamp() {
      time_t now = time(nullptr);
      char buf[64];
      strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
      return std::string(buf);
    }

    static std::string keycode_to_string(int code) {
      static std::unordered_map<int, std::string> keymap = {
          { KEY_A, "a" }, { KEY_B, "b" }, { KEY_C, "c" },
          { KEY_D, "d" }, { KEY_E, "e" }, { KEY_F, "f" },
          { KEY_G, "g" }, { KEY_H, "h" }, { KEY_I, "i" },
          { KEY_J, "j" }, { KEY_K, "k" }, { KEY_L, "l" },
          { KEY_M, "m" }, { KEY_N, "n" }, { KEY_O, "o" },
          { KEY_P, "p" }, { KEY_Q, "q" }, { KEY_R, "r" },
          { KEY_S, "s" }, { KEY_T, "t" }, { KEY_U, "u" },
          { KEY_V, "v" }, { KEY_W, "w" }, { KEY_X, "x" },
          { KEY_Y, "y" }, { KEY_Z, "z" },
          { KEY_0, "0" }, { KEY_1, "1" }, { KEY_2, "2" },
          { KEY_3, "3" }, { KEY_4, "4" }, { KEY_5, "5" },
          { KEY_6, "6" }, { KEY_7, "7" }, { KEY_8, "8" },
          { KEY_9, "9" }, { KEY_ENTER, "Enter" },
          { KEY_SPACE, "Space" }, { KEY_BACKSPACE, "Backspace" },
          { KEY_TAB, "Tab" }, { KEY_ESC, "Escape" },
          { KEY_LEFT, "Left" }, { KEY_RIGHT, "Right" },
          { KEY_UP, "Up" }, { KEY_DOWN, "Down" },
          { KEY_CAPSLOCK, "CapsLock" },
          { KEY_F1, "F1" }, { KEY_F2, "F2" }, { KEY_F3, "F3" },
          { KEY_F4, "F4" }, { KEY_F5, "F5" }, { KEY_F6, "F6" },
          { KEY_F7, "F7" }, { KEY_F8, "F8" }, { KEY_F9, "F9" },
          { KEY_F10, "F10" }, { KEY_F11, "F11" }, { KEY_F12, "F12" }
      };
      return keymap.contains(code) ? keymap[code] : "[?]";
    }
};
