#pragma once

#include <bits/stdc++.h>

#include "utils/IDGeneratorSingleton.hpp"

class Customer {
 private:
  int _id;
  std::string first_name;
  std::string last_name;
  std::string phone;
  std::string email;

  bool is_valid_email(std::string _email);
  bool is_valid_phone(std::string _phone);

 public:
  Customer(IDGeneratorSingleton* id_gen, std::string _first_name,
           std::string _last_name, std::string _phone = "",
           std::string _email = "");
  int get_id();
  std::string get_first_name();
  std::string get_last_name();
  std::string get_full_name();
  std::string get_phone();
  std::string get_email();
  void set_first_name(std::string _first_name);
  void set_last_name(std::string _last_name);
  void set_phone(std::string _phone);
  void set_email(std::string _email);

#ifdef __TEST__
  friend void test_validators();
  friend void test_constructors();
#endif
};