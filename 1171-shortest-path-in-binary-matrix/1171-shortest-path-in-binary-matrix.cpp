class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        if(grid[0][0]==1){
            return -1;
        }
        q.push({{0,0},1});
        int ans=INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
          auto t=q.front();
          q.pop();
          int x=t.first.first;
          int y=t.first.second;
          if(x==n-1&&y==m-1){
            ans=min(ans,t.second);
          }
          for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nx=i+x;
                int ny=y+j;
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&grid[nx][ny]==0){
                     q.push({{nx,ny},t.second+1});
                     grid[nx][ny]=1;
                }
            }
          }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};