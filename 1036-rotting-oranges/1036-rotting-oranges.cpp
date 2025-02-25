class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int total_orange=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                total_orange++;
            }
            else if(grid[i][j]==1){
                total_orange++;
            }
            }
        }
        int ans=0;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        int cnt=0;
       while(!q.empty()){
        auto tmp=q.front();
        int x=tmp.first.first;
        int y=tmp.first.second;
        int time=tmp.second;
        ans=max(ans,time);
        q.pop();
        cnt++;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<n&&ny<m&&nx>=0&&ny>=0&&grid[nx][ny]==1){
              q.push({{nx,ny},time+1});
              grid[nx][ny]=2;
            }
        }
       }
       if(cnt==total_orange){
        return ans;
       }
       return -1;
    }
};