#ifndef POLYGON_HPP
#define POLYGON_HPP
#include <vector>

namespace kovshikov
{
  struct Point
  {
    int x, y;
  };

  struct Polygon
  {
    std::vector< Point > points;
  };
}

std::istream& kovshikov::operator>>(std::istream& is, Point& value);

#endif
