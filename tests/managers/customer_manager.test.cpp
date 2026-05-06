#include "managers/customer_manager.test.hpp"

#include <bits/stdc++.h>

#include "data/Customer.hpp"
#include "managers/CustomerManager.hpp"

void test_customer_manager_add() {
  CustomerManager cm;
  Customer c = cm.add("John", "Doe", "+391234567890", "john@doe.com");

  assert(c.get_first_name() == "John");
  assert(c.get_last_name() == "Doe");
  assert(c.get_phone() == "+391234567890");
  assert(c.get_email() == "john@doe.com");
  assert(cm.get(c.get_id()) != std::nullopt);

  std::cout << "CustomerManager > Test add return value passed!" << std::endl;
}

void test_customer_manager_update() {
  CustomerManager cm;
  Customer c = cm.add("Mario", "Rossi", "+39333546987", "mario@rossi.it");
  int id = c.get_id();

  // All-empty update must leave every field unchanged
  cm.update(id, "", "", "", "");
  auto updated = cm.get(id);
  assert(updated->get_first_name() == "Mario");
  assert(updated->get_last_name() == "Rossi");
  assert(updated->get_phone() == "+39333546987");
  assert(updated->get_email() == "mario@rossi.it");

  // Only first_name provided: only that field changes
  cm.update(id, "Jane", "", "", "");
  updated = cm.get(id);
  assert(updated->get_first_name() == "Jane");
  assert(updated->get_last_name() == "Rossi");
  assert(updated->get_phone() == "+39333546987");
  assert(updated->get_email() == "mario@rossi.it");

  std::cout << "CustomerManager > Test update selective skipping passed!"
            << std::endl;
}

void test_customer_manager() {
  std::cout << std::endl;
  test_customer_manager_add();
  test_customer_manager_update();
  std::cout << "Test CustomerManager passed!" << std::endl;
}