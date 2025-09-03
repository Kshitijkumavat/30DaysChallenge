#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int>& st, int element) {
    if (st.empty() || st.top() <= element) {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();
    insertSorted(st, element);
    st.push(temp);
}

void sortStack(stack<int>& st) {
    if (st.empty()) return;

    int temp = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, temp);
}

void printStack(stack<int> st) {
    cout << "[ ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "]" << endl;
}

int main() {
    stack<int> st;
    int n, value;

    cout << "Enter number of elements in stack: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        st.push(value);  
    }

    sortStack(st);

    cout << "Sorted stack (smallest at top): ";
    printStack(st);

    return 0;
}
