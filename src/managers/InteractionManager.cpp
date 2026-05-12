#include "managers/InteractionManager.hpp"

#include <ctime>
#include <string>
#include <vector>

#include "data/Interaction.hpp"
#include "utils/IDGeneratorSingleton.hpp"

Interaction InteractionManager::add(int _customer_id, std::time_t _date,
                                    Interaction::Types _type,
                                    const std::string& _notes) {
  IDGeneratorSingleton* id_gen = IDGeneratorSingleton::get_instance();
  Interaction i(id_gen, _customer_id, _date, _type, _notes);
  DataManager<Interaction>::add(i);
  return i;
}

std::vector<Interaction> InteractionManager::search(int _customer_id) {
  std::vector<Interaction> found;
  for (Interaction i : list()) {
    if (i.get_customer_id() == _customer_id) {
      found.push_back(i);
    }
  }
  return found;
}