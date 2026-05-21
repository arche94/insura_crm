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
  for (std::string f : fields) {
    std::cout << sep << f << std::setw(10);
  }
  std::cout << std::endl
            << "---------------------------------------------------------------"
               "-----------------"
            << std::endl;

  for (Interaction i : interactions) {
    std::cout << sep << i.get_id() << std::setw(10);
    std::cout << sep << i.get_customer_id() << std::setw(10);
    std::cout << sep << insura_utils::date_to_str(i.get_date())
              << std::setw(10);
    std::cout << sep << Interaction::type2string(i.get_type()) << std::setw(10);
    std::cout << sep << i.get_notes() << std::setw(10);
    std::cout << std::endl;
  }
}

InteractionManager* insura_ui::interaction_ui::interaction_manager =
    new InteractionManager();

void insura_ui::interaction_ui::list() {
  std::cout << "List interactions" << std::endl << std::endl;

  std::vector<Interaction> interactions = interaction_manager->list();

  std::cout << std::endl;
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
        std::cout << "Invalid type!" << std::endl;
        break;
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