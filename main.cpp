#include "crossroad-manager.h"
#include "utils.h"
#include <iostream>

auto main(int argc, char** argv) -> int {
  CrossroadManager crmgr(Stage(StageType::PEDESTRIAN,
                               default_durations[StageType::PEDESTRIAN],
                               "PEDESTRIAN STAGE",
                               std::move(initialize_traffic_lights<PedestrianTrafficLight, 5, 8>())),
                         Stage(StageType::VEHICLE,
                               default_durations[StageType::VEHICLE],
                               "NORTH-SOUTH VEHICULAR STAGE",
                               std::move(initialize_traffic_lights<VehicleTrafficLight, 2, 2>())),

                         Stage(StageType::VEHICLE,
                               default_durations[StageType::VEHICLE],
                               "WEST-EAST VEHICULAR STAGE",
                               std::move(initialize_traffic_lights<VehicleTrafficLight, 1, 2>())));

  std::cout << "kek" << std::endl;
  //crmgr.main_loop();
  return 0;
}




