#include "test.h"

int main() {
    cout << "hi" << endl;

    auto root = Tree("root node");
    root->AddChild("Bob");
    auto alice = root->AddChild("Alice");
    alice->AddChild("Roger");
    alice->AddChild("Malfoy");
    alice->AddChild("Gregory");
    alice->AddChild("Krang");
    alice->AddChild("Lucious");
    alice->AddChild("Max");

}
