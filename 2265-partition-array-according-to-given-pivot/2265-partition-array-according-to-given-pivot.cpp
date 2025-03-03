class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int small=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot)small++;
        }
        
        int mid=small;
        small=0;
         vector<int>ans(nums.size());
         for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                ans[small]=nums[i];
                small++;
            }
            else if(nums[i]==pivot){
                ans[mid]=pivot;
                mid++;
            }
         }
         for(int i=0;i<nums.size();i++){
           if(nums[i]>pivot){
            ans[mid]=nums[i];
            mid++;
           }
         }
         return ans;
    }
};