#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "event.h"
#include <queue>

class TrafficLight {
public:
  TrafficLight(unsigned short id): _id(id) {};
  //TODO: Timer with sending an Event to an another ID
  virtual ~TrafficLight() = default;
private:
  const unsigned short _id;
  std::queue<Event> _event_queue;
};

class PedestrianTrafficLight: public TrafficLight {

};

class VehicleTrafficLight: public TrafficLight {

};
#endif //TRAFFICLIGHT_H
