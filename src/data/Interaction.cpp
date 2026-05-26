#include "data/Interaction.hpp"

#include <bits/stdc++.h>

#include "utils/IDGeneratorSingleton.hpp"
#include "utils/insura_utils.hpp"

Interaction::Interaction(IDGeneratorSingleton* id_gen, int _customer_id,
                         std::time_t _date, Types _type, std::string _notes) {
  _id = id_gen->get_next_interaction_id();
  customer_id = _customer_id;
  date = _date;
  type = _type;
  notes = _notes;
}

Interaction::Interaction(int id, int _customer_id, std::time_t _date,
                         Types _type, std::string _notes) {
  _id = id;
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

std::string Interaction::to_csv() {
  return std::to_string(_id) + "," + std::to_string(customer_id) + "," +
         insura_utils::date_to_str(date) + "," + type2string(type) + "," +
         notes;
}

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

Interaction::Types Interaction::string2type(std::string s) {
  if (s == "CONTRACT") return Types::CONTRACT;
  if (s == "MEETING") return Types::MEETING;
  throw std::invalid_argument("Type not recognized");
}

Interaction Interaction::from_csv(std::string s) {
  std::vector<std::string> row;
  std::string field;

  std::stringstream ss(s);
  while (std::getline(ss, field, ',')) {
    row.push_back(field);
  }

  int id = std::stoi(row[0]);
  int _customer_id = std::stoi(row[1]);
  std::time_t _date = insura_utils::parse_date(row[2]);
  Interaction::Types _type = string2type(row[3]);
  std::string notes = (row.size() > 4) ? row[4] : "";
  return Interaction(id, _customer_id, _date, _type, notes);
}