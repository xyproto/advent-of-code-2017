#include <string>
#include <vector>
#include <optional>
#include <sstream>
#include <iostream>
#include <string_view>
#include <memory>

using std::endl;
using std::string;
using std::vector;
using std::string_view;
using std::optional;
using std::nullopt;
using std::stringstream;
using std::shared_ptr;

class Node {
private:
    string _name;
    unsigned _weight;
    vector<shared_ptr<Node>> _children; // children
public:
    Node(const string & name, unsigned weight = 0);
    string Name();
    void SetName(const string & name);
    unsigned Weight();
    void SetWeight(unsigned weight);
    vector<shared_ptr<Node>> Children();
    void AddChild(shared_ptr<Node> node);
    string str();
    optional<shared_ptr<Node>> BFind(const string & name);
    optional<shared_ptr<Node>> DFind(const string & name);
};

class Tree {
private:
    vector<shared_ptr<Node>> _nodes;
    shared_ptr<Node> _root_node;
public:
    Tree();
    void Add(shared_ptr<Node> node);
    string str();
    void SetRoot(shared_ptr<Node> node);
    shared_ptr<Node> Root();
    optional<shared_ptr<Node>> Find(const string & name);
};
