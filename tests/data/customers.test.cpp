#include "customers.test.hpp"

#include <bits/stdc++.h>

#include <cassert>

#include "data/Customer.hpp"
#include "utils/IDGeneratorSingleton.hpp"

void test_customers_validators() {
  IDGeneratorSingleton* s = IDGeneratorSingleton::get_instance();
  Customer c(s, "Mario", "Rossi");
  assert(c.is_valid_email("test@domain.com"));
  assert(!c.is_valid_email("wrongemail.string"));
  assert(!c.is_valid_email("wrong@emailstring"));

  assert(c.is_valid_phone("+39333546987"));
  assert(!c.is_valid_phone("wrong phone string"));
  std::cout << "Customers > Test validators passed!" << std::endl;
}

void test_customers_constructors() {
  IDGeneratorSingleton* id_generator = IDGeneratorSingleton::get_instance();
  int next_id = id_generator->get_next_customer_id();

  Customer c1(id_generator, "Mario", "Rossi");
  assert(c1._id == next_id + 1);
  assert(c1.first_name == "Mario");
  assert(c1.last_name == "Rossi");
  assert(c1.phone.empty());
  assert(c1.email.empty());

  Customer c2(id_generator, "Mario", "Bianchi", "+323293337766");
  assert(c2._id == next_id + 2);
  assert(c2.first_name == "Mario");
  assert(c2.last_name == "Bianchi");
  assert(c2.phone == "+323293337766");
  assert(c2.email.empty());

  Customer c3(id_generator, "Mario", "Gialli", "+333243454334",
              "m.gialli@test.it");
  assert(c3._id == next_id + 3);
  assert(c3.first_name == "Mario");
  assert(c3.last_name == "Gialli");
  assert(c3.phone == "+333243454334");
  assert(c3.email == "m.gialli@test.it");

  std::cout << "Customers > Test constructors passed!" << std::endl;
}

void test_customers_getters() {
  IDGeneratorSingleton* id_generator = IDGeneratorSingleton::get_instance();
  int next_id = id_generator->get_next_customer_id();

  Customer c(id_generator, "Mario", "Gialli", "+333243454334",
             "m.gialli@test.it");
  assert(c.get_id() == next_id + 1);
  assert(c.get_first_name() == "Mario");
  assert(c.get_last_name() == "Gialli");
  assert(c.get_full_name() == "Mario Gialli");
  assert(c.get_phone() == "+333243454334");
  assert(c.get_email() == "m.gialli@test.it");

  std::cout << "Customers > Test getters passed!" << std::endl;
}

void test_customers_setters() {
  IDGeneratorSingleton* id_generator = IDGeneratorSingleton::get_instance();
  Customer c(id_generator, "Mario", "Gialli", "+333243454334",
             "m.gialli@test.it");

  assert(c.get_first_name() == "Mario");
  c.set_first_name("Luigi");
  assert(c.get_first_name() == "Luigi");

  assert(c.get_last_name() == "Gialli");
  c.set_last_name("Rossi");
  assert(c.get_last_name() == "Rossi");

  assert(c.get_phone() == "+333243454334");
  c.set_phone("+10987654321");
  assert(c.get_phone() == "+10987654321");

  assert(c.get_email() == "m.gialli@test.it");
  c.set_email("new@email.test");
  assert(c.get_email() == "new@email.test");

  std::cout << "Customers > Test setters passed!" << std::endl;
}

void test_customers_setter_validation() {
  IDGeneratorSingleton* id_generator = IDGeneratorSingleton::get_instance();
  Customer c(id_generator, "Mario", "Rossi", "+39333546987", "mario@rossi.it");

  // Invalid email must not overwrite the existing value
  c.set_email("bad-email");
  assert(c.get_email() == "mario@rossi.it");

  // Invalid phone must not overwrite the existing value
  c.set_phone("abc");
  assert(c.get_phone() == "+39333546987");

  // Email over 254 chars must be rejected
  std::string too_long_email = std::string(250, 'a') + "@t.co";  // 255 chars
  c.set_email(too_long_email);
  assert(c.get_email() == "mario@rossi.it");

  std::cout << "Customers > Test setter validation rejection passed!"
            << std::endl;
}

void test_customers() {
  std::cout << std::endl;
  test_customers_validators();
  test_customers_constructors();
  test_customers_getters();
  test_customers_setters();
  test_customers_setter_validation();
  std::cout << "Test Customers passed!" << std::endl;
}