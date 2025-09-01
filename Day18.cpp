#include <iostream>
#include <cmath>
using namespace std;

int countDivisors(int N) {
    int count = 0;
    for (int i = 1; i <= sqrt(N); ++i) {
        if (N % i == 0) {
            if (i == N / i)
                count += 1;
            else
                count += 2;
        }
    }
    return count;
}

int main() {
    int N;
    cout << "Enter an integer: ";
    cin >> N;
    cout << "Number of divisors: " << countDivisors(N) << endl;
    return 0;
}