class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int c=image[sr][sc];
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[sr][sc]=1;
        q.push({sr,sc});
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        image[sr][sc]=color;
        while(!q.empty()){
            auto it=q.front();
            int x=it.first;
            int y=it.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<n&&ny<m&&nx>=0&&ny>=0&&image[nx][ny]==c&&!vis[nx][ny]){
                    image[nx][ny]=color;
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        return image;
    }
};