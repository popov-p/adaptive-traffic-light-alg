#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "event.h"
#include "circular-list.h"
#include <queue>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>

class TrafficLight {
public:
  template <typename... Args>
  TrafficLight(unsigned short id, boost::asio::io_context& io_context, Args&&... args)
    : _id(id),
      _io_context(io_context),
      _timer(io_context),
      _traffic_light_colors(std::forward<Args>(args)...),
      _active_color(*_traffic_light_colors.begin()) {
    std::cout << "C-TOR CALL" << std::endl;
    start_timer();
  };
  Color get_active_color();
  virtual ~TrafficLight() = default;

private:
  void start_timer() {
    std::cout << "STARTING TIMER" << std::endl;
    _timer.expires_after(Duration(2));
    _timer.async_wait([this](const boost::system::error_code& error) {
        std::cout << "WAITING" << std::endl;
        if (!error) {
            process_events();
            start_timer();
          }
      });
  };
  void test(){std::cout << "SUCCESSFULLY HANDLED FROM ID: " << _id << std::endl;};
  void process_events() {
    test();
    while (!_event_queue.empty()) {
      Event event = _event_queue.front();
      _event_queue.pop();
      handle_event(event);
    }
  };

  void handle_event(const Event& event) {
    std::cout << "SUCCESSFULLY HANDLED EVENT FROM TRAFFIC LIGHT" << _id << std::endl;
  };
  const unsigned short _id;
  std::queue<Event> _event_queue;
  CircularList<Color> _traffic_light_colors;
  Color _active_color;
  boost::asio::io_context& _io_context;
  boost::asio::steady_timer _timer;
};

class PedestrianTrafficLight: public TrafficLight {
public:
  template <typename... Args>
  PedestrianTrafficLight(unsigned short id,
                         boost::asio::io_context& io_context,
                         Args&&... args) : TrafficLight(id,
                                                        io_context,
                                                        std::forward<Args>(args)...) {};
};

class VehicleTrafficLight: public TrafficLight {
public:
  template <typename... Args>
  VehicleTrafficLight(unsigned short id,
                      boost::asio::io_context& io_context,
                      Args&&... args) : TrafficLight(id,
                                                     io_context,
                                                     std::forward<Args>(args)...) {};
};

#endif //TRAFFICLIGHT_H
