#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;

        // Find the number of bits in 'n'
        int bits = 0;
        int temp = n;
        while (temp > 0) {
            bits++;
            temp >>= 1;
        }

        return 1 << bits;
    }
};

int main() {
    // 1. Create an instance of the Solution class
    Solution solution;
    
    // 2. Define a test case 
    vector<int> nums = {1, 2, 3}; 
    
    
    int result = solution.uniqueXorTriplets(nums);
    cout << "Output: " << result << endl;

    return 0;
}