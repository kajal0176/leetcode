class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int prev=0;
        for(int i=1;i<nums.size();i++){
            if(nums[prev]==nums[i]&&nums[i]!=0){
                nums[prev]*=2;
                nums[i]=0;
                
            }
                prev=i;
        }
        int ind=0;
       
        for(int i=0;i<nums.size();i++){
           if(nums[i]!=0){
            nums[ind]=nums[i];
            ind++;
           }
        }
        for(int i=ind;i<nums.size();i++){
            nums[i]=0;
        }
        return nums;
    }
};