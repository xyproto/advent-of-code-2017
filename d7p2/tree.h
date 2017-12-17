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

class Node {
private:
    string _name;
    unsigned _weight;
    vector<Node*> _children; // children
public:
    Node(const string & name, unsigned weight = 0);
    string Name();
    void SetName(const string & name);
    unsigned Weight();
    void SetWeight(unsigned weight);
    vector<Node*> Children();
    void AddChild(Node* node);
    string str();
    optional<Node*> BFind(const string & name);
    optional<Node*> DFind(const string & name);
};

class Tree {
private:
    vector<Node> _nodes;
    Node* _root_node;
public:
    Tree();
    void Add(Node node);
    string str();
    void SetRoot(Node* node);
    Node* Root();
    optional<Node*> Find(const string & name);
};
