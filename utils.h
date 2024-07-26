#ifndef UTILS_H
#define UTILS_H


#include "traffic-light.h"
#include <type_traits>
#include <memory>
#include <vector>


template <typename TrafficLightType, std::size_t StartFromIdx, std::size_t... Is>
std::vector<std::shared_ptr<TrafficLight>> initialize_traffic_lights_impl(boost::asio::io_context& io_context,
                                                                          std::index_sequence<Is...>) {
  static_assert(std::is_base_of<TrafficLight, TrafficLightType>::value,
                "TrafficLightType must be derived from TrafficLight");

  std::vector<std::shared_ptr<TrafficLight>> result;
  if constexpr (std::is_same<TrafficLightType, PedestrianTrafficLight>::value) {
    (result.push_back(std::make_shared<TrafficLightType>(StartFromIdx + Is,
                                                         io_context,
                                                         Color::GREEN,
                                                         Color::RED)), ...);
  } else if constexpr (std::is_same<TrafficLightType, VehicleTrafficLight>::value) {
    (result.push_back(std::make_shared<TrafficLightType>(StartFromIdx + 2 * Is,
                                                         io_context,
                                                         Color::RED,
                                                         Color::YELLOW,
                                                         Color::GREEN)), ...);
  }
  return result;
}

template <typename TrafficLightType, std::size_t StartFromIdx, std::size_t N>
std::vector<std::shared_ptr<TrafficLight>> initialize_traffic_lights(boost::asio::io_context& io_context) {
    return initialize_traffic_lights_impl<TrafficLightType, StartFromIdx>(io_context, std::make_index_sequence<N>{});
}

#endif // UTILS_H
