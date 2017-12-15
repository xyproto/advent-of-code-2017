#include <string>
#include <vector>
#include <optional>
#include <sstream>
#include <iostream>
#include <string_view>

using std::endl;
using std::string_view;
using std::vector;
using std::string;
using std::optional;

class Tree {

private:
    const string _name;        // Each node can have a name
    unsigned _weight;          // Each node can have a weight
    vector<Tree*> _children;   // Each Tree node can have 0 or more children, which are just pointers to other Tree nodes

public:
    // Create a new freestanding Tree node (constructor)
    Tree(const string_view& name, const unsigned& weight = 0) : _name{name}, _weight{weight}, _children{} {};

    // Create a new node, together with a weight and the names of the children
    Tree(const string_view& name, const unsigned& weight = 0, const vector<string_view> childnames = vector<string_view> {});

    // Depth first search for a name
    optional<Tree*> DFirstSearch(const string_view& name);

    // Breadth first search for a name
    optional<Tree*> BFirstSearch(const string_view& name);

    // Add a new child and return the new Tree node
    Tree* AddChild(const string_view& name, const unsigned& weight = 0);

    const string str();
};
