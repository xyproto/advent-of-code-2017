#include "tree.h"

// Create a new node, together with a weight and the names of the children (constructor #2)
Tree::Tree(const string_view& name, const unsigned& weight, const vector<string_view> childnames) {
    _name = name;
    _weight = weight;
    // TODO: If this lambda works, check if it can be placed directly in the initializer list
    _children = [&] (vector<string_view> _childnames) -> vector<Tree*> {
        vector<Tree*> children {};
        for (const auto& childname: _childnames) {
            auto tree_node = Tree(childname);
            children.push_back(&tree_node);
        }
        return children;
    } (childnames);
}

// Breadth first search for a name
optional<Tree*> Tree::BFirstSearch(const string_view& name) {
    if (_name == name) {
        // Found it! XD
        return optional<Tree*> {this};
    }
    // Search the immediate children (but not in depth)
    for (const auto& child: _children) {
        if (child->Name() == name) {
            // Found it!
            return optional<Tree*> {child};
        }
    }
    // Did not find it among the children, start searching the childrens' children
    for (const auto& child: _children) {
        auto maybeTreeNode = child->BFirstSearch(name);
        if (maybeTreeNode) {
            // Found it!
            return *maybeTreeNode; // is a Tree* after picking out the value with *
        }
    }
    // Found nothing :(
    return nullopt;
}

// Depth first search for a name
optional<Tree*> Tree::DFirstSearch(const string_view& name) {
    if (_name == name) {
        // Found it! XD
        return optional<Tree*> {this};
    }
    for (const auto& child: _children) {
        if (child->Name() == name) {
            // Found it!
            return optional<Tree*> {child};
        } else {
            // Search those sub-children, recursively!
            auto maybeTreeNode = child->DFirstSearch(name);
            if (maybeTreeNode) {
                // Found it!
                return *maybeTreeNode; // is a Tree* after picking out the value with *
            }
        }
    }
    // Found nothing :(
    return nullopt;
}

// Add a new child
inline void Tree::AddChild(Tree* child) {
    _children.push_back(child);
}

// Add a new child and return the new Tree node
Tree Tree::AddChild(const string_view& name) {
    auto tree_node = Tree(name);
    _children.push_back(&tree_node);
    return tree_node;
}

// Print the tree with one-space indentation per level, depth first
const string Tree::str(unsigned indentation_level) {
    stringstream s;
    for (unsigned i=0; i < indentation_level; i++) {
        s << " ";
    }
    s << _name << endl;
    for (const auto& child: _children) {
        s << child->str(indentation_level + 1) << endl;
    }
    return s.str();
}

inline const string_view& Tree::Name() {
    return _name;
}
