#include <vector>
#include <algorithm> // For min and max

using namespace std;

class Solution {
public:
    // Our classic GCD finding machine
    int findGCD(int a, int b) {
        while (b != 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        // Step 1: Assume the first number is both the smallest and biggest for now
        int smallest = nums[0];
        int biggest = nums[0];
        
        // Step 2: Loop through the array to find the actual smallest and biggest
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < smallest) {
                smallest = nums[i];
            }
            if(nums[i] > biggest) {
                biggest = nums[i];
            }
        }
        
        // Step 3: Send them to our GCD machine
        return findGCD(smallest, biggest);
    }
};