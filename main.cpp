#include "Stag.h"
#include "opencv2/opencv.hpp"

#include <iostream>
#include <opencv2/highgui.hpp>

int main() {
  cv::Mat image = cv::imread("../00003.png", CV_LOAD_IMAGE_GRAYSCALE);
  cv::imshow("img", image);
  Stag stag(15, 7, true);
  int marker_Cnt = stag.detectMarkers(image);
  // stag.logResults("");
  cv::waitKey(0);
  return 0;
}