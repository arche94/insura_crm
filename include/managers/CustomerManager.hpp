#pragma once

#include <string>

#include "data/Customer.hpp"
#include "managers/DataManager.hpp"

class CustomerManager : public DataManager<Customer> {
 public:
  Customer add(const std::string& first_name, const std::string& last_name,
               const std::string& phone = "", const std::string& email = "");
  void update(int id, const std::string& first_name,
              const std::string& last_name, const std::string& phone,
              const std::string& email);
  std::vector<Customer> search(std::string query);
};