#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;
        
        for (int n : nums) {
            if (n > max1) {
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max2 = n;
            }
        }
        
        return (max1 - 1) * (max2 - 1);
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {3, 4, 5, 2};
    cout << solution.maxProduct(nums1) << endl;
    
    vector<int> nums2 = {1, 5, 4, 5};
    cout << solution.maxProduct(nums2) << endl;
    
    return 0;
}