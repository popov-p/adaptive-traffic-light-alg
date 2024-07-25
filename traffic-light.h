#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "event.h"
#include "constants.h"
#include "circular-list.h"
#include <queue>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <ctime>
#include <iostream>

class TrafficLight {
public:
  template <typename... Args>
  TrafficLight(unsigned short id, boost::asio::io_context& io_context, Args&&... args)
    : _id(id),
      _io_context(io_context),
      _timer(io_context),
      _traffic_light_colors(std::forward<Args>(args)...),
      _active_color(_traffic_light_colors.begin()) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::cout << "C-TOR CALL" << std::endl;
    start_timer();
  };
  virtual unsigned short get_data_from_camera() const = 0;
  virtual ~TrafficLight() = default;
protected:
  const unsigned short _id;
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
  void process_events() {
    std::cout << "SUCCESSFULLY HANDLED FROM ID: (DEBUG) " << typeid(*this).name() << _id << std::endl;
    while (!_event_queue.empty()) {
      Event event = _event_queue.front();
      _event_queue.pop();
      handle_event(event);
    }
  };

  void handle_event(const Event& event) {
    std::cout << "SUCCESSFULLY HANDLED EVENT FROM TRAFFIC LIGHT" << _id << std::endl;
  };
  std::queue<Event> _event_queue;
  CircularList<Color> _traffic_light_colors;
  CircularList<Color>::iterator _active_color;
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
  unsigned short get_data_from_camera() const override {
    auto min_value = amount_thresholds[StageType::PEDESTRIAN].first;
    auto max_value = amount_thresholds[StageType::PEDESTRIAN].second;
    auto result = min_value + std::rand() % (max_value - min_value + 1);
    std::cout << "PEDESTRIAN TRAFFIC LIGHT: " << _id << ", CAMERA VALUE: " << result << std::endl;
    return result;
  };
};

class VehicleTrafficLight: public TrafficLight {
public:
  template <typename... Args>
  VehicleTrafficLight(unsigned short id,
                      boost::asio::io_context& io_context,
                      Args&&... args) : TrafficLight(id,
                                                     io_context,
                                                     std::forward<Args>(args)...) {};
  unsigned short get_data_from_camera() const override {
    auto min_value = amount_thresholds[StageType::VEHICLE].first;
    auto max_value = amount_thresholds[StageType::VEHICLE].second;
    auto result = min_value + std::rand() % (max_value - min_value + 1);
    std::cout << "VEHICULAR TRAFFIC LIGHT: " << _id << ", CAMERA VALUE: " << result << std::endl;
    return result;
  };
};

#endif //TRAFFICLIGHT_H
