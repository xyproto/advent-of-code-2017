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

// Find the top word in the tree, not by building the actual tree,
// but by keeping track of which words are pointing to other words,
// but are not being pointed to by any other word.
// Returns an empty string if no top words were found.
// If several top words are found, return the first one.
const string top_word(vector<string> lines) {
    vector<string> pointed_to {}; // words that have been pointed too
    vector<string> pointing {}; // words that are pointing to other words
    vector<string> all_words {}; // all the words
    // Fill the vectors
    for (const auto & line: lines) {
        const auto word = words(line)[0];
        all_words.push_back(word);
        const auto child_names = children(line);
        if (child_names.size() > 0) {
            // This word is pointing at other words
            pointing.push_back(word);
        }
        for (const auto & child_name: child_names) {
            // Add the word to the list of words that has been pointed too
            pointed_to.push_back(child_name);
        }
    }
    // Top words are not pointed to, but pointing
    vector<string> top_words {};
    for (const auto & word: all_words) {
        if (has(pointing, word) && !has(pointed_to, word)) {
            top_words.push_back(word);
        }
    }
    // Return the top word, or "" if empty
    if (top_words.size() == 0) {
        return "";
    }
    return top_words[0];
}

// A tree with all the nodes and a pointer to the root node
using tree_t = pair<vector<Tree>, Tree*>;

// Return the full list of nodes, with the nodes, and a pointer to the root node
Tree build_tree(vector<string> lines) {
    auto tree = Tree(); // all nodes, in a Tree

    // Find the name of the root node (provided the given data is OK)
    string root_name = top_word(lines);

    // Push all nodes
    for (const auto & line: lines) {
        // Create a node
        string name = words(line)[0];
        auto node = new Node(name, weight(line));
        tree.Add(shared_ptr<Node> {node});
    }

    // Push all children
    for (const auto & line: lines) {
        auto parent_name = words(line)[0];
        // For each child name, find that name it in the tree, or create it, and push that node a a child
        for (const auto & child_name: children(line)) {
            optional<shared_ptr<Node>> found_child = tree.Root()->BFind(child_name);
            optional<shared_ptr<Node>> found_parent = tree.Root()->BFind(parent_name);
            if (found_child && found_parent) {
                shared_ptr<Node> child_node = *found_child;
                shared_ptr<Node> parent_node = *found_parent;
                parent_node->AddChild(child_node);
            } else {
                cout << "ERROR: could not find one of these: " << child_name << ", " << parent_name << "!" << endl;
            }
        }
    }

    // Find the root node
    optional<shared_ptr<Node>> found_root = tree.Root()->BFind(root_name);
    if (found_root) {
        shared_ptr<Node> root_node = *found_root;
        tree.SetRoot(root_node);
        return tree;
    } else {
        cout << "ERROR: could not find this: " << root_name << "!" << endl;
    }

    // Return what we've got
    return tree;
}

int main() {
    cout << "--- input.txt ---" << endl;
    auto tree1 = build_tree(readlines("input.txt"));
    cout << tree1.str() << endl;

    //cout << "--- input2.txt ---" << endl;
    //auto tree2 = build_tree(readlines("input2.txt"));
    //cout << tree2.str() << endl;
}