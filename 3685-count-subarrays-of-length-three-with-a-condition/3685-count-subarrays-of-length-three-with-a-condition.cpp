class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        int i=0;
        int j=0;
        int n=nums.size();
        vector<int>v;
        while(j<n){
        v.push_back(nums[j]);
        if(j-i+1==3){
            int a=v[i];
            int c=v[i+2];
            int b=v[i+1];
            if(2*(a+c)==b){
                count++;
            }
            i++;
        }
        j++;
        }
        return count;
    }
};