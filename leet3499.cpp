#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxActiveSections(string s) {
        // Step 1: Augment the string just like the problem said
        string t = "1" + s + "1";
        int n = t.length();
        
        vector<int> onesBlocks;  // Stores the sizes of islands
        vector<int> zerosBlocks; // Stores the sizes of lakes
        
        // Parse the string into blocks of 1s and 0s
        int i = 0;
        while (i < n) {
            int ones = 0;
            while (i < n && t[i] == '1') { ones++; i++; }
            onesBlocks.push_back(ones);
            
            int zeros = 0;
            while (i < n && t[i] == '0') { zeros++; i++; }
            if (zeros > 0) zerosBlocks.push_back(zeros);
        }
        
        // Count how many '1's we originally had in `s`
        int originalOnes = 0;
        for (char c : s) {
            if (c == '1') originalOnes++;
        }
        
        int k = zerosBlocks.size();
        
        // If there are less than 2 lakes, it means there are NO internal islands.
        // We cannot perform a trade.
        if (k <= 1) return originalOnes;
        
        // Step 2: Precalculate the biggest lakes from left to right, and right to left
        // This helps us instantly find the "other" biggest lake in O(1) time
        vector<int> prefMax(k, 0), suffMax(k, 0);
        
        prefMax[0] = zerosBlocks[0];
        for (int j = 1; j < k; j++) prefMax[j] = max(prefMax[j-1], zerosBlocks[j]);
        
        suffMax[k-1] = zerosBlocks[k-1];
        for (int j = k-2; j >= 0; j--) suffMax[j] = max(suffMax[j+1], zerosBlocks[j]);
        
        int maxProfit = 0;
        
        // Step 3: Test sinking every INTERNAL island
        // Internal islands are at index 1 to k-1
        for (int j = 1; j < k; j++) {
            
            // If we sink island 'j', it merges with lake 'j-1' and lake 'j'
            int megaLake = zerosBlocks[j-1] + onesBlocks[j] + zerosBlocks[j];
            
            // Find the biggest "other" lake that we didn't touch
            int maxOtherLake = 0;
            if (j - 2 >= 0) maxOtherLake = max(maxOtherLake, prefMax[j-2]);
            if (j + 1 < k)  maxOtherLake = max(maxOtherLake, suffMax[j+1]);
            
            // We obviously fill whichever lake is bigger!
            int bestLakeToFill = max(megaLake, maxOtherLake);
            
            // Calculate our net profit
            int profit = bestLakeToFill - onesBlocks[j];
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
        
        return originalOnes + maxProfit;
    }
};