#include "tree.h"

Node::Node(const string & name, unsigned weight) {
    _name = name;
    _weight = weight;
    _children = vector<Node*> {};
}

string Node::Name() {
    return _name;
}

void Node::SetName(const string & name) {
    _name = name;
}

unsigned Node::Weight() {
    return _weight;
}

void Node::SetWeight(unsigned weight) {
    _weight = weight;
}

vector<Node*> Node::Children() {
    return _children;
}

void Node::AddChild(Node* node) {
    _children.push_back(node);
}

string Node::str() {
    stringstream s;
    s << _name << " (weight " << _weight << "), " << _children.size() << " children";
    return s.str();
}

// Breadth first search for a name,
optional<Node*> Node::BFind(const string & name) {
    if (_name == name) {
        // Found it! XD
        return optional<Node*> {this};
    }
    // Search the immediate children (but not in depth)
    for (const auto & child_node: _children) {
        if (child_node->Name() == name) {
            // Found it!
            return optional<Node*> {child_node};
        }
    }
    // Did not find it among the children, start searching the childrens' children
    for (const auto & child_node: _children) {
        const auto found_node = child_node->BFind(name);
        if (found_node) {
            // Found it!
            Node* subchild = *found_node;
            return subchild;
        }
    }
    // Found nothing :(
    return nullopt;
}

// Depth first search for a name
optional<Node*> Node::DFind(const string& name) {
    if (_name == name) {
        // Found it! XD
        return optional<Node*> {this};
    }
    for (const auto & child_node: _children) {
        if (child_node->Name() == name) {
            // Found it!
            return optional<Node*> {child_node};
        } else {
            // Search those sub-children, recursively!
            const auto found_node = child_node->DFind(name);
            if (found_node) {
                // Found it!
                Node* subchild = *found_node;
                return subchild;
            }
        }
    }
    // Found nothing :(
    return nullopt;
}

//---

Tree::Tree() {
    _nodes = vector<Node> {};
}

void Tree::Add(Node node) {
    _nodes.push_back(node);
}

optional<Node*> Tree::Find(const string & name) {
    for (auto & node: _nodes) {
        if (node.Name() == name) {
            return optional<Node*> {&node};
        }
    }
    return nullopt;
}

void Tree::SetRoot(Node* node) {
    _root_node = node;
}

Node* Tree::Root() {
    return _root_node;
}

string Tree::str() {
    stringstream s;
    s << "Tree with " << _nodes.size() << " nodes";
    for (auto & node: _nodes) {
        s << node.str() << endl;
    }
    return s.str();
}

// ---


