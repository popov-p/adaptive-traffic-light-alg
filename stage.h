#ifndef STAGE_H
#define STAGE_H

#include "traffic-light.h"
#include "utils.h"
#include "constants.h"
#include <string>
#include <memory>



class Stage {
public:
  Stage() : _stage_type(StageType::NONE),
            _duration(default_durations[StageType::NONE]),
            _description("") {};

  Stage(StageType stage_type,
        Duration duration,
        std::string description,
        std::vector<std::shared_ptr<TrafficLight>> involved_traffic_lights) :
                                   _stage_type(stage_type),
                                   _duration(duration),
                                   _description(description),
                                   _involved_traffic_lights(involved_traffic_lights) {};
  Stage& operator=(const Stage& other) {
    if (this != &other) {
        _stage_type = other._stage_type;
        _duration = other._duration;
        _description = other._description;
        // TODO: copy traffic lights if needed
      }
    return *this;
  }
    ;
private:
  StageType _stage_type;
  Duration _duration;
  std::string _description;
  std::vector<std::shared_ptr<TrafficLight>> _involved_traffic_lights;
};
#endif
