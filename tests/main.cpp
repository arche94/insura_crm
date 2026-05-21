#include <bits/stdc++.h>

#include "./data/customers.test.hpp"
#include "./data/interactions.test.hpp"
#include "./managers/customer_manager.test.hpp"
#include "./managers/data_manager.test.hpp"
#include "./managers/interaction_manager.test.hpp"
#include "./utils/id_generator_singleton.test.hpp"
#include "./utils/insura_utils.test.hpp"

using namespace std;

int main() {
  cout << endl
       << "----------------------------------------------------------" << endl
       << "\t\tInsura CRM - Test suite" << endl
       << "----------------------------------------------------------" << endl;

  test_id_generator_singleton();
  test_insura_utils();
  test_customers();
  test_interactions();
  test_data_manager();
  test_customer_manager();
  test_interaction_manager();

  cout << "----------------------------------------------------------" << endl
       << "\t\tAll tests passed!" << endl
       << "----------------------------------------------------------" << endl;
}