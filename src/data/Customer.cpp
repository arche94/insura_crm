#include "data/Customer.hpp"

#include <bits/stdc++.h>

#include <regex>

#include "utils/IDGeneratorSingleton.hpp"

// Constructors
Customer::Customer(IDGeneratorSingleton* id_gen, std::string _first_name,
                   std::string _last_name, std::string _phone,
                   std::string _email) {
  _id = id_gen->get_next_customer_id();
  first_name = _first_name;
  last_name = _last_name;
  if (is_valid_phone(_phone)) {
    phone = _phone;
  } else {
    phone = "";
  }
  if (is_valid_email(_email)) {
    email = _email;
  } else {
    email = "";
  }
}

// public
int Customer::get_id() { return _id; }

std::string Customer::get_first_name() { return first_name; }

std::string Customer::get_last_name() { return last_name; }

std::string Customer::get_full_name() { return first_name + " " + last_name; }

std::string Customer::get_phone() { return phone; }

std::string Customer::get_email() { return email; }

void Customer::set_first_name(std::string _first_name) {
  first_name = _first_name;
}

void Customer::set_last_name(std::string _last_name) { last_name = _last_name; }

void Customer::set_phone(std::string _phone) {
  if (is_valid_phone(_phone)) {
    phone = _phone;
  }
}

void Customer::set_email(std::string _email) {
  if (is_valid_email(_email)) {
    email = _email;
  }
}

// private
bool Customer::is_valid_email(std::string _email) {
  /** Validation logic
   * - must start with letter or digit
   * - allowed characters: letter, digit, ., _, -
   * - must contain @
   * - domain must start with letter or digit
   * - domain allowed characters: letter, digit, ., _, -
   * - must contain .
   * - top-level domain at least 2 chars long
   * - top-level domain allows only letters
   */
  return !(_email.empty() || _email.size() < 6 || _email.size() > 254) &&
         std::regex_match(
             _email,
             std::regex(
                 R"((^[a-zA-Z0-9][a-zA-Z0-9._-]*@[a-zA-Z0-9][a-zA-Z0-9.-]*\.[a-zA-Z]{2,})$)"));
}

bool Customer::is_valid_phone(std::string _phone) {
  /** Validation logic
   * - can contain + at start
   * - only digits allowed
   * - min 7 digits, max 15
   */
  return !_phone.empty() &&
         std::regex_match(_phone, std::regex(R"(^(\+)?\d{7,15}$)"));
}