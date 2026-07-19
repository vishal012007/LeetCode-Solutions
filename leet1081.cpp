#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        // To store the last index of each of the 26 letters
        vector<int> lastIndex(26, 0);
        
        // To keep track if a letter is currently in our final answer
        vector<bool> alreadyInString(26, false);
        
        string result = ""; // This will act as our Stack
        
        // Step 1: Find the LAST appearance of every letter
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i; 
        }
        
        // Step 2: Build the perfect string
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            
            // If we already picked this letter, skip it!
            if (alreadyInString[curr - 'a'] == true) {
                continue;
            }
            
            // THE MAGIC TRICK (Kick out bigger letters if they appear later)
            while (result.length() > 0 && curr < result.back() && lastIndex[result.back() - 'a'] > i) {
                
                // Mark the kicked-out letter as "not in string anymore"
                alreadyInString[result.back() - 'a'] = false;
                
                // Kick it out of our result
                result.pop_back();
            }
            
            // Add the current letter to our result
            result.push_back(curr);
            alreadyInString[curr - 'a'] = true;
        }
        
        return result;
    }
};