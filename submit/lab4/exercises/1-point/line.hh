#ifndef LINE_HH_
#define LINE_HH_

#include "point.hh"

#include <string>

struct Line {
  //for the purpose of this lab, these fields are public but const.
  //Having them public makes it hard to change the reprentation
  //from these cartesian coordinates to polar coordinates.
  const Point x, y;

  /** constructor */
  Line(Point x = Point(),Point y = Point()) : x(x), y(y) { }

  /** return distance of this point from other point */
  //the trailing const means that this function will not change
  //this point
  double length() const;

  /** return a string representation of this point */
  std::string toString() const;
};



#endif //ifndef POINT_HH_
