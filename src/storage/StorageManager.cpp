#include "storage/StorageManager.hpp"

#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "data/Customer.hpp"
#include "data/Interaction.hpp"
#include "managers/CustomerManager.hpp"
#include "managers/InteractionManager.hpp"

namespace fs = std::filesystem;

StorageManager::StorageManager(CustomerManager* _customer_manager,
                               InteractionManager* _interaction_manager,
                               std::string _storage_dir) {
  customer_manager = _customer_manager;
  interaction_manager = _interaction_manager;
  storage_dir = _storage_dir;
}

void StorageManager::dump_data() {
  int n_customers = customer_manager->list().size();
  int n_interactions = interaction_manager->list().size();
  if (n_customers == 0 && n_interactions == 0) {
    throw std::runtime_error("No data found");
  }

  fs::create_directories(storage_dir);
  std::ofstream out_stream;

  fs::path cust_file(storage_dir);
  cust_file /= customers_file;
  out_stream.open(cust_file);

  for (Customer c : customer_manager->list()) {
    out_stream << c.to_csv() << std::endl;
  }
  out_stream.close();

  fs::path int_file(storage_dir);
  int_file /= interactions_file;
  out_stream.open(int_file);

  for (Interaction i : interaction_manager->list()) {
    out_stream << i.to_csv() << std::endl;
  }
  out_stream.close();
}

void StorageManager::load_data() {
  fs::path cust_file(storage_dir);
  cust_file /= customers_file;

  fs::path int_file(storage_dir);
  int_file /= interactions_file;

  if (!(fs::exists(cust_file) && fs::exists(int_file))) {
    throw std::runtime_error("No dump file found");
  }

  std::ifstream in_stream;
  std::string line;

  in_stream.open(cust_file);
  while (std::getline(in_stream, line)) {
    if (line.empty()) continue;
    Customer cust = Customer::from_csv(line);
    customer_manager->add(cust);
  }
  in_stream.close();

  in_stream.open(int_file);
  while (std::getline(in_stream, line)) {
    if (line.empty()) continue;
    Interaction inter = Interaction::from_csv(line);
    interaction_manager->add(inter);
  }
  in_stream.close();
}