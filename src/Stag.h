#ifndef STAG_H
#define STAG_H

#include "Decoder.h"
#include "Drawer.h"
#include "EDInterface.h"
#include "Marker.h"
#include "PoseRefiner.h"
#include "QuadDetector.h"
#include <vector>

class Stag {
  // if keepLogs is true, keep the intermediate results of the detection
  // algorithm in the memory, to be dumped when asked (default: false)
public:
  vector<Marker> markers;
  vector<Quad> falseCandidates;

private:
  bool keepLogs = false;
  int errorCorrection;
  EDInterface edInterface;
  QuadDetector quadDetector;
  Drawer drawer;
  Decoder decoder;
  PoseRefiner poseRefiner;

  vector<cv::Mat> codeLocs;
  vector<cv::Mat> blackLocs;
  vector<cv::Mat> whiteLocs;
  cv::Mat image;
  // take readings from 48 code locations, 12 black border locations, and 12
  // white border locations thresholds and converts to binary code
public:
  Codeword decodeFromImage(const Quad &q);

  void fillCodeLocations();
  cv::Mat createMatFromPolarCoords(double radius, double radians,
                                   double circleRadius);

  Stag(int libraryHD = 15, int errorCorrection = 7, bool inKeepLogs = false);
  int detectMarkers(cv::Mat inImage);
  std::vector<std::vector<std::vector<double>>> getContours();
  std::vector<int> getIds();

  void logResults(string path = "");
};

#endif