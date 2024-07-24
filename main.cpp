#include "crossroad-manager.h"
#include <iostream>

auto main(int argc, char** argv) -> int {
  CrossroadManager crmgr(Stage(StageType::PEDESTRIAN,
                               default_durations[StageType::PEDESTRIAN],
                               std::string("PEDESTRIAN STAGE")),
                         Stage(StageType::VEHICLE,
                               default_durations[StageType::VEHICLE],
                               "NORTH-SOUTH VEHICULAR STAGE"),
                         Stage(StageType::VEHICLE,
                               default_durations[StageType::VEHICLE],
                               "WEST-EAST VEHICULAR STAGE"));

  std::cout << "kek" << std::endl;
  //crmgr.main_loop();
  return 0;
}

