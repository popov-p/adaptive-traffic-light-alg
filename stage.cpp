 #include "stage.h"

std::map<StageType, Duration> default_durations = {
    { StageType::PEDESTRIAN, Duration(30) },
    { StageType::VEHICLE, Duration(60) },
    { StageType::NONE, Duration(1) }
};
