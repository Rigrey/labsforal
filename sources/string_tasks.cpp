// Copyright 2018 Your Name <your_email>

#include <tasks.hpp>

// Task 5.
bool name_is_even(const std::string& name) {
  return (name.size() % 2 == 0);
}

// Task 6.
bool first_is_longer(const std::string& name_one, const std::string& name_two) {
  return (name_one.size() > name_two.size());
}

// Task 7.
void longest_shortest(const std::string& name_one, const std::string& name_two,
                      const std::string& name_three, std::string& the_longest,
                      std::string& the_shortest) {
  std::vector<std::string> names = {name_one, name_two, name_three};
  the_longest = names[0];
  the_shortest = names[0];
  for (const std::string& name : names) {
    if (name.length() > the_longest.length()) {
      the_longest = name;
    }
    if (name.length() < the_shortest.length()) {
      the_shortest = name;
    }
  }
}

// Task 8.
std::string sub_str(const std::string& word, int m, int n) {
  std::string sub;
  sub.reserve(word.size());
  for (; m <= n; ++m) {
    if (m == static_cast<int>(word.size())) {
      break;
    }
    sub.push_back(word[m]);
  }
  return sub;
}

// Task 9.
void add_stars(std::string& word) {
  int size_word = word.size();
  word.insert(0, size_word, '*');
  word.append(size_word, '*');
}

// Task 10.
int percent_of_a(const std::string& word) {
  int n_a = 0;
  for (auto& item : word) {
    if (item == 'a') {
      ++n_a;
    }
  }
  return ((n_a * 100) / word.size());
}

// Task 11.
std::string replace_can(const std::string& new_word) {
  std::string result;
  std::string strToChange = "Can you can a can as a canner can can a can?";
  result.reserve(strToChange.size());
  for (size_t i = 0; i < strToChange.size(); ++i) {
    if (i < strToChange.size() - 2 && strToChange[i] == 'c' &&
        strToChange[i + 1] == 'a' && strToChange[i + 2] == 'n') {
      result += new_word;
      i += 3;
    }
    result += strToChange[i];
  }
  return result;
}
