#include<iostream>
using namespace std;

void sortarr(int arr[], int n){
    int start=0,mid=0,end=n-1;
    while (mid<=end){
        if (arr[mid]==0){
            int temp=arr[start];
            arr[start]=arr[mid];
            arr[mid]=temp;
            start++;
            mid++;
        }
        else if (arr[mid]==1){
            mid++;
        }
        else{
            int temp=arr[mid];
            arr[mid]=arr[end];
            arr[end]=temp;
            end--;
        }
    }
}

int main(){
    int arr[100], n;
    cout<<"Enter number of elements:";
    cin>>n;
    cout<<"Enter elements(0,1,2):";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sortarr(arr,n);
    cout<<"Sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

