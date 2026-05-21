#include "insura_utils.test.hpp"

#include <cassert>
#include <ctime>
#include <iostream>
#include <stdexcept>

#include "utils/insura_utils.hpp"

using namespace insura_utils;

void test_parse_date() {
  std::string good = "2026-05-19";
  std::string bad = "pippo";
  std::string out_range = "1000-05-19";

  try {
    std::time_t t1 = insura_utils::parse_date(bad);
  } catch (std::invalid_argument e) {
    assert(std::string(e.what()) ==
           "Invalid date format. Accepted format: YYYY-MM-DD");
  }
  try {
    std::time_t t2 = insura_utils::parse_date(out_range);
  } catch (std::runtime_error e) {
    assert(std::string(e.what()) == "Date out of range");
  }
  std::time_t t3 = insura_utils::parse_date(good);
  std::tm* t3_date = std::localtime(&t3);
  int year = t3_date->tm_year + 1900;
  int month = t3_date->tm_mon + 1;
  int day = t3_date->tm_mday;
  assert(year == 2026 && month == 05 && day == 19);

  std::cout << "Test Insura Utils > Test parse date passed!" << std::endl;
}

void test_date_to_string() {
  std::string test_date = "2026-05-19";
  std::time_t test_time = insura_utils::parse_date(test_date);
  std::string out_date = insura_utils::date_to_str(test_time);

  assert(out_date == test_date);

  std::cout << "Test Insura Utils > Test date to string passed!" << std::endl;
}

void test_insura_utils() {
  std::cout << std::endl;
  test_parse_date();
  test_date_to_string();
  std::cout << "Test Insura Utils passed!" << std::endl;
}
