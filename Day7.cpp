#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of bars: ";
    cin >> n;
    int height[200001];
    cout << "Enter the heights of the bars: ";
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }
    if(n < 3) {
        cout << "Water trapped: 0" << endl;
        return 0;
    }
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0, water = 0;
    while(left < right) {
        if(height[left] < height[right]) {
            if(height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];
            left++;
        } else {
            if(height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];
            right--;
        }
    }
    cout << "Water trapped: " << water << endl;
    return 0;
}