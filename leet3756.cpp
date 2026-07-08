#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Just changed the function name here to sumAndMultiply
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;
        
        // Step 1: Filter out non-zero digits
        vector<int> A;
        for (char c : s) {
            if (c != '0') {
                A.push_back(c - '0');
            }
        }
        
        int n = A.size();
        
        // Step 2: Index Mapping Arrays
        vector<int> next_nonzero(m, n);
        int curr_next = n;
        for (int i = m - 1; i >= 0; i--) {
            if (s[i] != '0') curr_next--;
            next_nonzero[i] = curr_next;
        }
        
        vector<int> prev_nonzero(m, -1);
        int curr_prev = -1;
        for (int i = 0; i < m; i++) {
            if (s[i] != '0') curr_prev++;
            prev_nonzero[i] = curr_prev;
        }
        
        // Step 3: Precompute Prefixes and Powers of 10
        vector<long long> pref_sum(n + 1, 0);
        vector<long long> pref_x(n + 1, 0);
        vector<long long> power10(n + 1, 1);
        
        for (int i = 0; i < n; i++) {
            pref_sum[i + 1] = pref_sum[i] + A[i];
            pref_x[i + 1] = (pref_x[i] * 10 + A[i]) % MOD;
            power10[i + 1] = (power10[i] * 10) % MOD;
        }
        
        // Step 4: Process Each Query in O(1)
        vector<int> answer;
        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            int L = next_nonzero[l];
            int R = prev_nonzero[r];
            
            // If there are no non-zero digits in the range
            if (L > R) {
                answer.push_back(0);
                continue;
            }
            
            // O(1) Digit Sum
            long long sum_digits = pref_sum[R + 1] - pref_sum[L];
            
            // O(1) Value of x using Modular Math
            long long x_val = (pref_x[R + 1] - (pref_x[L] * power10[R - L + 1]) % MOD + MOD) % MOD;
            
            // Final Multiplied Answer Modulo 10^9 + 7
            long long res = (x_val * (sum_digits % MOD)) % MOD;
            answer.push_back(res);
        }
        
        return answer;
    }
};