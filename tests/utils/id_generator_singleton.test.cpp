#include "id_generator_singleton.test.hpp"

#include <bits/stdc++.h>

#include <cassert>

#include "utils/IDGeneratorSingleton.hpp"

void test_id_generator_singleton() {
  std::cout << std::endl;

  IDGeneratorSingleton* s = IDGeneratorSingleton::get_instance();
  IDGeneratorSingleton* s_x = IDGeneratorSingleton::get_instance();

  assert(s == s_x);

  for (int i = 0; i < 100; i++) {
    assert(s->get_next_customer_id() == i);
    assert(s->get_next_interaction_id() == i);
  }

  std::cout << "Test IDGeneratorSingleton passed!" << std::endl;
}