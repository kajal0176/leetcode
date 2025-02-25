class Solution {
public:
void solve(vector<int>adj[],int nd,vector<int>&vis){
    vis[nd]=1;
    for(auto it:adj[nd]){
        if(!vis[it]){
          solve(adj,it,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
              if(isConnected[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
              }
            }
        }
       int cnt=0;
       vector<int>vis(n,0);
       for(int i=0;i<n;i++){
        if(!vis[i]){
            solve(adj,i,vis);
            cnt++;
        }
       }
       return cnt;
    }
};