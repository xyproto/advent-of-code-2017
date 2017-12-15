#include <string>
#include <vector>
#include <optional>
#include <sstream>
#include <iostream>
#include <string_view>

using std::endl;
using std::string;
using std::vector;
using std::string_view;
using std::optional;
using std::nullopt;
using std::stringstream;

class Tree {

private:
    string _name;              // Each node can have a name, which will not be changed after being set
    unsigned _weight;          // Each node can have a weight, that may be changed after being set
    vector<Tree> _children;    // Each Tree node can have 0 or more children, which may be trees

public:
    // Create a new node, together with a weight and the names of the children
    Tree(string name, unsigned weight = 0, vector<string> childnames = {});

    // Breadth first search for a name
    optional<Tree> BFirstSearch(string& name);

    // Depth first search for a name
    optional<Tree> DFirstSearch(string& name);

    // Add a new child
    inline void AddChild(Tree child);

    // Add a new child and return the new Tree node
    Tree AddChild(string name);

    string str(unsigned indentation_level = 0);

    inline string Name();
};
