#include <iostream>
using namespace std;
int findDuplicate(int arr[], int n)
{
    int slow = arr[0];
    int fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main()
{
    int arr[100001], n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Duplicate number is: " << findDuplicate(arr, n) << endl;
    return 0;
}