// 1. Top-Down 
class Solution {
public:

    int f(int i, int j, vector<vector<int>>& grid,
          vector<vector<int>>& dp) {

        if(i == 0 && j == 0)
            return dp[0][0] = grid[0][0];

        if(dp[i][j] != -1)
            return dp[i][j];

        int fromUp = (i - 1 >= 0)
                    ? f(i - 1, j, grid, dp)
                    : INT_MAX;

        int fromLeft = (j - 1 >= 0)
                    ? f(i, j - 1, grid, dp)
                    : INT_MAX;

        return dp[i][j] =
            grid[i][j] + min(fromUp, fromLeft);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(
            m, vector<int>(n, -1)
        );

        return f(m - 1, n - 1, grid, dp);
    }
};

// 2. BOTTOM-UP
// class Solution{
//     public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<int> dp(n,-1);

//         for(int i = 0;i <m;i++){
//             vector<int> temp(n,-1);
//             for(int j = 0;j<n;j++){
//                 if(i==0&&j==0) {temp[0] = grid[0][0];continue;}

//                 int fromUp = (i-1>=0)? dp[j] : INT_MAX;
//                 int fromLeft = (j-1>=0) ? temp[j-1] : INT_MAX;

//                 temp[j] = grid[i][j] + min(fromUp,fromLeft);
//             }
//             dp = temp;
//         }
//         return dp[n-1];
//     }
// };

// 3 . Dijkstra
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        
//         dist[0][0] = grid[0][0];

//         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

//         pq.push({grid[0][0],{0,0}});

//         vector<int> dr = {1,0};
//         vector<int> dc = {0,1};

//         while(!pq.empty()){
//             int dis = pq.top().first;
//             int r = pq.top().second.first;
//             int c = pq.top().second.second;
//             pq.pop();
//             if(dis>dist[r][c]) continue;

//             for(int i = 0;i < 2;i++){
//                 int nr = r + dr[i];
//                 int nc = c + dc[i];
//                 if(nr>=0&&nr<m && nc>=0&&nc<n && dis+grid[nr][nc]<dist[nr][nc]){
//                     dist[nr][nc] = dis + grid[nr][nc];
//                     pq.push({dist[nr][nc],{nr,nc}});
//                 }
//             }
//         }
//         return dist[m-1][n-1];
//     }
// };