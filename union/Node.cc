#include <iostream>

struct Node {
  int id;
  struct Node* left;
  struct Node* right;
  union Type {
    int intValue;
    float floatValue;
  } value;
};

void PrintNode(const Node& node) {
  std::cout << "Node id=" << node.id << ", ";
  std::cout << "node intValue=" << node.value.intValue << ", ";
  std::cout << "node floatValue=" << node.value.floatValue << std::endl;
}

int main() {
  Node root;
  root.id = 0;
  root.left = NULL;
  root.right = NULL;
  root.value.intValue = 5;
  PrintNode(root);
  root.value.floatValue = 10;
    PrintNode(root);    
  return 0;
}