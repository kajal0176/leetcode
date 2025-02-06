class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<int>st;
        int last=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int num=max(last+1,nums[i]-k);
         //   cout<<last<<" ";
            if(num<=nums[i]+k){
                st.insert(num);
                last=num;
            }
        }
        return st.size();
    }
};