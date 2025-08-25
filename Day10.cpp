#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string s : strs) {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        groups[sorted].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& pair : groups) {
        result.push_back(pair.second);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    vector<string> strs(n);
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    vector<vector<string>> grouped = groupAnagrams(strs);

    cout << "Grouped anagrams:\n";
    for (auto group : grouped) {
        cout << "[ ";
        for (auto word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}