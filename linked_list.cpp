#include <iostream>

struct IntegerNode {
  int value;
  IntegerNode* next;
};

class LinkedIntegers {
  private:
    IntegerNode* head = nullptr;
    IntegerNode* last;

  public:
    void add(int num);
    void traverse();
    IntegerNode* get_node();
};

void LinkedIntegers::add (int num) {
  IntegerNode* next = new IntegerNode { num, nullptr };

  if (this -> head == nullptr) {
    this -> head = next;
    this -> last = next;
  } else {
    this -> last -> next = next;
    this -> last = next;
  }
}

void LinkedIntegers::traverse () {
  IntegerNode* head = this -> head;
  int i = 0;
  while (head != nullptr ) {
    std::cout << i++ << ") " << head -> value << "\n";
    head = head -> next;
  }
}

IntegerNode* LinkedIntegers::get_node() {
  return this -> head;
}


int main () {
  LinkedIntegers link;
  link.add(10);
  link.add(20);
  link.add(30);

  link.traverse();

  std::cout << "node value" << link.get_node() -> next -> value;

  return 0;
}