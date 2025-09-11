#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return NULL;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr) {

            if (i < nodes.size()) {
                if (nodes[i] != "null") {
                    curr->left = new TreeNode(stoi(nodes[i]));
                    q.push(curr->left);
                } else {
                    curr->left = NULL;
                    q.push(NULL);
                }
                i++;
            }

            if (i < nodes.size()) {
                if (nodes[i] != "null") {
                    curr->right = new TreeNode(stoi(nodes[i]));
                    q.push(curr->right);
                } else {
                    curr->right = NULL;
                    q.push(NULL);
                }
                i++;
            }
        }
    }
    return root;
}

int main() {
    cout << "Enter tree in array format :\n";
    string line;
    getline(cin, line);

    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());
    replace(line.begin(), line.end(), ',', ' ');

    stringstream ss(line);
    vector<string> nodes;
    string temp;
    while (ss >> temp) nodes.push_back(temp);

    TreeNode* root = buildTree(nodes);

    cout << (isSymmetric(root) ? "true" : "false") << endl;
    return 0;
}
