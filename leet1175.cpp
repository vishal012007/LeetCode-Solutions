#include <iostream>

using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if(n < 2)
            return false;

        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0)
                return false;
        }
        return true;
    }

    long long factorial(int n) {
        if(n == 0 || n == 1)
            return 1;
        return n * factorial(n - 1) % 1000000007;
    }

    int numPrimeArrangements(int n) {
        int i, count = 0;
        for(i = 1; i <= n; i++) {
            if(isPrime(i))
                count++;
        }
        return factorial(count) * factorial(n - count) % 1000000007;
    }
};

int main() {
    Solution sol;
    
    // Testing with an example (n = 5)
    int n = 5;
    int result = sol.numPrimeArrangements(n);
    
    cout << "Total Prime Arrangements for n = " << n << " is: " << result << endl;
    
    // You can test another input
    n = 100;
    result = sol.numPrimeArrangements(n);
    cout << "Total Prime Arrangements for n = " << n << " is: " << result << endl;
    
    return 0;
}