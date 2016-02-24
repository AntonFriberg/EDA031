#include "date.h"
#include <string>

template<typename T>
string toString(T s)
{
    return "";
}

int main() {
  double d = 1.234;
  Date today;
  std::string sd = toString(d);
  std::string st = toString(today);
}
