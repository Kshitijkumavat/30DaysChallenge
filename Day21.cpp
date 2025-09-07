#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void insertAtBottom(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(topElement);
}

void reverseStack(stack<int> &st) {
    if (st.empty()) return;
    int topElement = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElement);
}

void printStack(stack<int> st) {
    vector<int> temp;
    while (!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }
    cout << "[ ";
    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << temp[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    stack<int> st;
    int n;
    cout << "Enter number of elements in stack: ";
    cin >> n;

    cout << "Enter elements : ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    cout << "Original stack : ";
    printStack(st);

    reverseStack(st);

    cout << "Reversed stack : ";
    printStack(st);

    return 0;
}
