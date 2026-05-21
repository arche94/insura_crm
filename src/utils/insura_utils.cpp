#include "utils/insura_utils.hpp"

#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>

std::time_t insura_utils::parse_date(std::string s) {
  std::tm tm = {};
  std::istringstream ss(s);

  ss >> std::get_time(&tm, "%Y-%m-%d");
  if (ss.fail()) {
    throw std::invalid_argument(
        "Invalid date format. Accepted format: YYYY-MM-DD");
  }

  tm.tm_isdst = -1;
  std::time_t date = std::mktime(&tm);
  if (date == -1) {
    throw std::runtime_error("Date out of range");
  }
  return date;
}

std::string insura_utils::date_to_str(std::time_t t) {
  size_t str_size = std::size("YYYY-mm-dd");
  char buf[str_size];
  std::tm* t_date = std::localtime(&t);
  std::strftime(buf, str_size, "%Y-%m-%d", t_date);

  return std::string(buf);
}