class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            if(!st.empty()&&st.top()==nums[i]&&nums[i]!=0){
                int x=st.top();
                st.pop();
                st.push(x*2);
                st.push(0);
            }
           else{
                st.push(nums[i]);
            }
        }
        int ind=0;
        while(!st.empty()){
            int element=st.top();
            st.pop();
            if(element!=0){
                nums[ind]=element;
                ind++;
            }
        }
        reverse(nums.begin(),nums.begin()+ind);
        for(int i=ind;i<nums.size();i++){
            nums[i]=0;
        }
        return nums;
    }
};