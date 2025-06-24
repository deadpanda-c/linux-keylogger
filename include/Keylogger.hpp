#pragma once

#include <linux/input.h>
#include <string>
#include <fcntl.h>
#include <unistd.h>

class Keylogger {
  public:
    Keylogger(const std::string &devicePath);

    ~Keylogger();

    void start();
  private:
    int fd = -1; // File descriptor for the input device
    std::string devicePath; // Path to the input device
};
