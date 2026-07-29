#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    const long long LIMIT = 1000001LL;

    long long countWays(const vector<int>& cnt, int total) {
        long long res = 1;
        int remaining = total;
        for (int i = 0; i < 26; i++) {
            int c = cnt[i];
            for (int j = 1; j <= c; j++) {
                res = res * (remaining - c + j) / j;
                if (res > LIMIT) return LIMIT;
            }
            remaining -= c;
        }
        return res;
    }

public:
    string smallestPalindrome(string s, long long k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> half(26, 0);
        int len = 0;
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
            if (freq[i] % 2 == 1) {
                mid = string(1, 'a' + i);
            }
        }

        if (countWays(half, len) < k) {
            return "";
        }

        string left = "";
        for (int pos = 0; pos < len; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0) continue;
                half[ch]--;
                long long ways = countWays(half, len - pos - 1);
                if (ways >= k) {
                    left += (char)('a' + ch);
                    break;
                }
                k -= ways;
                half[ch]++;
            }
        }

        string rev_left = left;
        reverse(rev_left.begin(), rev_left.end());
        return left + mid + rev_left;
    }
};

int main() {
    Solution solution;
    
    string s1 = "abba";
    long long k1 = 2;
    cout << solution.smallestPalindrome(s1, k1) << endl;
    
    string s2 = "bacab";
    long long k2 = 1;
    cout << solution.smallestPalindrome(s2, k2) << endl;
    
    return 0;
}