class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
            pq.push({0,{0,0}});
            vector<vector<int>>dis(heights.size(),vector<int>(heights[0].size(),INT_MAX));
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,-1,1};
            while(!pq.empty()){
                auto tmp=pq.top();
                pq.pop();
                int diff=tmp.first;
                int x=tmp.second.first;
                int y=tmp.second.second;
                if(x==heights.size()-1&&y==heights[0].size()-1) return diff;
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0&&ny>=0&&nx<heights.size()&&ny<heights[0].size()){
                    int t=max(diff,abs(heights[nx][ny]-heights[x][y]));
                    if(t<dis[nx][ny]){
                        dis[nx][ny]=t;
                        pq.push({t,{nx,ny}});
                    }
                }
                }
            }
            return 0;
    }
};