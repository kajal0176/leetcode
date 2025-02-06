class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int cnt=0;
        for(auto it:mp){
            int n=it.second;
            int p=(n*(n-1))/2;
            cnt+=p;
        }
        return cnt*8;
    }
};