class Solution {
public:
int res=1e9;
 int solve(vector<vector<int>>&arr,int i,int j){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    int n=arr.size();
    int m=arr[0].size();
   int dx[4]={1,-1,0,0};
   int dy[4]={0,0,1,-1};
  pq.push({0,{0,0}});
  vector<vector<int>>vis(n,vector<int>(m,0));
  vis[0][0]=1;
  while(!pq.empty()){
   auto it=pq.top();
   int time=it.first;
   int x=it.second.first;
   int y=it.second.second;
   pq.pop();
   if(x==n-1&&y==m-1)return time;
   for(int i=0;i<4;i++){
    int nx=dx[i]+x;
    int ny=dy[i]+y;
    if(nx>=0&&ny>=0&&nx<n&&ny<m&&!vis[nx][ny]){
        int wt=max(arr[nx][ny]-time,0);
        pq.push({time+wt+1,{nx,ny}});
        vis[nx][ny]=1;
    }
   }
  }
  return -1;
} 
    int minTimeToReach(vector<vector<int>>& arr) {
         int n=arr.size();
       int m=arr[0].size();
        //  vector<vector<int>>vis(n,vector<int>(m,0));
        //  solve(arr,0,0,0,vis);
        //  return res;
return solve(arr,0,0);
    //    int i=0;
    //    int j=1e9;
    //    int ans=-1;
    //    int n=arr.size();
    //    int m=arr[0].size();
    //    while(i<=j){
    //     int mid=(i+j)/2;
    //     vector<vector<int>>vis(n,vector<int>(m,0));
    //     if(solve(arr,mid,0,0,vis)){
    //         ans=mid;
    //         j=mid-1;
    //     }
    //     else{
    //         i=mid+1;
    //     }
    //    }
    //    return ans;
    }
};