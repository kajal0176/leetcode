class Solution {
public:
int solve(vector<vector<int>>&arr,int i,int j){
    priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>>pq;
    int n=arr.size();
    int m=arr[0].size();
   int dx[4]={1,-1,0,0};
   int dy[4]={0,0,1,-1};
  pq.push({{0,0},{0,0}});
  vector<vector<int>>vis(n,vector<int>(m,0));
  vis[0][0]=1;
  while(!pq.empty()){
   auto it=pq.top();
   int time=it.first.first;
   int ad=it.first.second;
   int x=it.second.first;
   int y=it.second.second;
   pq.pop();
   if(x==n-1&&y==m-1)return time;
   for(int i=0;i<4;i++){
    int nx=dx[i]+x;
    int ny=dy[i]+y;
    if(nx>=0&&ny>=0&&nx<n&&ny<m&&!vis[nx][ny]){
        int wt=max(arr[nx][ny]-time,0);
        if(ad%2){
            wt+=2;
        }
        else wt+=1;
        pq.push({{time+wt,ad+1},{nx,ny}});
        vis[nx][ny]=1;
    }
   }
  }
  return -1;
} 
    int minTimeToReach(vector<vector<int>>& moveTime) {
        return solve(moveTime,0,0);
    }
};