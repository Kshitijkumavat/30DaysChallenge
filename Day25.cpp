#include <iostream>
#include <climits>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}

TreeNode* buildTree(int n) {
    if (n == 0) return nullptr;
    
    cout << "Enter values in level order (-1 for null):\n";
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);
    int count = 1;

    while (!q.empty() && count < n) {
        TreeNode* curr = q.front();
        q.pop();

        cin >> val;
        count++;
        if (val != -1) {
            curr->left = new TreeNode(val);
            q.push(curr->left);
        }

        if (count >= n) break;

        cin >> val;
        count++;
        if (val != -1) {
            curr->right = new TreeNode(val);
            q.push(curr->right);
        }
    }
    return root;
}

int main() {
    int n;
    cout << "Enter number of nodes (including nulls as -1): ";
    cin >> n;

    TreeNode* root = buildTree(n);
    cout << (isValidBST(root) ? "true" : "false") << endl;
    return 0;
}
