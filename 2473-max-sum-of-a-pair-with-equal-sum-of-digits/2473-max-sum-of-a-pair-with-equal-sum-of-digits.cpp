class Solution {
public:
int findSum(int num){
    int sum=0;
    while(num){
        int r=num%10;
        sum+=r;
        num=num/10;
    }
    return sum;
}
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            int sum=findSum(nums[i]);
            mp[sum].push_back(nums[i]);
        }
        int ans=-1;
        for(auto it:mp){
            auto v=it.second;
            int n=v.size();
            if(v.size()>=2){
                ans=max(ans,v[n-1]+v[n-2]);
            }
        }
        
        return ans;
    }

};