#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();       // Total rows
        int n = grid[0].size();    // Total columns
        int total_elements = m * n;
        
        // If k is larger than the total elements, it just loops around.
        // E.g., if total elements = 9, shifting by 10 is the same as shifting by 1.
        k = k % total_elements;
        
        // Create an empty new grid of the same size, filled with 0s
        vector<vector<int>> newGrid(m, vector<int>(n, 0));
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                
                // Step 1: Find its current 1D position
                int current_1d_pos = (r * n) + c;
                
                // Step 2: Calculate its new 1D position after jumping k steps
                int new_1d_pos = (current_1d_pos + k) % total_elements;
                
                // Step 3: Convert that 1D position back into 2D (row and column)
                int new_r = new_1d_pos / n;
                int new_c = new_1d_pos % n;
                
                // Step 4: Place the element in its new home!
                newGrid[new_r][new_c] = grid[r][c];
            }
        }
        
        return newGrid;
    }
};