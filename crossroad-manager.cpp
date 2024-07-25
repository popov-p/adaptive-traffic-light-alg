#include "crossroad-manager.h"
#include <thread>

void CrossroadManager::main_loop() {
  int counter = 0;
  while(true) {
    if (_stages.next(_active_stage)->get_stage_type() == StageType::VEHICLE) {
        _stages.next(_active_stage)->update();
        _stages.next(_active_stage)->switch_traffic_lights_colors(); /*activate yellow*/
        std::this_thread::sleep_for(YELLOW_LIGHT_DURATION);
        _active_stage->switch_traffic_lights_colors(); /*start previous stageloop from the beginning*/
        _active_stage = _stages.next(_active_stage);
        _active_stage->switch_traffic_lights_colors(); /*activate green*/
        std::cout << "SLEEPING FOR: " << _active_stage->get_duration().count() - YELLOW_LIGHT_DURATION.count() << std::endl;
        std::this_thread::sleep_for(_active_stage->get_duration() - YELLOW_LIGHT_DURATION);
    }
    else if (_stages.next(_active_stage)->get_stage_type() == StageType::PEDESTRIAN) {
      _stages.next(_active_stage)->update();
      _stages.next(_active_stage)->switch_traffic_lights_colors(); /*activate green*/
      _active_stage->switch_traffic_lights_colors(); /*start previous stage loop from the beginning*/
      _active_stage = _stages.next(_active_stage);
      std::cout << "SLEEPING FOR: " << _active_stage->get_duration().count() - YELLOW_LIGHT_DURATION.count() << std::endl;
      std::this_thread::sleep_for(_active_stage->get_duration() - YELLOW_LIGHT_DURATION);
    }
    counter++;
    if(counter == 3) {
      std::cout << "GENERAL CYCLE DONE" << std::endl;
      break;
    }
  }
};

