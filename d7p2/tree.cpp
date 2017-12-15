#include "tree.h"

// Create a new node, together with a weight and the names of the children (constructor #2)
Tree::Tree(string name, unsigned weight) {
    _name = name;
    _weight = weight;
    _children = {};
}

// Breadth first search for a name
optional<Tree*> Tree::BFirstSearch(string& name) {
    if (_name == name) {
        // Found it! XD
        return optional<Tree*> {this};
    }
    // Search the immediate children (but not in depth)
    for (auto& child: _children) {
        if (child->Name() == name) {
            // Found it!
            return optional<Tree*> {child};
        }
    }
    // Did not find it among the children, start searching the childrens' children
    for (auto& child: _children) {
        auto maybeTreeNode = child->BFirstSearch(name);
        if (maybeTreeNode) {
            // Found it!
            return *maybeTreeNode; // is a Tree after picking out the value with *
        }
    }
    // Found nothing :(
    return nullopt;
}

// Depth first search for a name
optional<Tree*> Tree::DFirstSearch(string& name) {
    if (_name == name) {
        // Found it! XD
        return optional<Tree*> {this};
    }
    for (auto& child: _children) {
        if (child->Name() == name) {
            // Found it!
            return optional<Tree*> {child};
        } else {
            // Search those sub-children, recursively!
            auto maybeTreeNode = child->DFirstSearch(name);
            if (maybeTreeNode) {
                // Found it!
                return *maybeTreeNode; // is a Tree after picking out the value with *
            }
        }
    }
    // Found nothing :(
    return nullopt;
}

// Add a new child
void Tree::AddChild(Tree* child) {
    _children.push_back(child);
}

// Print the tree with one-space indentation per level, depth first
string Tree::str(unsigned indentation_level) {
    stringstream s;
    for (unsigned i=0; i < indentation_level; i++) {
        s << "\t";
    }
    s << _name << endl;
    for (auto& child: _children) {
        for (unsigned i=0; i < indentation_level; i++) {
            s << "\t";
        }
        //s << child->Name() << endl;
        s << child->str(indentation_level + 1); // ends with newline
    }
    return s.str();
}

string Tree::Name() {
    return _name;
}

unsigned Tree::Weight() {
    return _weight;
}
