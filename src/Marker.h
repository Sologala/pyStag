#ifndef MARKER_H
#define MARKER_H

#include "Quad.h"
#include <string>

class Marker : public Quad {
public:
  int id;
  cv::Mat C;

  Marker(const Quad &q, int inId);
  Marker(const Marker &m);
  std::string show() { return "id: " + std::to_string(this->id); }
  void shiftCorners2(int shift);
};

#endif