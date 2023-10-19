// Copyright 2018 Your Name <your_email>

#include <tasks.hpp>

// Task 1.
void multi_2(std::vector<int>& input) {
  for (auto& item : input) {
    item *= 2;
  }
}

void reduce_a(std::vector<int>& input, int a) {
  for (auto& item : input) {
    item -= a;
  }
}

void div_on_first(std::vector<int>& input) {
  if (input.empty()) {
    return;
  }
  int zn = input[0];
  for (size_t i = 0; i < input.size(); ++i) {
    input[i] /= zn;
  }
}
