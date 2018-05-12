#include "tree.h"
#include "test.h"

int main() {
  cout << "hi" << endl;

  auto root = Node("root node"s);
  auto bob = Node("Bob"s);
  root.AddChild(unique_ptr<Node>(&bob));
  auto alice = Node("Alice"s);
  root.AddChild(unique_ptr<Node>(&alice));
  auto roger = Node("Roger"s);
  alice.AddChild(unique_ptr<Node>(&roger));
  auto malfoy = Node("Malfoy"s);
  alice.AddChild(unique_ptr<Node>(&malfoy));
  auto gregory = Node("Gregory"s);
  alice.AddChild(unique_ptr<Node>(&gregory));
  auto krang = Node("Gregory"s);
  alice.AddChild(unique_ptr<Node>(&krang));
  auto lucious = Node("Lucious"s);
  alice.AddChild(unique_ptr<Node>(&lucious));
  auto max = Node("Max"s);
  alice.AddChild(unique_ptr<Node>(&max));

  cout << root.str() << endl;

  auto node = root.DFind("Alice");
  if (node) {
    cout << (*node)->str() << endl;
  } else {
    cout << "Could not find Alice" << endl;
  }
}
