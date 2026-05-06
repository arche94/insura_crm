#pragma once

#include "managers/CustomerManager.hpp"

namespace insura_ui::customer_ui {
extern CustomerManager* customer_manager;

void list();
void add();
void edit();
void remove();
void search();
void details();
}  // namespace insura_ui::customer_ui