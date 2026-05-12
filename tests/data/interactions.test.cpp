#include "interactions.test.hpp"

#include <cassert>
#include <ctime>
#include <iostream>

#include "data/Interaction.hpp"
#include "utils/IDGeneratorSingleton.hpp"

void test_interactions_getters() {
  IDGeneratorSingleton* id_gen = IDGeneratorSingleton::get_instance();
  int cur_id = id_gen->get_next_interaction_id();
  time_t now = time(0);

  Interaction it_1 = Interaction(id_gen, 1, now, Interaction::Types::MEETING);
  Interaction it_2 =
      Interaction(id_gen, 1, now, Interaction::Types::CONTRACT, "Test note");

  assert(it_1.get_id() == (cur_id + 1) && it_2.get_id() == (cur_id + 2));
  assert(it_1.get_customer_id() == 1 && it_2.get_customer_id() == 1);
  assert(it_1.get_date() == now && it_2.get_date() == now);
  assert(it_1.get_type() == Interaction::Types::MEETING &&
         it_2.get_type() == Interaction::Types::CONTRACT);
  assert(it_1.get_notes() == "" && it_2.get_notes() == "Test note");

  std::cout << "Interactions > Test getters passed!" << std::endl;
}

void test_interactions() {
  std::cout << std::endl;
  test_interactions_getters();
  std::cout << "Test Interactions passed!" << std::endl;
}