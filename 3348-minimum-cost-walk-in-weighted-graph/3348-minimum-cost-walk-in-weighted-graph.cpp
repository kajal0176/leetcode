class dsu{
    public:
  vector<int>parent;
  vector<int>height;
  dsu(int n){
    parent.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    height.resize(n,1);
  }
  int find(int nd){
    if(nd==parent[nd])return nd;
    return parent[nd]=find(parent[nd]);
  }
  void findunion(int u,int v){
    int pu=find(u);
    int pv=find(v);
    if(pu==pv)return;
    if(height[pu]>=height[pv]){
        parent[pv]=pu;
        height[pu]+=height[pv];
    }
    else{
     parent[pu]=pv;
     height[pv]+=height[pu];
    }
  }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int>cost(n,-1);
        dsu ds(n);
        for(auto edge:edges){
            ds.findunion(edge[0],edge[1]);
        }
        for(auto it:edges){
            int uparent=ds.find(it[1]);
            cost[uparent]&=it[2];
        }
        vector<int>ans;
        for(auto q:query){
            int src=q[0];
            int d=q[1];
            if(ds.find(src)!=ds.find(d)){
                ans.push_back(-1);
            }
            else{
                int root=ds.find(src);
                ans.push_back(cost[root]);
            }
        }
        return ans;
    }
};