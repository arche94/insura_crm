#include "data/Interaction.hpp"

#include <ctime>
#include <stdexcept>

#include "utils/IDGeneratorSingleton.hpp"

Interaction::Interaction(IDGeneratorSingleton* id_gen, int _customer_id,
                         std::time_t _date, Types _type, std::string _notes) {
  _id = id_gen->get_next_interaction_id();
  customer_id = _customer_id;
  date = _date;
  type = _type;
  notes = _notes;
}

int Interaction::get_id() { return _id; }

int Interaction::get_customer_id() { return customer_id; }

std::time_t Interaction::get_date() { return date; }

Interaction::Types Interaction::get_type() { return type; }

std::string Interaction::get_notes() { return notes; }

std::string Interaction::type2string(Interaction::Types t) {
  switch (t) {
    case Types::CONTRACT:
      return "CONTRACT";
    case Types::MEETING:
      return "MEETING";
    default:
      throw std::invalid_argument("Type not recognized");
  }
}