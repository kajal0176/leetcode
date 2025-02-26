class dsu{
public:
vector<int>parent;
vector<int>size;
dsu(int n){
    size.resize(n+1,1);
    parent.resize(n+1,0);
    for(int i=0;i<n+1;i++){
        parent[i]=i;
    }
}
int findpar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findpar(parent[node]);
}
void unionbysz(int a,int b){
    int pa=findpar(a);
    int pb=findpar(b);
    if(pa==pb){
        return;
    }
    if(size[pa]<size[pb]){
        parent[pa]=pb;
        size[pb]+=size[pa];
    }
    else{
        parent[pb]=pa;
        size[pa]+=size[pb];
    }
}
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp;
        int n=accounts.size();
        vector<vector<int>>v;
        dsu ds(n);
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    int v=mp[accounts[i][j]];
                    int u=i;
                    ds.unionbysz(u,v);
                }
                else{
                    mp[accounts[i][j]]=i;
                }
            }
        }
        vector<vector<string>>merge(n);
       for(auto it:mp){
        string mail=it.first;
        int p=ds.findpar(mp[mail]);
        merge[p].push_back(mail);
       }
       vector<vector<string>>tmp;
       for(int i=0;i<n;i++){
        if(merge[i].size()==0){
            continue;
        }
        string name=accounts[i][0];
        sort(merge[i].begin(),merge[i].end());
        vector<string>v;
        v.push_back(name);
        for(auto it:merge[i]){
            v.push_back(it);
        }
        tmp.push_back(v);
       }
       return tmp;
    }
};