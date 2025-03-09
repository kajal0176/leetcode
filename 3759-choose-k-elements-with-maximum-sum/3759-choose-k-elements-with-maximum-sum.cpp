class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>vp;
        for(int i=0;i<nums1.size();i++){
            vp.push_back({nums1[i],i});
        }
        sort(vp.begin(),vp.end());
        unordered_map<long long,long long>mp;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        int j=0;
        long long sum=0;
        for(int i=0;i<vp.size();i++){
            
            while(j<i){
                int ind=vp[j].second;
                if(vp[j].first>=vp[i].first)break;
                pq.push(nums2[ind]);
                sum+=nums2[ind];
                if(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }
                j++;
            }
            mp[vp[i].second]=sum;
        }
        vector<long long>ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=mp[i];
        }
        return ans;
    }
};