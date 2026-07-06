#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        // Step 1: The Magic Sorting Rule
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; 
            }
            return a[0] < b[0];     
        });
        
        int useful_count = 0;
        int max_end = -1;
        
        // Step 2: The Beach Walk
        for (auto& interval : intervals) {
            int current_end = interval[1];
            
            if (current_end > max_end) {
                useful_count++;
                max_end = current_end;
            }
        }
        
        return useful_count;
    }
};