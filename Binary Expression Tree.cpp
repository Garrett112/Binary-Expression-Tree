#include "binaryExpressionTree.h"
#include <fstream>

using namespace std;

int main()
{
    binaryExpressionTree tree;
    ifstream file("Text.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
        tree.buildExpressionTree(line);
        cout << tree.evaluateExpressionTree() << endl;
        tree.clearTree();
        cout << endl;
    }
}

