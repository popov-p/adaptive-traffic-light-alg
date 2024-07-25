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
  unsigned short max_camera_user_value = 0;
  for (const auto& tl : _involved_traffic_lights) {
      if
    total_amount_of_users += tl->get_data_from_camera();
  };
};

//void Stage::allow_movement() {
//  for (const auto& tl: _involved_traffic_lights) {
//      //tl.
//    }
//}
