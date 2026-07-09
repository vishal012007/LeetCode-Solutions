#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
      
        vector<int> groupId(n, 0);
        int current_group = 0;
        
        
        for (int i = 1; i < n; i++) {
            
            if (nums[i] - nums[i - 1] > maxDiff) {
                current_group++;
            }
            
            groupId[i] = current_group;
        }
        
        
        vector<bool> answer;
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            if (groupId[u] == groupId[v]) {
                answer.push_back(true);
            } else {
                answer.push_back(false);
            }
        }
        
        return answer;
    }
};