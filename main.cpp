#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maximalRectangleArea(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    
    vector<int> heights(m, 0);
    int maxArea = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0)
                heights[j] = 0;
            else
                heights[j] += 1;
        }
        
        stack<int> stk;
        for (int j = 0; j <= m; ++j) {
            while (!stk.empty() && (j == m || heights[j] <= heights[stk.top()])) {
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? j : (j - stk.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            stk.push(j);
        }
    }
    
    return maxArea;
}

int main() {
    int n = 4, m = 4;
    vector<vector<int>> matrix = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };
    
    int result = maximalRectangleArea(matrix);
    cout << "Maximal Rectangle Area: " << result << endl;
    
    return 0;
}
