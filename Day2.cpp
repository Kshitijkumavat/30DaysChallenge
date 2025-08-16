#include<iostream>
using namespace std;
int missNum(int arr[], int n) {
    long long total=(long long)n * (n + 1) / 2;
    long long sum = 0;
    for (int i = 0; i < n-1; i++) {
        sum += arr[i];
    }
    return total - sum;
}

int main() {
    int arr[100],n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n-1; i++) {
        cin >> arr[i];
    }
    cout << "Missing number is: " << missNum(arr, n) << endl;
    return 0;
}