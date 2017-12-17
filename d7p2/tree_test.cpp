#include "test.h"
#include "tree.h"

int main() {
    cout << "hi" << endl;

    auto root = Node("root node"s);
    auto bob = Node("Bob"s); root.AddChild(&bob);
    auto alice = Node("Alice"s); root.AddChild(&alice);
    auto roger = Node("Roger"s); alice.AddChild(&roger);
    auto malfoy = Node("Malfoy"s); alice.AddChild(&malfoy);
    auto gregory = Node("Gregory"s); alice.AddChild(&gregory);
    auto krang = Node("Gregory"s); alice.AddChild(&krang);
    auto lucious = Node("Lucious"s); alice.AddChild(&lucious);
    auto max = Node("Max"s); alice.AddChild(&max);

    cout << root.str() << endl;
}

