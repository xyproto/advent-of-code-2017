#include "test.h"
#include "util.h"
#include "stringutils.h"
#include "tree.h"

// Return the child-names of a node, read from a line of text
inline const vector<string> children(const string line) {
    return words(split(line, "->").second, ',');
}

// Return the name of a node, read from a line of text
inline const string name(const string line) {
    return trim(split(line, "->").first);
}

// Return the weight of a node, read from a line of text
inline const unsigned long weight(const string line) {
    return to_unsigned_long(between(line, '(', ')'));
}

Tree* build_tree(vector<string> lines) {
    vector<Tree*> all_nodes {}; // all nodes
    for (const auto &line: lines) {
        // Create a node
        string name = words(line)[0];
        auto node = Tree(name);
        all_nodes.push_back(&node);

        cout << name << " weight " << weight(line) << endl;

        // TODO: for each "other" word, find that node in all_nodes and push this node as a child.
        auto other_words = children(line);
    }
    // TODO: Return the root node
    return nullptr;
}

int main() {
    cout << "--- input.txt ---" << endl;
    build_tree(readlines("input.txt"));

    cout << "--- input2.txt ---" << endl;
    build_tree(readlines("input2.txt"));
}
