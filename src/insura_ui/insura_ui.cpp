#include "insura_ui/insura_ui.hpp"

#include <iostream>
#include <limits>

#include "insura_ui/customer_ui.hpp"
#include "insura_ui/interaction_ui.hpp"

void insura_ui::main_menu() {
  std::cout << "Welcome into Insura CRM!" << std::endl << std::endl;

  bool running = true;
  while (running) {
    std::cout << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "Main menu" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << std::endl;
    std::cout << "1) Customer menu" << std::endl;
    std::cout << "2) Interaction menu" << std::endl;
    std::cout << "0) Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Select an option: ";

    int option;
    std::cin >> option;
    std::cout << std::endl;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer value." << std::endl;
    } else {
      switch (option) {
        case 1:
          insura_ui::customer_menu();
          break;
        case 2:
          insura_ui::interaction_menu();
          break;
        case 0:
          running = false;
          break;

        default:
          std::cout << "Invalid option." << std::endl;
          break;
      }
    }
  }
}

void insura_ui::customer_menu() {
  bool in_customer = true;
  while (in_customer) {
    std::cout << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "Customer menu" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << std::endl;
    std::cout << "1) List customers" << std::endl;
    std::cout << "2) Add customer" << std::endl;
    std::cout << "3) Edit customer" << std::endl;
    std::cout << "4) Remove customer" << std::endl;
    std::cout << "5) Search customers" << std::endl;
    std::cout << "6) Customer details" << std::endl;
    std::cout << "0) Return to main menu" << std::endl;
    std::cout << std::endl;
    std::cout << "Select an option: ";

    int option;
    std::cin >> option;
    std::cout << std::endl;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer value." << std::endl;
    } else {
      switch (option) {
        case 1:
          insura_ui::customer_ui::list();
          break;
        case 2:
          insura_ui::customer_ui::add();
          break;
        case 3:
          insura_ui::customer_ui::edit();
          break;
        case 4:
          insura_ui::customer_ui::remove();
          break;
        case 5:
          insura_ui::customer_ui::search();
          break;
        case 6:
          insura_ui::customer_ui::details();
          break;
        case 0:
          in_customer = false;
          break;
        default:
          std::cout << "Invalid option." << std::endl;
          break;
      }
    }
  }
}

void insura_ui::interaction_menu() {
  bool in_interaction = true;
  while (in_interaction) {
    std::cout << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "Interaction menu" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << std::endl;
    std::cout << "1) List all interactions" << std::endl;
    std::cout << "2) Add customer interaction" << std::endl;
    std::cout << "3) Search interactions by customer" << std::endl;
    std::cout << "0) Return to main menu" << std::endl;
    std::cout << std::endl;
    std::cout << "Select an option: ";

    int option;
    std::cin >> option;
    std::cout << std::endl;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer value." << std::endl;
    } else {
      switch (option) {
        case 1:
          insura_ui::interaction_ui::list();
          break;
        case 2:
          insura_ui::interaction_ui::add();
          break;
        case 3:
          std::cout << "Search customer interaction" << std::endl;
          break;
        case 0:
          in_interaction = false;
          break;
        default:
          std::cout << "Invalid option." << std::endl;
          break;
      }
    }
  }
}