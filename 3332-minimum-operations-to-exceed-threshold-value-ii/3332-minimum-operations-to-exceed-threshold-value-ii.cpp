class Solution {
public:
#define ll long long
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int cnt=0;
        while(pq.size()>=2){
            if(pq.top()>=k){
                break;
            }
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            pq.push(2*a*1L+b*1L);
            cnt++;
        }
        return cnt;
    }
};