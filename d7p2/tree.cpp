#include "tree.h"

Node::Node(const string& name, unsigned weight)
{
    _name = name;
    _weight = weight;
    _children = vector<shared_ptr<Node>>{};
}

string Node::Name() { return _name; }

void Node::SetName(const string& name) { _name = name; }

unsigned Node::Weight() { return _weight; }

void Node::SetWeight(unsigned weight) { _weight = weight; }

vector<shared_ptr<Node>> Node::Children() { return _children; }

void Node::AddChild(shared_ptr<Node> node) { _children.push_back(node); }

string Node::str()
{
    stringstream s;
    s << _name << " (weight " << _weight << "), " << _children.size() << " children";
    return s.str();
}

// Breadth first search for a name,
const optional<shared_ptr<Node>> Node::BFind(const string& name)
{
    using std::cerr;
    using std::endl;
    if (_name == "") {
        cerr << "_name has not been initialized!" << endl;
        exit(EXIT_FAILURE);
    }
    if (_name == name) {
        // Found it! XD
        return optional<shared_ptr<Node>>{ this };
    }
    // Search the immediate children (but not in depth)
    for (const auto& child_node : _children) {
        if (child_node->Name() == name) {
            // Found it!
            return optional<shared_ptr<Node>>(child_node);
        }
    }
    // Did not find it among the children, start searching the childrens' children
    for (const auto& child_node : _children) {
        const auto found_node = child_node->BFind(name);
        if (found_node) {
            // Found it!
            return optional<shared_ptr<Node>>(*found_node);
        }
    }
    // Found nothing :(
    return nullopt;
}

// Depth first search for a name
const optional<shared_ptr<Node>> Node::DFind(const string& name)
{
    if (_name == name) {
        // Found it! XD
        return optional<shared_ptr<Node>>{ this };
    }
    for (const auto& child_node : _children) {
        if (child_node->Name() == name) {
            // Found it!
            return optional<shared_ptr<Node>>(child_node);
        } else {
            // Search those sub-children, recursively!
            const auto found_node = child_node->DFind(name);
            if (found_node) {
                // Found it!
                return optional<shared_ptr<Node>>(*found_node);
            }
        }
    }
    // Found nothing :(
    return nullopt;
}

//---

Tree::Tree() { _nodes = vector<shared_ptr<Node>>{}; }

void Tree::Add(shared_ptr<Node> node) { _nodes.push_back(node); }

optional<shared_ptr<Node>> Tree::Find(const string& name)
{
    for (auto& node : _nodes) {
        if (node->Name() == name) {
            return optional<shared_ptr<Node>>{ node };
        }
    }
    return nullopt;
}

void Tree::SetRoot(shared_ptr<Node> node) { _root_node = node; }

shared_ptr<Node> Tree::Root() { return _root_node; }

string Tree::str()
{
    stringstream s;
    s << "Tree with " << _nodes.size() << " nodes";
    for (auto& node : _nodes) {
        s << node->str() << endl;
    }
    return s.str();
}

// ---
