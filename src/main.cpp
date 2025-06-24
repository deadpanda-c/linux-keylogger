#include <iostream>
#include "Keylogger.hpp"

int main(int ac, char **av)
{
  if (ac != 2) {
    std::cerr << "Usage: " << av[0] << " <device_path>" << std::endl;
    return 1;
  }
  std::string device_path = av[1];
  Keylogger keylogger(device_path);

  keylogger.start();
  return 0;
}
