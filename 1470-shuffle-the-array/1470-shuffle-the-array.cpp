class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2*n);
        int ind=0;
        int i=0;
        int j=n;
        while(i<n&&j<2*n){
            ans[ind]=nums[i];
            ind++;
            ans[ind]=nums[j];
            ind++;
            i++;
            j++;
        }
        return ans;
    }
};