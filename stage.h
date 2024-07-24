#ifndef STAGE_H
#define STAGE_H

#include <string>
#include <chrono>
#include <map>

enum class StageType {
  PEDESTRIAN,
  VEHICLE,
  NONE
};

using Duration = std::chrono::seconds;
extern std::map<StageType, Duration> default_durations;

class Stage {
public:
  Stage() : _stage_type(StageType::NONE), _duration(default_durations[StageType::NONE]), _description("") {}
  Stage(StageType stage_type,
        Duration duration,
        std::string description) : _stage_type(stage_type),
                                   _duration(duration),
                                   _description(description) {};
    ;
private:
  StageType _stage_type;
  Duration _duration;
  std::string _description;
  //TODO: traffic lights used;
};
#endif
