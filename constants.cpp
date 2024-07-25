#include "constants.h"

std::map<StageType, std::pair<unsigned short, unsigned short>> amount_thresholds {
  { StageType::PEDESTRIAN, {10, 20} },
  { StageType::VEHICLE, {30, 60} },
  { StageType::NONE, {1, 1} }
};

const unsigned short conversion_factor = 1;

std::map<StageType, std::pair<Duration, Duration>> duration_bounds = {
    { StageType::PEDESTRIAN, {Duration(conversion_factor*amount_thresholds[StageType::PEDESTRIAN].first),
                              Duration(conversion_factor*amount_thresholds[StageType::PEDESTRIAN].second)} },
    { StageType::VEHICLE, {Duration(conversion_factor*amount_thresholds[StageType::VEHICLE].first),
                           Duration(conversion_factor*amount_thresholds[StageType::VEHICLE].second)} },
    { StageType::NONE, {Duration(conversion_factor*amount_thresholds[StageType::NONE].first),
                        Duration(conversion_factor*amount_thresholds[StageType::NONE].second)} }
};

std::string color_to_string(Color color) {
  switch (color) {
    case Color::RED:    return "RED";
    case Color::YELLOW: return "YELLOW";
    case Color::GREEN:  return "GREEN";
    case Color::NONE:   return "NONE";
    default:            return "UNKNOWN";
  }
};


const Duration YELLOW_LIGHT_DURATION = Duration(3);
