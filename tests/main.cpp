#include <bits/stdc++.h>

#include "./data/customers.test.hpp"
#include "./managers/data_manager.test.hpp"
#include "./utils/id_generator_singleton.test.hpp"

using namespace std;

int main() {
  cout << endl
       << "----------------------------------------------------------" << endl
       << "\t\tEnsura CRM - Test suite" << endl
       << "----------------------------------------------------------" << endl;

  test_id_generator_singleton();
  test_customers();
  test_data_manager();

  cout << "----------------------------------------------------------" << endl
       << "\t\tAll tests passed!" << endl
       << "----------------------------------------------------------" << endl;
}