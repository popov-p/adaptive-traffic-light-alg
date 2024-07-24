#ifndef STAGE_H
#define STAGE_H

enum class StageType {
  PEDESTRIAN,
  VEHICULAR,
  NONE
};

class Stage {
private:
  StageType _stage_type;
  unsigned short _duration;
};
#endif
