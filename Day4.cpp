#include<iostream>
using namespace std;

int Space(int gap){
    if(gap<=1){
        return 0;
    }
    return (gap/2)+(gap%2);
}

void merge(int arr1[],int arr2[], int m, int n){
    int gap = Space(m+n);
    while(gap>0){
        int i,j;
        for (i=0;i+gap<m;i++){
            if(arr1[i]>arr1[i+gap]){
                swap(arr1[i],arr1[i+gap]);
            }
        }
        for(j=gap>m? gap-m : 0; i<m && j<n; i++, j++){
            if(arr1[i]>arr2[j]){
                swap(arr1[i], arr2[j]);
            }
        }
        if(j<n){
            for(j=0;j+gap<n;j++){
                if(arr2[j]>arr2[j+gap]){
                    swap(arr2[j], arr2[j+gap]);
                }
            }
        }
        gap = Space(gap);
    }
}

int main(){
    int arr1[100001], arr2[100001];
    int m, n;
    cout << "Enter the number of elements in first array: ";
    cin >> m;
    cout << "Enter the elements of first array: ";
    for(int i=0;i<m;i++){
        cin >> arr1[i];
    }
    cout << "Enter the number of elements in second array: ";
    cin >> n;
    cout << "Enter the elements of second array: ";
    for(int i=0;i<n;i++){
        cin >> arr2[i];
    }
    merge(arr1, arr2, m, n);
    cout<<"arr1: ";
    for(int i=0;i<m;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<"\narr2: ";
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }
    return 0;
}