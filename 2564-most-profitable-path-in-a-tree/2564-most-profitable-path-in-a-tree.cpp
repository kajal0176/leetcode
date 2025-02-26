class Solution {
public:
      bool solve(vector<int>adj[],int nd,int time,vector<int>&vis,unordered_map<int,int>&bobPath){
        vis[nd]=1;
        bobPath[nd]=time;
        if(nd==0){
            return true;
        }
        for(auto it:adj[nd]){
            if(!vis[it]){
                if(solve(adj,it,time+1,vis,bobPath)){
                    return true;
                }
            }
        }
        bobPath.erase(nd);
        return false;
      }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        int mx=INT_MIN;
        //create graph
        vector<int>adj[n];
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
      unordered_map<int,int>bobPath;
      vector<int>vis(n,0);
      solve(adj,bob,0,vis,bobPath);
    //   for(auto it:bobPath){
    //     cout<<it.first<<" "<<it.second<<" ";
    //   }
      queue<vector<int>>q;
      q.push({0,0,0});
      
      for(int i=0;i<n;i++){
       vis[i]=0;
      }
      while(!q.empty()){
        auto t=q.front();
        int nd=t[0];
        int cost=t[1];
        int time=t[2];
        if(bobPath.find(nd)==bobPath.end()||time<bobPath[nd]){
            cost+=amount[nd];
        }
        else if(time==bobPath[nd]){
            cost+=(amount[nd]/2);
        }
      //  cout<<nd<<" ";
        if(adj[nd].size()==1&&nd!=0){
          //  cout<<"k";
            mx=max(mx,cost);
        }
        for(auto it:adj[nd]){
            if(!vis[it]){
                q.push({it,cost,time+1});
            }
        }
        vis[nd]=1;
        q.pop();
      }
      return mx;
    }
};