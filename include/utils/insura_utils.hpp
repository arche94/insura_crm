#pragma once

#include <ctime>
#include <string>

namespace insura_utils {
std::time_t parse_date(std::string s);
std::string date_to_str(std::time_t t);
}