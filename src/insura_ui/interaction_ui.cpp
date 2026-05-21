#include "insura_ui/interaction_ui.hpp"

#include <iostream>
#include <vector>

#include "data/Interaction.hpp"
#include "managers/InteractionManager.hpp"
#include "utils/insura_utils.hpp"

void print_interactions(std::vector<Interaction> interactions) {
  std::string sep = "| ";
  std::vector<std::string> fields = {"ID", "CustomerID", "Date", "Type",
                                     "Notes"};
  std::vector<int> field_len = {10, 15, 20, 20, 40};

  std::cout << std::endl;
  for (int i = 0; i < fields.size(); i++) {
    std::cout << sep << fields[i]
              << std::setw(field_len[i] - fields[i].length());
  }
  std::cout << sep << std::endl << std::string(105, '-') << std::endl;

  for (Interaction i : interactions) {
    std::string date_string = insura_utils::date_to_str(i.get_date());
    std::string type_string = Interaction::type2string(i.get_type());

    std::cout << sep << i.get_id()
              << std::setw(field_len[0] - std::to_string(i.get_id()).length());
    std::cout << sep << i.get_customer_id()
              << std::setw(field_len[1] -
                           std::to_string(i.get_customer_id()).length());
    std::cout << sep << date_string
              << std::setw(field_len[2] - date_string.length());
    std::cout << sep << type_string
              << std::setw(field_len[3] - type_string.length());
    std::cout << sep << i.get_notes()
              << std::setw(field_len[4] - i.get_notes().length());
    std::cout << sep << std::endl;
  }
}

InteractionManager* insura_ui::interaction_ui::interaction_manager =
    new InteractionManager();

void insura_ui::interaction_ui::list() {
  std::cout << "List interactions" << std::endl << std::endl;

  std::vector<Interaction> interactions = interaction_manager->list();
  print_interactions(interactions);
}

void insura_ui::interaction_ui::add() {
  int customer_id;
  std::string date_buf;
  std::time_t date;
  int type_buf;
  Interaction::Types type;
  std::string notes;

  std::cout << "Add interaction" << std::endl << std::endl;

  std::cout << "Customer ID: ";
  std::cin >> customer_id;

  std::cin.ignore();
  std::cout << "Date (YYYY-MM-DD): ";
  std::getline(std::cin, date_buf);
  date = insura_utils::parse_date(date_buf);

  std::cout << "Select type:" << std::endl
            << "\t1) Contract" << std::endl
            << "\t2) Meeting" << std::endl
            << std::endl;

  bool type_valid = false;
  while (!type_valid) {
    std::cout << "Type: ";
    std::cin >> type_buf;
    std::cout << std::endl;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer value." << std::endl;
    } else {
      switch (type_buf) {
        case 1:
          type = Interaction::Types::CONTRACT;
          type_valid = true;
          break;
        case 2:
          type = Interaction::Types::MEETING;
          type_valid = true;
          break;
        default:
          std::cout << "Invalid option." << std::endl;
          break;
      }
    }
  }

  std::cin.ignore();
  std::cout << "Notes: ";
  std::getline(std::cin, notes);

  Interaction i = interaction_manager->add(customer_id, date, type, notes);

  std::cout << "New interaction for customer " << customer_id
            << " hase been added with id " << i.get_id() << std::endl
            << std::endl;
}

void insura_ui::interaction_ui::search() {
  int customer_id;

  std::cout << "Search interactions" << std::endl << std::endl;

  std::cout << "Select customer: ";
  std::cin >> customer_id;

  std::vector<Interaction> found = interaction_manager->search(customer_id);

  if (found.size() == 0) {
    std::cout << std::endl
              << "No interaction found for customer " << customer_id
              << std::endl
              << std::endl;
  } else {
    print_interactions(found);
  }
}