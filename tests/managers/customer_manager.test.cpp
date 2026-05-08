#include "managers/customer_manager.test.hpp"

#include <bits/stdc++.h>

#include "data/Customer.hpp"
#include "managers/CustomerManager.hpp"

void test_customer_manager_add() {
  CustomerManager cm;
  Customer c = cm.add("Luca", "Bianchi", "+391234567890", "luca@bianchi.it");

  assert(c.get_first_name() == "Luca");
  assert(c.get_last_name() == "Bianchi");
  assert(c.get_phone() == "+391234567890");
  assert(c.get_email() == "luca@bianchi.it");
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
  cm.update(id, "Giuseppe", "", "", "");
  updated = cm.get(id);
  assert(updated->get_first_name() == "Giuseppe");
  assert(updated->get_last_name() == "Rossi");
  assert(updated->get_phone() == "+39333546987");
  assert(updated->get_email() == "mario@rossi.it");

  std::cout << "CustomerManager > Test update selective skipping passed!"
            << std::endl;
}

void test_customer_manager_search() {
  CustomerManager cm;
  cm.add("Giulia", "Ferrari", "+391111111111", "giulia@ferrari.it");
  cm.add("Marco", "Esposito", "+392222222222", "marco@esposito.it");
  cm.add("Giulia", "Esposito", "+393333333333", "giulia2@esposito.it");

  // Exact full-name match returns only that customer
  auto results = cm.search("Giulia Ferrari");
  assert(results.size() == 1);
  assert(results[0].get_first_name() == "Giulia");
  assert(results[0].get_last_name() == "Ferrari");

  // Partial first-name match returns all customers with that name
  results = cm.search("Giulia");
  assert(results.size() == 2);

  // Case-insensitive match
  results = cm.search("giulia ferrari");
  assert(results.size() == 1);
  results = cm.search("GIULIA FERRARI");
  assert(results.size() == 1);

  // Query with no match returns empty
  results = cm.search("Nessuno");
  assert(results.empty());

  std::cout << "CustomerManager > Test search passed!" << std::endl;
}

void test_customer_manager() {
  std::cout << std::endl;
  test_customer_manager_add();
  test_customer_manager_update();
  test_customer_manager_search();
  std::cout << "Test CustomerManager passed!" << std::endl;
}
