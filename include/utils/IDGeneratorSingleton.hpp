#pragma once

class IDGeneratorSingleton {
  static IDGeneratorSingleton* _instance;
  int last_customer_id;
  int last_interaction_id;

  IDGeneratorSingleton();

 public:
  static IDGeneratorSingleton* get_instance();
  IDGeneratorSingleton(IDGeneratorSingleton& s) = delete;
  void operator=(IDGeneratorSingleton& s) = delete;
  int get_next_customer_id();
  int get_next_interaction_id();
  void set_last_customer_id(int _id);
  void set_last_interaction_id(int _id);
};