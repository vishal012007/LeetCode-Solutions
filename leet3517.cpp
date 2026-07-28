#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);

        // Count frequency of each character
        for (char c : s) {
            count[c - 'a']++;
        }

        string left = "";
        string mid = "";

        // Build left half and middle character
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                mid = string(1, i + 'a');
            }

            left += string(count[i] / 2, i + 'a');
        }

        // Create right half
        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};

int main() {
    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Smallest Palindrome: " << obj.smallestPalindrome(s);

    return 0;
}