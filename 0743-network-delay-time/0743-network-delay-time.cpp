class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int time=times[i][2];
            adj[u].push_back({v,time});
        }
        vector<int>dis(n+1,INT_MAX);
        queue<pair<int,int>>q;
        q.push({k,0});
        dis[k]=0;
        dis[0]=-1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first;
            int time=it.second;
            for(auto nd:adj[node]){
                int adjn=nd.first;
                int nt=nd.second;
                if(time+nt<dis[adjn]){
                    dis[adjn]=time+nt;
                    q.push({adjn,dis[adjn]});
                }
            }
        }
        int ans=*max_element(dis.begin(),dis.end());
        return (ans==INT_MAX)?-1:ans;
    }
};