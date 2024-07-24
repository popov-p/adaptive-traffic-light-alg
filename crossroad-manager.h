#ifndef CROSSROADMANAGER_H
#define CROSSROADMANAGER_H

#include "circular-list.h"
#include "stage.h"
#include <vector>

class CrossroadManager {
  CrossroadManager() = default;
  void change_stage();
  CircularList<Stage> _stages;
};

#endif // CROSSROADMANAGER_H
