// Copyright 2018 Your Name <your_email>

#include <tasks.hpp>

// Task 2.
int sum(const std::vector<int>& input) {
  int sum = 0;
  for (const auto& item : input) {
    sum += item;
  }
  return sum;
}

int square_sum(const std::vector<int>& input) {
  int square_sum = 0;
  for (const auto& item : input) {
    square_sum += (item * item);
  }
  return square_sum;
}

int sum_six(const std::vector<int>& input) {
  int sum_six = 0;
  for (int i = 0; i < 6; ++i) {
    sum_six += input[i];
  }
  return sum_six;
}

int sum_k(const std::vector<int>& input, int k1, int k2) {
  int sum_k = 0;
  if (k2 >= static_cast<int>(input.size())) {
    return 0;
  }
  while (k1 <= k2) {
    sum_k += input[k1];
    ++k1;
  }
  return sum_k;
}

int mean(const std::vector<int>& input) {
  int sum = 0;
  for (const auto& item : input) {
    sum += item;
  }
  return (sum / input.size());
}

int mean_k(const std::vector<int>& input, int s1, int s2) {
  int summ = 0;
  int i = s1;
  while (i <= s2) {
    summ += input[i];
    ++i;
  }
  return (summ / abs(1 + s2 - s1));
}
