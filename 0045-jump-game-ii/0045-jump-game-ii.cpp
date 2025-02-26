class Solution {
public:
    int jump(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]=max(nums[i-1],i+nums[i]);
        }
        int cnt=0;
        int i=0;
        while(i<nums.size()-1){
         i=nums[i];
         cnt++;
        }
        return cnt;
    }
};