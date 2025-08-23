#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

string reverseWords(string s) {
    vector<string> words;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    string result;
    for (int i = words.size() - 1; i >= 0; --i) {
        result += words[i];
        if (i != 0) result += " ";
    }
    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << "Output: \"" << reverseWords(s) << "\"" << endl;
    return 0;
}