#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
     
        int maxVal = 0;
        for (int x : nums) {
            if (x > maxVal) maxVal = x;
        }
        
        
        vector<long long> count(maxVal + 1, 0);
        for (int x : nums) {
            count[x]++;
        }
        
       
        vector<long long> gcdCount(maxVal + 1, 0);
        
       
        for (int i = maxVal; i >= 1; i--) {
            long long total_multiples = 0;
            
           
            for (int j = i; j <= maxVal; j += i) {
                total_multiples += count[j];
            }
            
           
            long long total_pairs = (total_multiples * (total_multiples - 1)) / 2;
            
            
            for (int j = 2 * i; j <= maxVal; j += i) {
                total_pairs -= gcdCount[j];
            }
            
            gcdCount[i] = total_pairs;
        }
        
       
        vector<long long> prefixSum(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; i++) {
            prefixSum[i] = prefixSum[i - 1] + gcdCount[i];
        }
        
        
        vector<int> ans;
        for (long long q : queries) {
           
            auto it = upper_bound(prefixSum.begin(), prefixSum.end(), q);
            int gcd_value = distance(prefixSum.begin(), it);
            ans.push_back(gcd_value);
        }
        
        return ans;
    }
};