#include<iostream>
using namespace std;
int main() {
    int arr[1000001];
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Subarrays with sum zero: [";
    bool first = true;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 0) {
                if(!first) cout << ", ";
                cout << "(" << i << ", " << j << ")";
                first = false;
            }
        }
    }
    cout << "]" << endl;
    return 0;
}