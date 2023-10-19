// Copyright 2018 Your Name <your_email>

#include <tasks.hpp>

// Task 4.
void remove_negative(std::vector<int>& input) {
  for (size_t i = 0; i < input.size(); ++i) {
    if (input[i] < 0) {
      input.erase(input.begin() + i);
      break;
    }
  }
}

void remove_last_even(std::vector<int>& input) {
  int lastit = -1;
  for (int i = input.size() - 1; i >= 0; --i) {
    if (input[i] % 2 == 0) {
      lastit = i;
      break;
    }
  }
  if (lastit != -1) {
    input.erase(input.begin() + lastit);
  }
}
