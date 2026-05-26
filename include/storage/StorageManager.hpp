#pragma once

#include <string>
#include <tuple>

#include "managers/CustomerManager.hpp"
#include "managers/InteractionManager.hpp"

class StorageManager {
 public:
  StorageManager(CustomerManager* _customer_manager,
                 InteractionManager* _interaction_manager,
                 std::string _storage_dir = ".insura-db/");
  void dump_data();
  void load_data();

 private:
  CustomerManager* customer_manager;
  InteractionManager* interaction_manager;

  std::string storage_dir;
  const std::string customers_file = "customers.csv";
  const std::string interactions_file = "interactions.csv";
};
