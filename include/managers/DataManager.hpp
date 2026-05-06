#pragma once

#include <optional>
#include <unordered_map>
#include <vector>

template <typename T>
class DataManager {
 private:
  std::unordered_map<int, T> items;

 public:
  DataManager() = default;
  void add(T _item);
  std::optional<T> get(int _id);
  void update(int _id, T _item);
  void remove(int _id);
  std::vector<T> list();
};