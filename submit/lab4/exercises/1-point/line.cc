#include "point.hh"
#include "line.hh"

#include <cmath>
#include <string>
#include <sstream>

/** return distance of this point from other point */
double Line::length() const {
  return (x.distance(y));
}

std::string Line::toString() const {
  //declaring s to be a stringstream allows usage similar to std::cout
  std::stringstream s;
  s << x.toString() << " -- " << y.toString(); //normal (x, y) format
  return s.str(); //return std::string underlying stringstream
}
