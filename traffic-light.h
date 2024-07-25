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
      _active_color(_traffic_light_colors.begin())
  {
     std::srand(static_cast<unsigned>(std::time(nullptr)));
     start_timer();
  };
  void add_event(const Event& event);
  virtual unsigned short get_data_from_camera() const = 0;
  virtual ~TrafficLight() = default;
protected:
  const unsigned short _id;
  CircularList<Color> _traffic_light_colors;
  CircularList<Color>::iterator _active_color;
private:
  void start_timer() {
    _timer.expires_after(std::chrono::milliseconds(100));
    _timer.async_wait([this](const boost::system::error_code& error) {
        if (!error) {
            process_events();
            start_timer();
          }
      });
  };
  virtual void handle_event(const Event& event) = 0;
  void process_events() {
    while (!_event_queue.empty()) {
      Event event = _event_queue.front();
      _event_queue.pop();
      handle_event(event);
    }
  };

  std::queue<Event> _event_queue;

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
    std::cout << "PEDESTRIAN TRAFFIC LIGHT: " << _id << ", CAMERA VALUE: " << result << " (SYNC)" << std::endl;
    return result;
  };

  void handle_event(const Event& event) override {
    if (event.provide_next_color()) {
      _active_color = _traffic_light_colors.next(_active_color);
      std::cout << "PEDESTRIAN TRAFFIC LIGHT: " << _id << " SWITCHED LIGHT COLOR TO " << color_to_string(*_active_color) << " (ASYNC)" << std::endl;
    }
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
    std::cout << "VEHICULAR TRAFFIC LIGHT: " << _id << ", CAMERA VALUE: " << result << " (SYNC)" << std::endl;
    return result;
  };
  void handle_event(const Event& event) override {
    if (event.provide_next_color()) {
      _active_color = _traffic_light_colors.next(_active_color);
      std::cout << "VEHICULAR TRAFFIC LIGHT: " << _id << " SWITCHED LIGHT COLOR TO " << color_to_string(*_active_color) << " (ASYNC)" << std::endl;
    }
  };
};

#endif //TRAFFICLIGHT_H
