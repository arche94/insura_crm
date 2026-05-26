#include "managers/CustomerManager.hpp"

#include <cctype>
#include <format>
#include <stdexcept>
#include <string>

#include "utils/IDGeneratorSingleton.hpp"

Customer CustomerManager::add(Customer c) {
  DataManager<Customer>::add(c);
  return c;
}

Customer CustomerManager::add(const std::string& first_name,
                              const std::string& last_name,
                              const std::string& phone,
                              const std::string& email) {
  IDGeneratorSingleton* id_gen = IDGeneratorSingleton::get_instance();
  Customer c(id_gen, first_name, last_name, phone, email);
  DataManager<Customer>::add(c);
  return c;
}

void CustomerManager::update(int id, const std::string& first_name,
                             const std::string& last_name,
                             const std::string& phone,
                             const std::string& email) {
  std::optional<Customer> c = get(id);
  if (!c.has_value()) {
    throw std::runtime_error(
        std::format("[CustomerManager] Customer with id {} not found", id));
  }
  if (!first_name.empty()) c->set_first_name(first_name);
  if (!last_name.empty()) c->set_last_name(last_name);
  if (!phone.empty()) c->set_phone(phone);
  if (!email.empty()) c->set_email(email);
  DataManager<Customer>::update(id, *c);
}

std::vector<Customer> CustomerManager::search(std::string query) {
  std::vector<Customer> found;
  std::transform(query.begin(), query.end(), query.begin(), ::tolower);

  for (Customer c : list()) {
    std::string f_name = c.get_full_name();
    std::transform(f_name.begin(), f_name.end(), f_name.begin(), ::tolower);
    if (f_name.find(query) != std::string::npos) {
      found.push_back(c);
    }
  }
  return found;
}
