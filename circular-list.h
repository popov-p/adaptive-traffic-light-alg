#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H


#include <list>


template <typename T>
class CircularList {
public:
  template <typename... Args>
  CircularList(Args&&... args) {
    (elements.push_back(std::forward<Args>(args)), ...);
  }

  using iterator = typename std::list<T>::iterator;
  using const_iterator = typename std::list<T>::const_iterator;

  void add(const T& value) {
    elements.push_back(value);
  }

  void remove(const_iterator it) {
    elements.erase(it);
  }

  iterator begin() {
    return elements.begin();
  }

  const_iterator begin() const {
    return elements.begin();
  }

  iterator end() {
    return elements.end();
  }

  const_iterator end() const {
    return elements.end();
  }

  iterator next(iterator it) {
    return ++it == elements.end() ? elements.begin() : it;
  }

  const_iterator next(const_iterator it) const {
    return ++it == elements.end() ? elements.begin() : it;
  }

  iterator prev(iterator it) {
    return it == elements.begin() ? --elements.end() : --it;
  }

  const_iterator prev(const_iterator it) const {
    return it == elements.begin() ? --elements.end() : --it;
  }

private:
  std::list<T> elements;
};


#endif
