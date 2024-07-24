#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "event.h"
#include "circular-list.h"
#include <queue>

class TrafficLight {
public:
  template <typename... Args>
  TrafficLight(unsigned short id, Args&&... args)
    : _id(id),
      _traffic_light_colors(std::forward<Args>(args)...),
      _active_color(*_traffic_light_colors.begin()) {};
  //TODO: Timer with sending an Event to an another ID
  virtual ~TrafficLight() = default;
  Color get_active_color();
protected:
  const unsigned short _id;
  std::queue<Event> _event_queue;
  CircularList<Color> _traffic_light_colors;
  Color _active_color;
};

class PedestrianTrafficLight: public TrafficLight {
public:
  template <typename... Args>
  PedestrianTrafficLight(unsigned short id, Args&&... args) : TrafficLight(id, std::forward<Args>(args)...) {};
};

class VehicleTrafficLight: public TrafficLight {
public:
  template <typename... Args>
  VehicleTrafficLight(unsigned short id, Args&&... args) : TrafficLight(id, std::forward<Args>(args)...) {};
};
#endif //TRAFFICLIGHT_H
