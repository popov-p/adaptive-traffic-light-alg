 #include "stage.h"

Stage& Stage::operator=(const Stage& other) {
  if (this != &other) {
    _stage_type = other._stage_type;
    _duration = other._duration;
    _description = other._description;
    _involved_traffic_lights = other._involved_traffic_lights;
  }
  return *this;
};


void Stage::update() {
  auto upper_available_bound = amount_thresholds[_stage_type].first;
  auto lower_available_bound = amount_thresholds[_stage_type].second;
  auto maximum = lower_available_bound;
  for (const auto& tl : _involved_traffic_lights) { /*search max*/
    auto current_value = tl->get_data_from_camera();
    if (current_value > maximum) {
      maximum = current_value;
    }
  }
  _duration = Duration(conversion_factor*maximum);
};

//void Stage::allow_movement() {
//  for (const auto& tl: _involved_traffic_lights) {
//      //tl.
//    }
//}
