#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string addStrings(const string &a, const string &b) {
    string result = "";
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Handle base cases
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    // Store Fibonacci numbers as strings to handle very large values
    vector<string> fib(n + 1);
    fib[0] = "0";
    fib[1] = "1";

    for (int i = 2; i <= n; i++) {
        fib[i] = addStrings(fib[i - 1], fib[i - 2]);
    }

    cout << fib[n] << endl;
    return 0;
}
