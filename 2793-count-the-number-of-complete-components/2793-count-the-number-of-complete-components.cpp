class dsu{
    public:
    vector<int>height;
    vector<int>parent;
    dsu(int n){
        height.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findPar(int u){
        if(u==parent[u])return u;
        return parent[u]=findPar(parent[u]);
    }
    void findUnion(int u,int v){
        int pu=findPar(u);
        int pv=findPar(v);
        if(pu==pv)return ;
        if(height[pu]>=height[pv]){
            height[pu]+=height[pv];
            parent[pv]=pu;
        }
        else{
            height[pv]+=height[pu];
            parent[pu]=pv;
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        dsu ds(n);
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            ds.findUnion(edge[0],edge[1]);
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            int p=ds.findPar(i);
            int t=0;
            if(p==i){
                for(int j=0;j<n;j++){
                    int par=ds.findPar(j);
                    if(p==par&&adj[j].size()==ds.height[par]-1){
                        t++;
                    }
                }
                if(t==ds.height[p]){
                    count++;
                }
            }
        }
        return count;
    }
};