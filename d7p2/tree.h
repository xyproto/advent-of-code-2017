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
using std::nullopt;
using std::stringstream;

class Tree {

private:
    string_view _name;         // Each node can have a name, which will not be changed after being set
    unsigned _weight;          // Each node can have a weight, that may be changed after being set
    vector<Tree*> _children;   // Each Tree node can have 0 or more children, which are just pointers to other Tree nodes

public:
    // Create a new node, together with a weight and the names of the children
    Tree(const string_view& name, const unsigned& weight = 0, const vector<string_view> childnames = {});

    // Depth first search for a name
    optional<Tree*> DFirstSearch(const string_view& name);

    // Breadth first search for a name
    optional<Tree*> BFirstSearch(const string_view& name);

    // Add a new child
    inline void AddChild(Tree* child);

    // Add a new child and return the new Tree node
    Tree AddChild(const string_view& name);

    const string str(unsigned indentation_level = 0);

    inline const string_view& Name();
};



