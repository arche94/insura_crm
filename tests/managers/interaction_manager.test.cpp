#include "interaction_manager.test.hpp"

#include <cassert>
#include <ctime>
#include <iostream>

#include "data/Interaction.hpp"
#include "managers/InteractionManager.hpp"

void test_interaction_manager_add() {
  std::time_t now = std::time(0);
  InteractionManager im;
  Interaction i1 = im.add(1, now, Interaction::Types::CONTRACT);
  Interaction i2 = im.add(1, now, Interaction::Types::MEETING, "Test note");

  assert(i1.get_customer_id() == 1 && i2.get_customer_id() == 1);
  assert(i1.get_date() == now && i2.get_date() == now);
  assert(i1.get_type() == Interaction::Types::CONTRACT &&
         i2.get_type() == Interaction::Types::MEETING);
  assert(i1.get_notes() == "" && i2.get_notes() == "Test note");
  assert(im.get(i1.get_id()) != std::nullopt &&
         im.get(i2.get_id()) != std::nullopt);

  std::cout << "InteractionManager > Test add passed!" << std::endl;
}

void test_interaction_manager_search() {
  InteractionManager im;
  im.add(1, std::time(0), Interaction::Types::CONTRACT);
  im.add(1, std::time(0), Interaction::Types::MEETING, "Test note");
  im.add(2, std::time(0), Interaction::Types::MEETING, "Test note to exclude");

  // Query by customer_id with assigned interactions
  auto results = im.search(1);
  assert(results.size() == 2);
  for (Interaction i : results) {
    assert(i.get_customer_id() == 1);
  }

  // Query by customer_id with no interactions
  results = im.search(3);
  assert(results.empty());

  std::cout << "InteractionManager > Test search passed!" << std::endl;
}

void test_interaction_manager() {
  std::cout << std::endl;
  test_interaction_manager_add();
  test_interaction_manager_search();
  std::cout << "Test InteractionManager passed!" << std::endl;
}