#include "crossroad-manager.h"
#include "utils.h"
#include <iostream>
#include <thread>

auto main(int argc, char** argv) -> int {
  std::cout << "KEK" << std::endl;
  boost::asio::io_context io_context;
  CrossroadManager crmgr(Stage(StageType::PEDESTRIAN,
                               duration_bounds[StageType::PEDESTRIAN].first,
                               "PEDESTRIAN STAGE",
                               initialize_traffic_lights<PedestrianTrafficLight, 5, 8>(io_context)),
                         Stage(StageType::VEHICLE,
                               duration_bounds[StageType::VEHICLE].first,
                               "NORTH-SOUTH VEHICULAR STAGE",
                               initialize_traffic_lights<VehicleTrafficLight, 2, 2>(io_context)),
                         Stage(StageType::VEHICLE,
                               duration_bounds[StageType::VEHICLE].first,
                               "WEST-EAST VEHICULAR STAGE",
                               initialize_traffic_lights<VehicleTrafficLight, 1, 2>(io_context)));

  std::thread io_thread([&io_context]() {
          io_context.run();
      });
  std::this_thread::sleep_for(std::chrono::seconds(300));
  io_context.stop();
  io_thread.join();
  std::cout << "LOL" << std::endl;
  return 0;
}




