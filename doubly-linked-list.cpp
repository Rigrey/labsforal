#include <iostream>
#include <vector>

struct Node {
  int data;
  Node* next;
  Node* prev;
};

class LinkedList {
 public:
  LinkedList();
  LinkedList(int data);
  LinkedList(std::vector<int> data);
  bool add_element(int data);
  int delete_element(int data);
  bool find_element(int data);
  bool find_pos(int pos);
  constexpr int size_list();
  bool insert_list(int data, int pos);
  void print_list();
  void sort_list();
  void cycle_list();

  void inf_print_backwards();

  ~LinkedList();

 private:
  Node* first;
  Node* last;
  bool cycled = false;
};

LinkedList::LinkedList() {
  first = nullptr;
  last = nullptr;
}

LinkedList::LinkedList(int data) {
  first = nullptr;
  last = nullptr;
  add_element(data);
}

LinkedList::LinkedList(std::vector<int> data) {
  first = nullptr;
  last = nullptr;
  for (int element : data) {
    add_element(element);
  }
}

bool LinkedList::add_element(int data) {
  Node* newNode = new Node{data, nullptr, nullptr};
  if (first == nullptr) {
    first = newNode;
    last = newNode;
  } else {
    newNode->prev = last;
    last->next = newNode;
    last = newNode;
  }
  if (cycled) {
    newNode->next = first;
  } else {
    newNode->next = nullptr;
  }
  return true;
}

int LinkedList::delete_element(int data) {
  if (first == nullptr) {
    return -1;
  }
  Node* current = first;
  bool deleted = false;
  do {
    if (current != nullptr && current->data == data) {
      if (current == first) {
        Node* temp = first;
        first = first->next;
        if (cycled) {
          first->prev = last;
        } else {
          if (first != nullptr) {
            first->prev = nullptr;
          }
        }
        delete temp;
        deleted = true;
      } else if (current == last) {
        Node* temp = last;
        last = current->prev;
        if (cycled) {
          last->next = first;
        } else {
          last->next = nullptr;
        }
        delete temp;
        deleted = true;
        break;
      } else {
        Node* temp = current;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        Node* onemore = current->prev;
        delete temp;
        deleted = true;
        current = onemore;
      }
    }
    current = current->next;
  } while (current != nullptr && current != first);
  if (deleted) {
    return data;
  }
  return -1;
}

bool LinkedList::find_element(int data) {
  if (first == nullptr) {
    return 0;
  }
  Node* current = first;
  do {
    if (current->data == data) {
      return 1;
    }
    current = current->next;
  } while (current != nullptr && current != first);
  return 0;
}

bool LinkedList::find_pos(int pos) {
  if (!first) {
    return 0;
  }
  Node* current = first;
  int counter = 0;
  do {
    ++counter;
    if (counter == pos) {
      return 1;
    }
    current = current->next;
  } while (current != nullptr && current != first);
  return 0;
}

constexpr int LinkedList::size_list() {
  if (first == nullptr) {
    return 0;
  }
  Node* current = first;
  int counter = 0;
  do {
    ++counter;
    current = current->next;
  } while (current != nullptr && current != first);
  return counter;
}

bool LinkedList::insert_list(int data, int pos) {
  if (cycled) {
    if (pos > this->size_list()) pos = pos % this->size_list();
    while (pos < 0) {
      pos += this->size_list();
    }
  }
  if (!this->find_pos(pos)) {
    return false;
  }

  Node* nd = new Node{data, nullptr, nullptr};
  if (pos == 1) {
    nd->next = first;
    if (cycled) {
      first->prev = nd;
      nd->prev = last;
      last->next = nd;
    }
    first = nd;
  } else {
    if (pos == 0) {
      if (cycled) {
        nd->next = first;
        first->prev = nd;
        last->next = nd;
        first = nd;
        return true;
      }
    }
    Node* current = first;
    for (int i = 1; i < pos - 1; ++i) {
      current = current->next;
    }
    nd->next = current->next;
    nd->prev = current;
    current->next = nd;
  }
  return true;
}

void LinkedList::print_list() {
  if (first == nullptr) {
    return;
  }
  Node* current = first;
  do {
    std::cout << current->data << " ";
    current = current->next;
  } while (current != nullptr && current != first);
  std::cout << std::endl;
}

void LinkedList::sort_list() {
  if (first == nullptr || first->next == nullptr) {
    return;
  }
  if (cycled) {
    last->next = nullptr;
    first->prev = nullptr;
  }
  Node* sorted_first = nullptr;
  Node* unsorted = first;
  while (unsorted != nullptr) {
    Node* current = unsorted;
    unsorted = unsorted->next;
    if (sorted_first == nullptr || current->data < sorted_first->data) {
      current->next = sorted_first;
      if (sorted_first != nullptr) {
        sorted_first->prev = current;
      }
      sorted_first = current;
    } else {
      Node* temp = sorted_first;
      while (temp->next != nullptr && temp->next->data < current->data) {
        temp = temp->next;
      }
      current->next = temp->next;
      current->prev = temp;
      if (temp->next != nullptr) {
        temp->next->prev = current;
      }
      temp->next = current;
    }
  }
  sorted_first->prev = nullptr;
  Node* currenttemp = sorted_first;
  while (currenttemp->next != nullptr) {
    currenttemp->next->prev = currenttemp;
    currenttemp = currenttemp->next;
  }
  first = sorted_first;
  last = currenttemp;
  if (cycled) {
    this->cycle_list();
  }
}

void LinkedList::cycle_list() {
  last->next = first;
  first->prev = last;
  cycled = true;
}

void LinkedList::inf_print_backwards() {
  if (last == nullptr) {
    return;
  }
  Node* current = last;
  do {
    std::cout << current->data << " ";
    if (current == first) {
      std::cout << std::endl;
    }
    current = current->prev;
  } while (current != nullptr);
}

LinkedList::~LinkedList() {
  Node* current = first;
  if (cycled) {
    last->next = nullptr;
    first->prev = nullptr;
  }
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }
}

int main() {
  std::vector<int> hm{6, 7, 3, 2, -19, 5};
  LinkedList f(hm);
  LinkedList h(hm);
  std::cout << "F is cycled, H isn't." << std::endl;
  std::cout << "Adding and deleting elements. F comes first, H is second:" << std::endl;
  f.cycle_list();
  f.print_list();
  h.print_list();
  f.add_element(3);
  h.add_element(3);
  f.print_list();
  h.print_list();
  f.delete_element(3);
  h.delete_element(3);
  f.print_list();
  h.print_list();
  std::cout << "Finding elements, position and size and inserting elements:" << std::endl;
  std::cout << f.find_element(-19) << std::endl;
  std::cout << h.find_pos(3) << std::endl;
  std::cout << f.size_list() << std::endl;
  std::cout << h.insert_list(10, 15) << std::endl;
  f.print_list();
  f.insert_list(10, 8);
  f.print_list();
  f.insert_list(10, 11);
  f.print_list();
  f.insert_list(100, -8);
  f.print_list();
  h.insert_list(-10, 4);
  h.print_list();
  std::cout << "Sorting lists:" << std::endl;
  f.sort_list();
  f.print_list();
  h.sort_list();
  h.print_list();
  h.inf_print_backwards();  // only works 1 time bcs not cycled
  // f.inf_print_backwards();  // works inf bcs cycled :D
  std::cout << "-------------------------" << std::endl;
  std::cout << "Working with list created through one element" << std::endl;
  LinkedList m(3);
  m.add_element(5);
  m.add_element(5);
  m.add_element(5);
  m.add_element(5);
  m.print_list();
  m.delete_element(5);
  m.print_list();
  m.add_element(-5);
  m.add_element(-8);
  m.add_element(17);
  m.sort_list();
  std::cout << m.insert_list(10, 10) << std::endl;
  m.cycle_list();
  m.insert_list(10, 10);
  m.print_list();
}
