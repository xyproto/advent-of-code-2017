#include "test.h"
#include "tree.h"

int main() {
    cout << "hi" << endl;

    auto root_node = Tree("root node"s);
    auto root = &root_node;
    root->AddChild("Bob"s);
    auto alice = root->AddChild("Alice"s);
    alice.AddChild("Roger"s);
    alice.AddChild("Malfoy"s);
    alice.AddChild("Gregory"s);
    alice.AddChild("Krang"s);
    alice.AddChild("Lucious"s);
    alice.AddChild("Max"s);

    cout << root_node.str() << endl;

}
