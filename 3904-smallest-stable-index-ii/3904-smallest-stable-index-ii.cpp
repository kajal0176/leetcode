class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>mx(nums.size());
        vector<int>mn(nums.size());
        mx[0]=nums[0];
        mn[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            mx[i]=max(mx[i-1],nums[i]);
        }
        for(int j=nums.size()-2;j>=0;j--){
            mn[j]=min(mn[j+1],nums[j]);
        }
        vector<int>score(nums.size());
        for(int i=0;i<nums.size();i++){
            score[i]=mx[i]-mn[i];
            if(score[i]<=k)return i;
        }
       return -1;
    }
};