#include "binaryExpressionTree.h"
#include <fstream>

using namespace std;

int main()
{
    binaryExpressionTree tree;
    ifstream file("RpnData.txt");
    string line;
    while (getline(file, line)) {
        tree.buildExpressionTree(line);
        tree.evaluateExpressionTree();
        tree.clearTree();
    }
}

