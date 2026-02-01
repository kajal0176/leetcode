class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum=nums[0];
        int k=2;
        priority_queue<int>pq;
        for(int i=1;i<nums.size();i++){
         pq.push(nums[i]);
         if(pq.size()>k){
            pq.pop();
         }
        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};