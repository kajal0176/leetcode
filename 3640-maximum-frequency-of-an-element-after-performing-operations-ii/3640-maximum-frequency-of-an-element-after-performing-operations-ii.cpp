class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mn=1e9;
       int mx=-1e9;
       unordered_map<int,int>mp;
        map<int,int>range;
        set<int>st;
       for(int i=0;i<nums.size();i++){
        range[nums[i]-k]++;
        range[nums[i]+k+1]--;
        mp[nums[i]]++;
        st.insert(nums[i]);
        st.insert(nums[i]-k);
        st.insert(nums[i]+k+1);
       }
       
      int ans=1;
      int cnt=0;
      
      for(auto it:st){
       cnt+=range[it];
       int t=min(numOperations,cnt-mp[it]);
       ans=max(ans,t+mp[it]);
      }
      return ans;
    }
};