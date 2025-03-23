class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>>adj(n);
        int mod=1e9+7;
        for(auto edge:roads){
          adj[edge[0]].push_back({edge[1],edge[2]});
          adj[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<long long>dist(n,1e15);
        vector<long long>cnt(n,0);
       priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
        q.push({0,0});
        dist[0]=0;
        cnt[0]=1;
        while(!q.empty()){
            long long nd=q.top().second;
            long long ds=q.top().first;
            q.pop();
           // cout<<nd<<" ";
            for(auto neigh:adj[nd]){
                if(dist[neigh.first]>ds+neigh.second){
                    dist[neigh.first]=ds+neigh.second;
                    cnt[neigh.first]=cnt[nd];
                    q.push({dist[neigh.first],neigh.first});
                }
                else if(dist[neigh.first]==ds+neigh.second){
                    cnt[neigh.first]=(cnt[neigh.first]+cnt[nd])%mod;
                }
            }
        }
        return cnt[n-1];
    }
};