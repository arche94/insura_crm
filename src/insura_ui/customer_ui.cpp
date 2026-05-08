#include "insura_ui/customer_ui.hpp"

#include <iostream>

#include "managers/CustomerManager.hpp"

CustomerManager* insura_ui::customer_ui::customer_manager =
    new CustomerManager();

void insura_ui::customer_ui::list() {
  std::cout << "List customers" << std::endl << std::endl;

  std::string sep = "| ";
  std::vector<std::string> fields = {"ID", "First name", "Last name", "Phone",
                                     "Email"};
  std::vector<Customer> customers = customer_manager->list();

  std::cout << std::endl;
  for (std::string f : fields) {
    std::cout << sep << f << std::setw(10);
  }
  std::cout << std::endl
            << "---------------------------------------------------------------"
               "-----------------"
            << std::endl;

  for (auto c : customers) {
    std::cout << sep << c.get_id() << std::setw(10);
    std::cout << sep << c.get_first_name() << std::setw(10);
    std::cout << sep << c.get_last_name() << std::setw(10);
    std::cout << sep << c.get_phone() << std::setw(10);
    std::cout << sep << c.get_email() << std::setw(10);
    std::cout << std::endl;
  }
}

void insura_ui::customer_ui::add() {
  std::string first_name;
  std::string last_name;
  std::string phone;
  std::string email;

  std::cout << "Add new customer" << std::endl << std::endl;

  std::cin.ignore();
  std::cout << "First name: ";
  std::getline(std::cin, first_name);

  std::cout << "Last name: ";
  std::getline(std::cin, last_name);

  std::cout << "Phone number (optional): ";
  std::getline(std::cin, phone);

  std::cout << "Email address (optional): ";
  std::getline(std::cin, email);

  Customer c = customer_manager->add(first_name, last_name, phone, email);

  std::cout << std::endl
            << "New customer " << c.get_full_name()
            << " has been added with id " << c.get_id() << std::endl
            << std::endl;
}

void insura_ui::customer_ui::edit() {
  int customer_id;
  std::string first_name;
  std::string last_name;
  std::string phone;
  std::string email;

  std::cout << "Edit customer" << std::endl << std::endl;

  std::cout << "Select customer id: ";
  std::cin >> customer_id;

  std::cin.ignore();
  std::cout << "Information to edit (leave blank to skip)" << std::endl;

  std::cout << "First name: ";
  std::getline(std::cin, first_name);

  std::cout << "Last name: ";
  std::getline(std::cin, last_name);

  std::cout << "Phone number: ";
  std::getline(std::cin, phone);

  std::cout << "Email address: ";
  std::getline(std::cin, email);

  try {
    customer_manager->update(customer_id, first_name, last_name, phone, email);
    std::cout << std::endl
              << "Customer with id " << customer_id << " successfully updated!"
              << std::endl
              << std::endl;
  } catch (std::runtime_error& e) {
    std::cout << std::endl << e.what() << std::endl << std::endl;
  }
}

void insura_ui::customer_ui::remove() {
  int customer_id;

  std::cout << "Remove customer" << std::endl << std::endl;

  std::cout << "Select customer id: ";
  std::cin >> customer_id;

  try {
    customer_manager->remove(customer_id);
    std::cout << std::endl
              << "Customer with id " << customer_id << " successfully removed!"
              << std::endl
              << std::endl;
  } catch (std::runtime_error& e) {
    std::cout << std::endl << e.what() << std::endl << std::endl;
  }
}

void insura_ui::customer_ui::search() {
  std::cout << "Search customers" << std::endl << std::endl;
}

void insura_ui::customer_ui::details() {
  int customer_id;

  std::cout << "Customer details" << std::endl << std::endl;

  std::cout << "Select customer id: ";
  std::cin >> customer_id;

  std::optional<Customer> c = customer_manager->get(customer_id);
  if (c == std::nullopt) {
    std::cout << std::endl
              << "No customer with id " << customer_id << " found" << std::endl
              << std::endl;
  } else {
    std::cout << std::endl
              << "Customer: " << c->get_full_name() << std::endl
              << "Phone number: " << c->get_phone() << std::endl
              << "Email address: " << c->get_email() << std::endl
              << std::endl;
  }
}
