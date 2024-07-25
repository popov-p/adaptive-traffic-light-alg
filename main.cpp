#include "crossroad-manager.h"
#include "utils.h"
#include <iostream>
#include <thread>

auto main(int argc, char** argv) -> int {
//  CrossroadManager crmgr(Stage(StageType::PEDESTRIAN,
//                               default_durations[StageType::PEDESTRIAN],
//                               "PEDESTRIAN STAGE",
//                               initialize_traffic_lights<PedestrianTrafficLight, 5, 8>()),
//                         Stage(StageType::VEHICLE,
//                               default_durations[StageType::VEHICLE],
//                               "NORTH-SOUTH VEHICULAR STAGE",
//                               initialize_traffic_lights<VehicleTrafficLight, 2, 2>()),

//                         Stage(StageType::VEHICLE,
//                               default_durations[StageType::VEHICLE],
//                               "WEST-EAST VEHICULAR STAGE",
//                               initialize_traffic_lights<VehicleTrafficLight, 1, 2>()));

  std::cout << "WTF" << std::endl;
  boost::asio::io_context io_context;
  auto tl = TrafficLight(1, io_context, Color::RED,
                             Color::YELLOW,
                             Color::GREEN);
  auto tls = TrafficLight(2, io_context, Color::RED,
                             Color::YELLOW,
                             Color::GREEN);
  auto tlt = TrafficLight(3, io_context, Color::RED,
                             Color::YELLOW,
                             Color::GREEN);
  auto tlf = TrafficLight(4, io_context, Color::RED,
                             Color::YELLOW,
                             Color::GREEN);
  std::thread io_thread([&io_context]() {
          io_context.run();
      });

  std::this_thread::sleep_for(std::chrono::seconds(300));
  io_context.stop();
  io_thread.join();
  std::cout << "kek2" << std::endl;
  return 0;
}




