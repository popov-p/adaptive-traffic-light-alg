#ifndef CROSSROADMANAGER_H
#define CROSSROADMANAGER_H


#include "circular-list.h"
#include "stage.h"
#include <vector>


class CrossroadManager {
public:
  template <typename... Args>
  CrossroadManager(Args&&... args) : _stages(std::forward<Args>(args)...) {
    _active_stage = _stages.begin();
  };

  void main_loop();

private:
  CircularList<Stage> _stages;
  CircularList<Stage>::iterator _active_stage;
};


#endif // CROSSROADMANAGER_H
