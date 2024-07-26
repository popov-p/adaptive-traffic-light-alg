#ifndef CROSSROADMANAGER_H
#define CROSSROADMANAGER_H


#include "circular-list.h"
#include "stage.h"
#include <vector>

/**
 * \brief Класс для управления перекрестком.
 *
 * Класс 'CrossroadManager' (можно понимать как главный сервер) управляет стадиями светофора на перекрестке. Он хранит
 * список стадий и отслеживает активную стадию, управляет порядком и длительностью стадий.
 */
class CrossroadManager {
public:
  template <typename... Args>
  CrossroadManager(Args&&... args) : _stages(std::forward<Args>(args)...) {
    _active_stage = _stages.begin();
  };
  /**
   * \brief Основной цикл работы.
   *
   * Метод `main_loop` реализует основной цикл работы перекрестка.
   * Ключевая логика регулировки движения.
   */
  void main_loop();

private:
  CircularList<Stage> _stages;
  CircularList<Stage>::iterator _active_stage;
};


#endif // CROSSROADMANAGER_H
