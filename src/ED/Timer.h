#ifndef TIMER_H
#define TIMER_H
#include <iostream>

#include <chrono>
#include <ctime>
#include <sys/types.h>
// #include <sys/_types/_int64_t.h>
// #include <sys/_types/_timespec.h>

class Timer {
private:
  std::chrono::steady_clock::time_point testTime_t1, testTime_t2;

public:
  Timer() {} // end-TimerClass

  void Start() {
    // Use hi-res timer
    testTime_t1 = std::chrono::steady_clock::now();
  } // end-Start

  void Stop() {
    // Perform operations that require timing
    testTime_t2 = std::chrono::steady_clock::now();
  } // end-Stop

  // Returns time in milliseconds
  double ElapsedTime() {
    // Calculate time difference in milliseconds
    return std::chrono::duration_cast<std::chrono::duration<double>>(
               testTime_t2 - testTime_t1)
        .count();
  } // end-Elapsed
};

#endif