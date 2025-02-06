class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int last=nums.size()-1;
        int first=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int cnt=0;
        while(mp.size()<last-first+1){
            mp[nums[first]]--;
            if(mp[nums[first]]==0){
                mp.erase(nums[first]);
            }
            cnt++;
            first++;
        }
        cout<<cnt<<" ";
        return cnt/3+(cnt%3>0);
    }
};