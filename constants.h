#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <chrono>
#include <map>
#include <string>
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

std::string color_to_string(Color color);

using Duration = std::chrono::seconds;
extern const unsigned short conversion_factor;
extern std::map<StageType, std::pair<Duration, Duration>> duration_bounds;
extern std::map<StageType, std::pair<unsigned short, unsigned short>> amount_thresholds;
extern const Duration YELLOW_LIGHT_DURATION;
#endif // CONSTANTS_H
