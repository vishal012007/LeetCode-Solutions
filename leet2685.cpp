#include <vector>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build the Adjacency List
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int complete_groups = 0;
        
        // Step 2: Loop through every person
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int v_count = 0;   // People in the current group
                int degree_sum = 0; // Total friendships in the current group
                
                // Step 3: Run DFS to collect group stats
                dfs(i, adj, visited, v_count, degree_sum);
                
                // Step 4: The Perfect Math Check
                if (degree_sum == v_count * (v_count - 1)) {
                    complete_groups++;
                }
            }
        }
        
        return complete_groups;
    }
    
private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& v_count, int& degree_sum) {
        visited[node] = true;
        v_count++; // Found a new person in this group
        degree_sum += adj[node].size(); // Add all their direct friends to the sum
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, v_count, degree_sum);
            }
        }
    }
};