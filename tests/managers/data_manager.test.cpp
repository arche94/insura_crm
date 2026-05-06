#include "data_manager.test.hpp"

#include <bits/stdc++.h>

#include <cassert>
#include <stdexcept>

#include "data/Customer.hpp"
#include "managers/CustomerManager.hpp"
#include "managers/DataManager.hpp"
#include "utils/IDGeneratorSingleton.hpp"

IDGeneratorSingleton* id_gen = IDGeneratorSingleton::get_instance();

void test_customer_manager_empty() {
  DataManager<Customer> cm;
  Customer c_test(id_gen, "Mario", "Rossi");

  assert(cm.get(0) == std::nullopt);

  bool thrown = false;
  std::string e_msg = "";
  try {
    cm.update(0, c_test);
  } catch (std::runtime_error e) {
    thrown = true;
    e_msg = e.what();
  }
  assert(thrown && e_msg.find("not found") != std::string::npos);

  thrown = false;
  e_msg = "";
  try {
    cm.remove(0);
  } catch (std::runtime_error e) {
    thrown = true;
    e_msg = e.what();
  }
  assert(thrown && e_msg.find("not found") != std::string::npos);

  std::cout << "DataManager > Test empty customer manager passed!" << std::endl;
}

void test_customer_manager_full() {
  DataManager<Customer> cm;
  Customer c1(id_gen, "Mario", "Rossi"), c2(id_gen, "Luigi", "Verdi");
  int c1_id = c1.get_id(), c2_id = c2.get_id();

  cm.add(c1);
  cm.add(c2);

  assert(cm.get(c1_id) != std::nullopt &&
         cm.get(c1_id)->get_full_name() == "Mario Rossi");
  assert(cm.get(c2_id) != std::nullopt &&
         cm.get(c2_id)->get_full_name() == "Luigi Verdi");

  c1.set_last_name("Bianchi");
  assert(cm.get(c1_id)->get_last_name() != "Bianchi");
  cm.update(c1_id, c1);
  assert(cm.get(c1_id)->get_last_name() == "Bianchi");

  cm.remove(c2_id);

  assert(cm.get(c2_id) == std::nullopt);

  std::cout << "DataManager > Test full customer manager passed!" << std::endl;
}

void test_data_manager_list() {
  DataManager<Customer> cm;
  Customer c1(id_gen, "Mario", "Rossi"), c2(id_gen, "Luigi", "Verdi");
  int c1_id = c1.get_id(), c2_id = c2.get_id();

  cm.add(c1);
  cm.add(c2);

  std::vector<Customer> items = cm.list();
  assert(items.size() == 2);

  bool found_c1 = false, found_c2 = false;
  for (auto& item : items) {
    if (item.get_id() == c1_id) found_c1 = true;
    if (item.get_id() == c2_id) found_c2 = true;
  }
  assert(found_c1 && found_c2);

  std::cout << "DataManager > Test list passed!" << std::endl;
}

void test_data_manager() {
  std::cout << std::endl;
  test_customer_manager_empty();
  test_customer_manager_full();
  test_data_manager_list();
  std::cout << "Test DataManager passed!" << std::endl;
}
