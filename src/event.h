#ifndef EVENT_H
#define EVENT_H


#include "traffic-light.h"
#include "constants.h"


/**
 * \brief Класс для представления события.
 *
 * Класс 'Event' используется для представления события.
 * Содержит информацию, которую должен обработать светофор в свой очереди событий.
 *
 */
class Event {
public:
  Event(unsigned short sender_id,
        bool turn_next_color = false) : _sender_id(sender_id),
                                                               _turn_next_color(turn_next_color) {}
  bool provide_next_color() const {
    return _turn_next_color;
  }
private:
  unsigned short _sender_id;
  bool _turn_next_color = false;
};


#endif // EVENT_H
