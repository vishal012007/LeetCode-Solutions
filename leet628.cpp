#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Sort the array from smallest to largest
        sort(nums.begin(), nums.end());
        
        // Step 2: Calculate Case 1 (The 3 biggest numbers at the end)
        int case1 = nums[n-1] * nums[n-2] * nums[n-3];
        
        // Step 3: Calculate Case 2 (The 2 smallest negatives * the 1 biggest positive)
        int case2 = nums[0] * nums[1] * nums[n-1];
        
        // Step 4: Return the maximum of both cases
        return max(case1, case2);
    }
};