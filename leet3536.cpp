#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0;
        int max2 = 0;
        
        while (n > 0) {
            int digit = n % 10;
            if (digit > max1) {
                max2 = max1;
                max1 = digit;
            } else if (digit > max2) {
                max2 = digit;
            }
            n /= 10;
        }
        
        return max1 * max2;
    }
};

int main() {
    Solution solution;
    
    int n1 = 31;
    cout << solution.maxProduct(n1) << endl;
    
    int n2 = 22;
    cout << solution.maxProduct(n2) << endl;
    
    int n3 = 124;
    cout << solution.maxProduct(n3) << endl;
    
    return 0;
}