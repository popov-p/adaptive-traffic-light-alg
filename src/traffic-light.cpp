#include "traffic-light.h"

void TrafficLight::add_event(const Event& event) {
  _event_queue.push(event);
}
