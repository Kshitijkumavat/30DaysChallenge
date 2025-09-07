#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstElementKTimes(vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    for (int num : arr) {
        freq[num]++;
    }

    for (int num : arr) {
        if (freq[num] == k) {
            return num;
        }
    }
    return -1;
}

int main() {
    int n, k;
    cout << "Enter number of elements in array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    cout << firstElementKTimes(arr, k) << endl;

    return 0;
}
