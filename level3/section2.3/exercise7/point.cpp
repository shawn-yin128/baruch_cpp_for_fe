// implement the point class

#include <iostream>
#include <sstream>
#include <string>
#include "point.hpp"

using namespace std;

// constructor
Point::Point() {
}

Point::Point(const Point &p) {
  m_x = p.m_x;
  m_y = p.m_y;
}

Point::Point(double x, double y) {
  m_x = x;
  m_y = y;
}

// destructor
Point::~Point() {
}

// to string
string Point::ToString() const {
  stringstream stream;
  stream << "Point(" << m_x << ", " << m_y << ")";
  return stream.str();
}

// distance functions
// distance with origin
double Point::Distance() const {
  return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

// distance with other point
double Point::Distance(const Point& p) const {
  double x_dif, y_dif;
  x_dif = m_x - p.m_x;
  y_dif = m_y - p.m_y;
  return sqrt(pow(x_dif, 2) + pow(y_dif, 2));
}
