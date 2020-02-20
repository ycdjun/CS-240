#include "point.hh"
#include "line.hh"

#include <iostream>

//declare an array of points
static const Point points[] = {
  Point(0, 0), Point(3, 4), Point(1, 1), Point(4, 5),
};
//use standard idiom to figure out number of elements in array
static constexpr auto nPoints = sizeof(points)/sizeof(points[0]);

/*
static void
outSizes(std::ostream& out) {
  out << "sizeof(double) = " << sizeof(double) << std::endl;
  out << "sizeof(Point) = " << sizeof(Point) << std::endl;
}
*/

/** output pair-wise distance between all points in points[] to out. */

/*
static void
outDistances(std::ostream& out)
{
  for (auto i = 0u; i < nPoints - 1; i++) {
    Point pi = points[i];
    for (auto j = i + 1; j < nPoints; j++) {
      Point pj = points[j];
      out << "distance from " << pi.toString()
	  << " to " << pj.toString()
	  << " is " << pi.distance(pj)
	  << std::endl;
    }
  }
}
*/


static void
outLength(std::ostream& out)
{
  for(auto i = 0u; i < nPoints-1; i+=2){
    Line l1 = Line(points[i], points[i+1]);
    std::cout << l1.toString() << " length " << l1.length() << std::endl;
  }
}



int main() {

  //instead of hardcoding std::cout in functions, we pass it as a param.
  //so if we wanted to output to a file, the code for the functions
  //would not need to change (the code in this function would change).
  std::ostream& out = std::cout;

  outLength(out); out << std::endl;

}
