#include <bits/stdc++.h>

#include "data/Customer.hpp"
#include "utils/IDGeneratorSingleton.hpp"

using namespace std;

int main() {
  IDGeneratorSingleton* id_generator = IDGeneratorSingleton::get_instance();
  Customer c1(id_generator, "Mario", "Rossi");
  cout << endl
       << "ID: " << c1.get_id() << endl
       << "Name: " << c1.get_first_name() << endl
       << "Last name: " << c1.get_last_name() << endl
       << "Full name: " << c1.get_full_name() << endl;

  Customer c2(id_generator, "Mario", "Bianchi", "+323293337766");
  cout << endl
       << "ID: " << c2.get_id() << endl
       << "Name: " << c2.get_first_name() << endl
       << "Last name: " << c2.get_last_name() << endl
       << "Full name: " << c2.get_full_name() << endl
       << "Phone: " << c2.get_phone() << endl;

  Customer c3(id_generator, "Mario", "Gialli", "+333243454334",
              "m.gialli@test.it");
  cout << endl
       << "ID: " << c3.get_id() << endl
       << "Name: " << c3.get_first_name() << endl
       << "Last name: " << c3.get_last_name() << endl
       << "Full name: " << c3.get_full_name() << endl
       << "Phone: " << c3.get_phone() << endl
       << "Email: " << c3.get_email() << endl;

  c3.set_first_name("Gianni");
  c3.set_last_name("Viola");
  c3.set_phone("1234567890");
  c3.set_email("g.viola@dischi.tarocchi");
  cout << endl
       << "ID: " << c3.get_id() << endl
       << "Name: " << c3.get_first_name() << endl
       << "Last name: " << c3.get_last_name() << endl
       << "Full name: " << c3.get_full_name() << endl
       << "Phone: " << c3.get_phone() << endl
       << "Email: " << c3.get_email() << endl;
}