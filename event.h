#ifndef EVENT_H
#define EVENT_H
#include "phase.h"
#include <optional>

class Event {
private:
 std::optional<unsigned short> _sender_id;
 std::optional<unsigned short> _opposite_pedestrian_count;
 std::optional<unsigned short> _opposite_vehicle_count;
 std::optional<Phase> _sender_current_phase;
};
#endif // EVENT_H
