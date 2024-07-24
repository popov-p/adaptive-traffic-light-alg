#ifndef EVENT_H
#define EVENT_H


#include "traffic-light.h"
#include "constants.h"
#include <optional>

class Event {
private:
  std::optional<unsigned short> _sender_id;
  std::optional<unsigned short> _opposite_pedestrian_count;
  std::optional<unsigned short> _opposite_vehicle_count;
  std::optional<Color> _sender_current_color;
};
#endif // EVENT_H
