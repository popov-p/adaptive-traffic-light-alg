#include "crossroad-manager.h"
#include <thread>


void CrossroadManager::main_loop() {
  unsigned short debug_demo_counter = 0;
  while(true) {/*Начинаем с пешеходной стадии, зелёный цвет сигнала активен*/
    if (_stages.next(_active_stage)->get_stage_type() == StageType::VEHICLE) {
        _stages.next(_active_stage)->update(); /*Обновляем длительность следующей стадии*/
        _stages.next(_active_stage)->switch_traffic_lights_colors(); /*Активируем желтый сигнал следующей стадии*/
        std::this_thread::sleep_for(YELLOW_LIGHT_DURATION);
        _active_stage->switch_traffic_lights_colors(); /*Начинаем текущий цикл сначала (включаем красный)*/
        _active_stage = _stages.next(_active_stage); /*Переключаем активную стадию на следующую*/
        _active_stage->switch_traffic_lights_colors(); /*Включаем зеленый сигнал*/
        std::cout << "SLEEPING FOR: " << _active_stage->get_duration().count() - YELLOW_LIGHT_DURATION.count() << std::endl;
        std::this_thread::sleep_for(_active_stage->get_duration() - YELLOW_LIGHT_DURATION);
    }
    else if (_stages.next(_active_stage)->get_stage_type() == StageType::PEDESTRIAN) {
      _stages.next(_active_stage)->update(); /*Обновляем длительность следующей стадии*/
      _stages.next(_active_stage)->switch_traffic_lights_colors(); /*Включаем зелёный, потому что жёлтого сигнала нет*/
      _active_stage->switch_traffic_lights_colors(); /*Начинаем текущий цикл сначала (включаем красный)*/
      _active_stage = _stages.next(_active_stage); /*Переключаем активную стадию на следующую*/
      std::cout << "SLEEPING FOR: " << _active_stage->get_duration().count() - YELLOW_LIGHT_DURATION.count() << std::endl;
      std::this_thread::sleep_for(_active_stage->get_duration() - YELLOW_LIGHT_DURATION);
    }
    debug_demo_counter++; /*Эту логику можно закомментировать.
                            Оставил специально, чтобы программа завершала main_loop после обработки одного цикла.
                            Нужно просто для демонстрации работы.
                           */
    if(debug_demo_counter == 3) {
      std::cout << "GENERAL CYCLE DONE" << std::endl;
      break;
    }
  }
};

