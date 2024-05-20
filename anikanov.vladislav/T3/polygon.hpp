#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include <iosfwd>
#include "point.hpp"

namespace anikanov {
  struct Polygon {
    std::vector< Point > points;
    Polygon() = default;
    Polygon(const std::vector< Point > &points) : points(points)
    {
    }
    ~Polygon() = default;
    Polygon &operator=(const Polygon &polygon);
    size_t operator%(const size_t number) const;
    Point &operator[](size_t index);
    const Point &operator[](size_t index) const;
    double getArea() const;
    double areaHelper(const Point &point1, const Point &point2) const;
    size_t getSize() const;
  };

  std::istream &operator>>(std::istream &in, Polygon &dest);
}

#endif
