#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> getPermutations(string s) {
    vector<string> result;
    sort(s.begin(), s.end());
    do {
        result.push_back(s); 
    } while (next_permutation(s.begin(), s.end())); 
    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    vector<string> permutations = getPermutations(s);
    cout << "Unique permutations:\n";
    for (string p : permutations) {
        cout << p << endl;
    }
    return 0;
}