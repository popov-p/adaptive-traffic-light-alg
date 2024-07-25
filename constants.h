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
extern const unsigned short conversion_factor;
extern std::map<StageType, std::pair<Duration, Duration>> duration_bounds;
extern std::map<StageType, std::pair<unsigned short, unsigned short>> amount_thresholds;
#endif // CONSTANTS_H
