class Solution {
public:
    int minOperations(vector<int>& nums) {
        queue<int>q;
        int i=0;
        int j=0;
        int cnt=0;
        while(j<nums.size()){
            q.push(nums[j]);
            while(!q.empty()&&q.front()==1){
                q.pop();
                i++;
            }
           // cout<<q.size()<<" ";
            if(q.size()==3){
              while(!q.empty())q.pop();
              //cout<<i<<" "<<j<<" ";
              while(i<=j&&nums[i]==0){
                nums[i]=1;
                i++;
              }
               for(int k=i;k<=j;k++){
                q.push((!nums[k]));
                nums[k]=!nums[k];
               }
              cnt++;
            }
            j++;
        }
        // while(!q.empty()){
        //     int x=q.front();
        //     q.pop();
        //     cout<<x<<" ";
        // }
         if(q.size())return -1;
        return cnt;
    }
};