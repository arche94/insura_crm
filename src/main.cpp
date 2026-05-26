#include <bits/stdc++.h>

#include "insura_ui/customer_ui.hpp"
#include "insura_ui/insura_ui.hpp"
#include "insura_ui/interaction_ui.hpp"
#include "managers/CustomerManager.hpp"
#include "managers/InteractionManager.hpp"
#include "storage/StorageManager.hpp"

using namespace insura_ui;

int main() {
  CustomerManager customer_manager;
  InteractionManager interaction_manager;
  StorageManager sm(&customer_manager, &interaction_manager);

  customer_ui::customer_manager = &customer_manager;
  interaction_ui::interaction_manager = &interaction_manager;

  try {
    sm.load_data();
  } catch (std::runtime_error e) {
    std::cout << std::endl
              << "No data loaded. Starting a clean instance." << std::endl;
  }
  main_menu();
  try {
    sm.dump_data();
  } catch (std::runtime_error e) {
    std::cout << std::endl << "No data to store." << std::endl;
  }
}