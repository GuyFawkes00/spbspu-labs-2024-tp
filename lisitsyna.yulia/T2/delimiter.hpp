#ifndef DELIMETER_HPP
#define DELIMETER_HPP
#include <istream>
#include <string>

namespace lisitsyna
{
  struct Separator
  {
    char exp;
  };
  std::istream & operator>>(std::istream & in, Separator && dest);
  struct Label
  {
    std::string exp;
  };
  std::istream& operator>>(std::istream& in, Label && dest);
}
#endif
