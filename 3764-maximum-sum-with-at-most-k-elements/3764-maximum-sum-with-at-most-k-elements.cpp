class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++)
            pq.push({grid[i][j],i});
        }
        long long ans=0;
        while(!pq.empty()&&k){
            auto t=pq.top();
            pq.pop();
           //  cout<<t.first<<" "<<t.second<<" ,";
            if(limits[t.second]>0){
                ans+=t.first;
                limits[t.second]--;
                k--;
               
            }
        }
        return ans;
    }
};