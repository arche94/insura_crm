#pragma once

#include <ctime>
#include <string>

#include "utils/IDGeneratorSingleton.hpp"

class Interaction {
 public:
  enum class Types : int { CONTRACT, MEETING };

  Interaction(IDGeneratorSingleton* id_gen, int _customer_id, std::time_t _date,
              Types _type, std::string _notes = "");
  int get_id();
  int get_customer_id();
  std::time_t get_date();
  Types get_type();
  std::string get_notes();
  // requirements do not include setters

 private:
  int _id;
  int customer_id;
  std::time_t date;
  Types type;
  std::string notes;
};