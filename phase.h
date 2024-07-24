#ifndef PHASE_H
#define PHASE_H

#include <algorithm>

enum class ActiveColor {
  RED,
  YELLOW,
  GREEN,
  NONE
};


class Phase {
public:
  //TODO: constructions
private:
  ActiveColor _state;
  unsigned short _duration;
};

#endif // PHASE_H
