#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }
};

TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

int main() {
    cout << "Enter tree in level order (use 'null' for empty):\n";
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<string> nodes;
    string token;
    while (ss >> token) nodes.push_back(token);

    TreeNode* root = buildTree(nodes);

    int pVal, qVal;
    cout << "Enter value of node p: ";
    cin >> pVal;
    cout << "Enter value of node q: ";
    cin >> qVal;

    TreeNode* p = findNode(root, pVal);
    TreeNode* q = findNode(root, qVal);

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca)
        cout << "LCA of " << pVal << " and " << qVal << " is: " << lca->val << endl;
    else
        cout << "LCA not found (check inputs)" << endl;

    return 0;
}
