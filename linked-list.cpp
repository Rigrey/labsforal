#include <vector>

struct Node {
  int data;
  Node* next;
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
  bool insert_list(int data, int pos);
  void print_list();
  ~LinkedList();

 private:
  Node* first;
  Node* last;
};

LinkedList::LinkedList() {
  first = nullptr;
  last = nullptr;
}

LinkedList::LinkedList(int data) {
  Node* nd = new Node{data, nullptr};
  first = nd;
  last = nd;
  last->next = nullptr;
}

LinkedList::LinkedList(std::vector<int> data) {
  first = nullptr;
  last = nullptr;
  for (int element : data) {
    add_element(element);
  }
}

bool LinkedList::add_element(int data) {
  Node* newNode = new Node{data, nullptr};
  if (first == nullptr) {
    first = newNode;
    last = newNode;
  } else {
    last->next = newNode;
    last = newNode;
  }
  newNode->next = nullptr;
  return true;
}

int LinkedList::delete_element(int data) {
  if (first == nullptr) {
    return -1;
  }
  Node* current = first;
  Node* previous = nullptr;
  while (current != nullptr) {
    if (current->data == data) {
      if (current == first) {
        first = first->next;
      } else if (current == last) {
        last = previous;
        last->next = nullptr;
      } else {
        previous->next = current->next;
      }
      return current->data;
    }
    previous = current;
    current = current->next;
  }
  return -1;
}

bool LinkedList::find_element(int data) {
  if (first == nullptr) {
    return 0;
  }
  Node* current = first;
  while (current != nullptr) {
    if (current->data == data) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

bool LinkedList::find_pos(int pos) {
  Node* current = first;
  int counter = 0;
  while (current != nullptr) {
    ++counter;
    if (counter == pos) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

bool LinkedList::insert_list(int data, int pos) {
  if (!this->find_pos(pos)) {
    return false;
  }
  Node* nd = new Node{data, nullptr};
  if (pos == 1) {
    nd->next = first;
    first = nd;
  } else {
    Node* current = first;
    for (int i = 1; i < pos - 1; ++i) {
      current = current->next;
    }
    nd->next = current->next;
    current->next = nd;
  }
  return true;
}

void LinkedList::print_list() {
  if (first == nullptr) {
    return;
  }
  Node* current = first;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

LinkedList::~LinkedList() {
  Node* current = first;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }
}
