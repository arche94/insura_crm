#include "utils/IDGeneratorSingleton.hpp"

#include <bits/stdc++.h>

IDGeneratorSingleton* IDGeneratorSingleton::_instance = nullptr;

IDGeneratorSingleton::IDGeneratorSingleton() {
  last_customer_id = -1;
  last_interaction_id = -1;
}

IDGeneratorSingleton* IDGeneratorSingleton::get_instance() {
  if (_instance == nullptr) {
    _instance = new IDGeneratorSingleton();
  }
  return _instance;
}

int IDGeneratorSingleton::get_next_customer_id() {
  last_customer_id++;
  return last_customer_id;
}

int IDGeneratorSingleton::get_next_interaction_id() {
  last_interaction_id++;
  return last_interaction_id;
}