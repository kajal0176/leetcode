class Solution {
public:

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int sum=0;
        vector<int>vis(n,0);
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
          //  sum+=wt;
            adj[v].push_back({u,wt});
            
        }
         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq; 
        pq.push({0,0});
        int mn=0;
        while(pq.size()){
            auto node=pq.top()[1],w=pq.top()[0];
            pq.pop();
            if(vis[node])continue;
            vis[node]=1;
            mn=max(mn,w); 
            for(auto i:adj[node]){
                if(!vis[i.first])
                pq.push({i.second,i.first});
            }
        }
        for(auto i:vis)if(i==0)return -1; 
        return mn;  
    }
};