class DisjointSet {
    
public:
vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    int unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return 0;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        return 1;
    }
};
class Solution {
public:
   bool isConnected(unordered_map<int, unordered_set<int>>& mp, int k, int i, int j){
    for(auto t: mp[i]) k -= (mp[j].find(t) != mp[j].end())?1:0;
    return (k <= 0);
}
   
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        vector<vector<int>>adj(properties.size());
        DisjointSet ds(properties.size());
        int cnt=properties.size();
         unordered_map<int, unordered_set<int>> mp;
   // for(int i = 0; i < par.size(); ++i) par[i] = i;
    for(int i = 0; i < properties.size(); ++i){           // create the lookup map 
        for(int j = 0; j < properties[i].size(); ++j) mp[i].insert(properties[i][j]);
    }
        for(int i=0;i<properties.size();i++){
            
            for(int j=i+1;j<properties.size();j++){
               // cout<<i<<" "<<j<<" ";
                if(isConnected(mp, k, i, j)){
                   cnt-=ds.unionByRank(i,j);
                }
            }
        }
        // for(int i=0;i<properties.size();i++){
        //     cout<<i<<"->";
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // int cnt=0;
        // vector<int>vis(properties.size()+1,0);
        // for(int i=0;i<properties.size();i++){
        //     if(ds.parent[i]==i){
        //        // dfs(adj,i,vis);
        //         cnt++;
        //     }
        // }
        return cnt;
    }
};