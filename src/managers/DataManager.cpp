#include "managers/DataManager.hpp"

#include <format>
#include <optional>
#include <stdexcept>
#include <vector>

template <typename T>
void DataManager<T>::add(T _item) {
  items.emplace(_item.get_id(), _item);
}

template <typename T>
std::optional<T> DataManager<T>::get(int _id) {
  auto item = items.find(_id);
  if (item != items.end()) {
    return item->second;
  }
  return std::nullopt;
}

template <typename T>
void DataManager<T>::update(int _id, T _item) {
  auto item = items.find(_id);
  if (item == items.end()) {
    throw std::runtime_error(
        std::format("[DataManager update] Object with id {} not found", _id));
  }
  item->second = _item;
}

template <typename T>
void DataManager<T>::remove(int _id) {
  if (items.erase(_id) == 0) {
    throw std::runtime_error(
        std::format("[DataManager remove] Object with id {} not found", _id));
  }
}

template <typename T>
std::vector<T> DataManager<T>::list() {
  std::vector<T> out;
  out.reserve(items.size());

  for (auto item : items) {
    out.push_back(item.second);
  }
  return out;
}

#include "data/Customer.hpp"
#include "data/Interaction.hpp"

template class DataManager<Customer>;
template class DataManager<Interaction>;