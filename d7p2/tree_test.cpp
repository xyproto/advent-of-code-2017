#include "test.h"
#include "tree.h"

int main() {
    cout << "hi" << endl;

    auto root = Tree("root node"s);

    auto bob = Tree("Bob"s); root.AddChild(&bob);
    auto alice = Tree("Alice"s); root.AddChild(&alice);
    auto roger = Tree("Roger"s); alice.AddChild(&roger);
    auto malfoy = Tree("Malfoy"s); alice.AddChild(&malfoy);
    auto gregory = Tree("Gregory"s); alice.AddChild(&gregory);
    auto krang = Tree("Gregory"s); alice.AddChild(&krang);
    auto lucious = Tree("Lucious"s); alice.AddChild(&lucious);
    auto max = Tree("Max"s); alice.AddChild(&max);

    cout << root.str() << endl;
}

