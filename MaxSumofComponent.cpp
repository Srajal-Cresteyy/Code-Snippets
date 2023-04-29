class Solution {
public:
    int delr[4]={-1,0,1,0};
    int delc[4]={0,1,0,-1};
    
    bool checkValidCell(int n,int m,int r,int c,vector<vector<int>> &grid){
        return nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc];
    }
    int bfs(int sr,int sc,vector<vector<int>> &grid,vector<vector<int>> &visited){
        
        int n=grid.size(),m=grid[0].size();
        visited[sr][sc]=1;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int sum=0;
        
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(checkValidCell(n,m,nr,nc,grid) and !visited[nr][nc]){
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
            sum+=grid[r][c];
        }
        
        return sum;
    }
    
    
    int countComponentSum(vector<vector<int>>& grid,int n,int m) {
        int ans=INT_MIN;
        vector<vector<int>> visited(n,vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!visited[i][j] and grid[i][j]){
                    int val=bfs(i,j,grid,visited);
                    ans=max(ans,val);
                }
        if(ans==INT_MIN) return 0;
        return ans;
    }
};
