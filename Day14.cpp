#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Helper function: count substrings with at most k distinct characters
int atMostKDistinct(const string& s, int k) {
    int n = s.size();
    vector<int> freq(26, 0);
    int left = 0, right = 0, count = 0, distinct = 0;
    while (right < n) {
        if (freq[s[right] - 'a'] == 0) distinct++;
        freq[s[right] - 'a']++;
        while (distinct > k) {
            freq[s[left] - 'a']--;
            if (freq[s[left] - 'a'] == 0) distinct--;
            left++;
        }
        count += right - left + 1;
        right++;
    }
    return count;
}

int countExactlyKDistinct(const string& s, int k) {
    if (k == 0 || k > s.size()) return 0;
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main() {
    string s;
    int k;
    cout << "Enter string and k: ";
    cin >> s >> k;
    cout << countExactlyKDistinct(s, k) << endl;
    return 0;
}