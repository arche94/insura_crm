#include "managers/CustomerManager.hpp"

#include <format>
#include <stdexcept>

#include "utils/IDGeneratorSingleton.hpp"

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
