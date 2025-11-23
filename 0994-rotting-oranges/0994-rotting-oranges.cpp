class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int totalOrange=0;
        int rottenOrange=0;
        int m=grid.size();
        int n=grid[0].size();
       queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                
                    q.push({i,j});
                }
                if(grid[i][j]!=0){
                    totalOrange++;
                }
            }
        }
       
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int time=0;
        while(!q.empty()){
            int k=q.size();
            for(int t=0;t<k;t++){
            auto node=q.front();
            int x=node.first;
            int y=node.second;
            q.pop();
            rottenOrange++;
          for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(nx>=0&&ny>=0&&nx<m&&ny<n&&grid[nx][ny]==1){
                grid[nx][ny]=2;
                q.push({nx,ny});
            }
          }
        }
          if(q.size()>0)
          time++;
        }
        if(rottenOrange==totalOrange){
            return time;
        }
        return -1;
    }
};