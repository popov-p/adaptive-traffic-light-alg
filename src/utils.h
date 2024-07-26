#ifndef UTILS_H
#define UTILS_H


#include "traffic-light.h"
#include <type_traits>
#include <memory>
#include <vector>


/**
 * \brief Реализует инициализацию вектора умных указателей на светофоры.
 *
 * Функция `initialize_traffic_lights_impl` создает и инициализирует вектор умных указателей на объекты
 * типа `TrafficLightType`. Используется для создания списка светофоров с заданными параметрами.
 *
 * \tparam TrafficLightType Тип светофора, который должен быть производным от `TrafficLight`.
 * \tparam StartFromIdx Начальный индекс для идентификаторов светофоров.
 * \tparam Is Индексы для создания светофоров.
 *
 * \param io_context Контекст ввода-вывода Boost.Asio для управления асинхронными операциями.
 * \param seq Последовательность индексов для создания светофоров.
 *
 * \return Вектор умных указателей на созданные объекты светофоров.
 *
 * \throws static_assert В случае, если `TrafficLightType` не является производным от `TrafficLight`.
 */
template <typename TrafficLightType, std::size_t StartFromIdx, std::size_t... Is>
std::vector<std::shared_ptr<TrafficLight>> initialize_traffic_lights_impl(boost::asio::io_context& io_context,
                                                                          std::index_sequence<Is...>) {
  static_assert(std::is_base_of<TrafficLight, TrafficLightType>::value,
                "TrafficLightType must be derived from TrafficLight");

  std::vector<std::shared_ptr<TrafficLight>> result;
  if constexpr (std::is_same<TrafficLightType, PedestrianTrafficLight>::value) {
    (result.push_back(std::make_shared<TrafficLightType>(StartFromIdx + Is,
                                                         io_context,
                                                         Color::GREEN,
                                                         Color::RED)), ...);
  } else if constexpr (std::is_same<TrafficLightType, VehicleTrafficLight>::value) {
    (result.push_back(std::make_shared<TrafficLightType>(StartFromIdx + 2 * Is,
                                                         io_context,
                                                         Color::RED,
                                                         Color::YELLOW,
                                                         Color::GREEN)), ...);
  }
  return result;
}

/**
 * \brief Инициализирует вектор умных указателей на светофоры.
 *
 * Функция `initialize_traffic_lights` создает вектор умных указателей на объекты типа `TrafficLightType`
 * с использованием заданного контекста ввода-вывода и начального индекса. Передает параметры в
 * `initialize_traffic_lights_impl` для создания конкретных светофоров. Необходима для того, чтобы
 * создать std::index_sequence, используемую при генерации id светофоров.
 *
 * \tparam TrafficLightType Тип светофора, который должен быть производным от `TrafficLight`.
 * \tparam StartFromIdx Начальный индекс для идентификаторов светофоров.
 * \tparam N Количество создаваемых светофоров.
 *
 * \param io_context Контекст ввода-вывода Boost.Asio для управления асинхронными операциями.
 *
 * \return Вектор умных указателей на созданные объекты светофоров.
 */
template <typename TrafficLightType, std::size_t StartFromIdx, std::size_t N>
std::vector<std::shared_ptr<TrafficLight>> initialize_traffic_lights(boost::asio::io_context& io_context) {
    return initialize_traffic_lights_impl<TrafficLightType, StartFromIdx>(io_context, std::make_index_sequence<N>{});
}

#endif // UTILS_H
