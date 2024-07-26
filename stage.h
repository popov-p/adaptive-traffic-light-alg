#ifndef STAGE_H
#define STAGE_H


#include "traffic-light.h"
#include "utils.h"
#include "constants.h"
#include <string>
#include <memory>

/**
 * \brief Класс для представления стадии светофора.
 *
 * Класс `Stage` представляет собой стадию светофора, включая информацию о типе стадии,
 * продолжительности, описании и задействованных светофорах.
 */
class Stage {
public:
  Stage() : _stage_type(StageType::NONE),
            _duration(duration_bounds[StageType::NONE].first),
            _description("") {}

  Stage(StageType stage_type,
        Duration duration,
        std::string description,
        std::vector<std::shared_ptr<TrafficLight>> involved_traffic_lights) :
                                   _stage_type(stage_type),
                                   _duration(duration),
                                   _description(description),
                                   _involved_traffic_lights(involved_traffic_lights) {}

  Stage& operator=(const Stage& other);
  /**
   * \brief Обновляет состояние стадии.
   *
   * Метод обновляет состояние стадии.
   * Читаем данные со всех камер светофоров, задействованных в стадии,
   * получаем максимальное значение "пользователей (машин или пешеходов)",
   * обновляем длительность стадии на основании данных с камер.
   *
   */
  void update();
  StageType get_stage_type();
  Duration get_duration();
  /**
   * \brief Переключает цвета светофоров на следующий.
   *
   */
  void switch_traffic_lights_colors();
private:
  unsigned short get_number_of_users();
  StageType _stage_type;
  Duration _duration;
  std::string _description;
  std::vector<std::shared_ptr<TrafficLight>> _involved_traffic_lights;
};


#endif
