#include<iostream>
using namespace std;

void leaders(int arr[], int n) {
    int result[1000000],max= arr[n-1],count=0;
    result[count++]=max;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>max){
            max=arr[i];
            result[count++]=max;
        }
    }
    for(int i=count-1;i>=0;i--){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int arr[1000000], n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Leaders in the array are: ";
    leaders(arr, n);
    return 0;
}
