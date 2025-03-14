class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
       int mn=1e9;
       int mx=-1e9;
       unordered_map<int,int>mp;
        unordered_map<int,int>range;

       for(int i=0;i<nums.size();i++){
        range[nums[i]-k]++;
        range[nums[i]+k+1]--;
        mp[nums[i]]++;
        mn=min(mn,nums[i]-k);
        mx=max(mx,nums[i]+k+1);
       }
       
      int ans=1;
      int cnt=0;
      auto it=mp.begin();
      for(int i=mn;i<=mx;i++){
      range[i]+=range[i-1];
       int t=min(numOperations,range[i]-mp[i]);
       ans=max(ans,t+mp[i]);
      }
      return ans;
    }
};