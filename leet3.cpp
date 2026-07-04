#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int L = 0;
        int R = 0;
        int max_len = 0;

        while (R < s.length()) {
            if (window.find(s[R]) == window.end()) {
                window.insert(s[R]);
                max_len = max(max_len, R - L + 1);
                R++;
            } else {
                window.erase(s[L]);
                L++;
            }
        }

        return max_len;
    }
};

int main()
{
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Answer = " << obj.lengthOfLongestSubstring(s);

    return 0;
}