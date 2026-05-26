#pragma once

#include <ctime>
#include <string>
#include <vector>

#include "data/Interaction.hpp"
#include "managers/CustomerManager.hpp"
#include "managers/DataManager.hpp"

class InteractionManager : public DataManager<Interaction> {
 public:
  Interaction add(Interaction i);
  Interaction add(int _customer_id, std::time_t _date, Interaction::Types _type,
                  const std::string& _notes = "");
  std::vector<Interaction> search(int _customer_id);
};