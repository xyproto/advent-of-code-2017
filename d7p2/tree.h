#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

using std::endl;
using std::nullopt;
using std::optional;
using std::unique_ptr;
using std::string;
using std::string_view;
using std::stringstream;
using std::vector;

class Node {
 private:
  string _name;
  unsigned _weight;
  vector<unique_ptr<Node>> _children;  // children
 public:
  Node(const string& name, unsigned weight = 0);
  string Name();
  void SetName(const string& name);
  unsigned Weight();
  void SetWeight(unsigned weight);
  vector<unique_ptr<Node>> Children();
  void AddChild(unique_ptr<Node> node);
  string str();
  const optional<unique_ptr<Node>> BFind(const string& name);
  const optional<unique_ptr<Node>> DFind(const string& name);
};

class Tree {
 private:
  vector<unique_ptr<Node>> _nodes;
  unique_ptr<Node> _root_node;

 public:
  Tree();
  void Add(unique_ptr<Node> node);
  string str();
  void SetRoot(unique_ptr<Node> node);
  unique_ptr<Node> Root();
  optional<unique_ptr<Node>> Find(const string& name);
};
