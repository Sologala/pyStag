#include "Marker.h"
#include "Quad.h"
#include "Stag.h"
#include "opencv2numpy/converter.h"
#include <pybind11/cast.h>
#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sys/types.h>
namespace py = pybind11;
using namespace py::literals;

// this is a simple warpping of the Stag detector.
// you can add your customized function or varialbes interface as fllow.
void declearType_Stag_Detector(py::module &m) {
  py::class_<Stag>(m, "Detector")
      .def(py::init<>())
      .def(py::init<int, int, bool>(), "libraryHD"_a, "errorCorrection"_a,
           "inKeepLogs"_a)
      .def("detect", &Stag::detectMarkers, "inImage"_a)
      .def("log2File", &Stag::logResults, "path"_a)
      .def("getContours", &Stag::getContours)
      .def("getIds", &Stag::getIds);
}

PYBIND11_MODULE(pyStag, m) {
  // this is crucial for convertation between numpy::ndarray and cv::Mat
  NDArrayConverter::init_numpy();
  declearType_Stag_Detector(m);
}