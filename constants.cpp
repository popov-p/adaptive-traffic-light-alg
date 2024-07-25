#include "constants.h"

std::map<StageType, Duration> default_durations = {
    { StageType::PEDESTRIAN, Duration(20) },
    { StageType::VEHICLE, Duration(40) },
    { StageType::NONE, Duration(1) }
};
