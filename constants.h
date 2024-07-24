#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <chrono>
#include <map>

enum class StageType {
  PEDESTRIAN,
  VEHICLE,
  NONE
};

enum class Color {
  RED,
  YELLOW,
  GREEN,
  NONE
};



using Duration = std::chrono::seconds;
extern std::map<StageType, Duration> default_durations;

#endif // CONSTANTS_H
