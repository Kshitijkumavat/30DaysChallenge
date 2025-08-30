#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> lastIndex;
    int maxLen = 0, start = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (lastIndex.count(s[i]) && lastIndex[s[i]] >= start) {
            start = lastIndex[s[i]] + 1;
        }
        lastIndex[s[i]] = i;
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
}

int main() {
    string S;
    cout << "Enter a string S: ";
    cin >> S;
    cout << lengthOfLongestSubstring(S) << endl;
    return 0;
}