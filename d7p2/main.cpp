#include "stringutils.h"
#include "test.h"
#include "tree.h"
#include "util.h"

// Return the child-names of a node, read from a line of text
inline const vector<string> children(const string line)
{
    return words(split(line, "->").second, ',');
}

// Return the name of a node, read from a line of text
inline const string name(const string line) { return trim(split(line, "->").first); }

// Return the weight of a node, read from a line of text
inline unsigned long weight(const string line)
{
    return to_unsigned_long(between(line, '(', ')'));
}

// Find the top word in the tree, not by building the actual tree,
// but by keeping track of which words are pointing to other words,
// but are not being pointed to by any other word.
// Returns an empty string if no top words were found.
// If several top words are found, return the first one.
const string top_word(vector<string> lines)
{
    vector<string> pointed_to{}; // words that have been pointed too
    vector<string> pointing{}; // words that are pointing to other words
    vector<string> all_words{}; // all the words
    // Fill the vectors
    for (const auto& line : lines) {
        const auto word = words(line)[0];
        all_words.push_back(word);
        const auto child_names = children(line);
        if (child_names.size() > 0) {
            // This word is pointing at other words
            pointing.push_back(word);
        }
        for (const auto& child_name : child_names) {
            // Add the word to the list of words that has been pointed too
            pointed_to.push_back(child_name);
        }
    }
    // Top words are not pointed to, but pointing
    vector<string> top_words{};
    for (const auto& word : all_words) {
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
Tree build_tree(vector<string> lines)
{
    using std::cerr;
    using std::endl;
    if (lines.size() == 0) {
        cerr << "GOT 0 LINES WHEN BUILDING A TREE!" << endl;
        exit(EXIT_FAILURE);
    }

    auto tree = Tree(); // all nodes, in a Tree

    // Find the name of the root node (provided the given data is OK)
    string root_name = top_word(lines);
    auto root = make_shared<Node>(root_name, 0);
    tree.SetRoot(root);

    // Set the weight for the root node
    for (const auto& line : lines) {
        if (line.size() == 0) {
            // Skip this line
            continue;
        }
        // Create a node
        string name = words(line)[0];
        cout << "NAME: " << name << endl;
        if (name == root_name) {
            root->SetWeight(weight(line));
            //} else {
            //    tree.Add(make_shared<Node>(name, weight(line)));
        }
    }
    cout << "ROOT NAME: " << root->Name() << endl;
    cout << "ROOT WEIGHT: " << root->Weight() << endl;

    // TODO: All of the code below is not great, re-read the task and re-write

    //// Push all children
    // for (const auto& line : lines) {
    //    auto parent_name = words(line)[0];
    //    auto child_names = children(line);

    //    // For each parent and list of children, add parents and children to the tree
    //    if (!tree.Has(parent_name)) {
    //        tree.Add(make_shared<Node>(parent_name, weight(line)));
    //    }

    //    for (const auto& child_name : child_names) {
    //        if (!tree.Has(child_name)) {
    //            tree.Add(make_shared<Node>(parent_name, weight(line)));
    //        }
    //        cout << "CHILD NAME: " << child_name << endl;
    //        auto root = tree.Root();
    //        cout << "ROOT NAME: " << root->Name() << endl;
    //        cout << "ROOT WEIGHT: " << root->Weight() << endl;
    //        auto found_child = root->BFind(child_name);
    //        // optional<shared_ptr<Node>> found_child = tree.Root()->BFind(child_name);
    //        cout << "A2" << endl;
    //        auto found_parent = tree.Root()->BFind(parent_name);
    //        cout << "A3" << endl;
    //        if (found_child && found_parent) {
    //            cout << "B1" << endl;
    //            // shared_ptr<Node> child_node = *found_child;
    //            cout << "B2" << endl;
    //            // shared_ptr<Node> parent_node = *found_parent;
    //            cout << "B3" << endl;
    //            // parent_node->AddChild(child_node);
    //            cout << "B4" << endl;
    //        } else {
    //            cout << "ERROR: could not find one of these: " << child_name << ", " <<
    //            parent_name
    //                 << "!" << endl;
    //        }
    //    }
    //}

    // cout << "B" << endl;

    //// Find the root node
    // auto found_root = tree.Root()->BFind(root_name);
    // if (found_root) {
    //    auto root_node = found_root.value();
    //    tree.SetRoot(root_node);
    //    return tree;
    //} else {
    //    cout << "ERROR: could not find this: " << root_name << "!" << endl;
    //}

    // Return what we've got
    return tree;
}

int main()
{
    cout << "---input.txt ---" << endl;
    auto tree1 = build_tree(readlines("input.txt"));
    cout << tree1.str() << endl;

    // cout << "--- input2.txt ---" << endl;
    // auto tree2 = build_tree(readlines("input2.txt"));
    // cout << tree2.str() << endl;
}
