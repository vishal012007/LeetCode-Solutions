#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> unique_nums;
        bool seen[2048] = {false};
        
        // 1. Get all unique numbers to avoid redundant work
        for(int x : nums) {
            if(!seen[x]) {
                seen[x] = true;
                unique_nums.push_back(x);
            }
        }
        
        // 2. Find all possible XOR results of two numbers
        bool pairs[2048] = {false};
        for(int i = 0; i < unique_nums.size(); ++i) {
            for(int j = i; j < unique_nums.size(); ++j) {
                pairs[unique_nums[i] ^ unique_nums[j]] = true;
            }
        }
        
        // 3. Find all possible XOR results of three numbers
        bool triplets[2048] = {false};
        int count = 0;
        
        for(int p = 0; p < 2048; ++p) {
            if(pairs[p]) {
                for(int z : unique_nums) {
                    if(!triplets[p ^ z]) {
                        triplets[p ^ z] = true;
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 3};
    cout << "Output 1: " << solution.uniqueXorTriplets(nums1) << endl; // Expected: 2
    
    // Test case 2
    vector<int> nums2 = {6, 7, 8, 9};
    cout << "Output 2: " << solution.uniqueXorTriplets(nums2) << endl; // Expected: 4
    
    return 0;
}