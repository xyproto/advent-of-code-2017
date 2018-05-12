#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

using std::endl;
using std::make_shared;
using std::nullopt;
using std::optional;
using std::shared_ptr;
using std::string;
using std::string_view;
using std::stringstream;
using std::vector;

class Node {
private:
    string _name;
    unsigned _weight;
    vector<shared_ptr<Node>> _children; // children
public:
    Node(const string& name, unsigned weight = 0);
    string Name();
    void SetName(const string& name);
    unsigned Weight();
    void SetWeight(unsigned weight);
    vector<shared_ptr<Node>> Children();
    void AddChild(shared_ptr<Node> node);
    string str();
    const optional<shared_ptr<Node>> BFind(const string& name);
    const optional<shared_ptr<Node>> DFind(const string& name);
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
    optional<shared_ptr<Node>> Find(const string& name);
};
