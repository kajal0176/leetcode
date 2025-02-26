class dsu{
    vector<int>parent;
    vector<int>height;
    public:
    dsu(int n){
        parent.resize(n);
        height.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findPar(int node){
        if(parent[node]==node){
            return node;
        }
       return parent[node]=findPar(parent[node]);
    }
    void unite(int u,int v){
        int up=findPar(u);
        int vp=findPar(v);
        if(up==vp){
            return;
        }
        if(height[up]>=height[vp]){
            parent[vp]=up;
        }
        else{
            parent[up]=vp;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cnt=0;
        dsu ds(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            if(ds.findPar(u)==ds.findPar(v)){
                cnt++;
            }
            else{
                ds.unite(u,v);
            }
        }
        int con=0;
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i){
                con++;
            }
        }
        if (con-1>cnt){
            return -1;
        }
        return con-1;
    }
};