class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long >prefixgcd(nums.size());
        vector<long long>suffixgcd(nums.size());
        vector<long long>prelcm(n);
        vector<long long>suf(n);
        prefixgcd[0]=nums[0];
        prelcm[0]=nums[0];
        suffixgcd[n-1]=nums[n-1];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            long long t=nums[i];
           prefixgcd[i]= __gcd(prefixgcd[i-1],t);
           prelcm[i]=lcm(prelcm[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            long long t=nums[i];
            suffixgcd[i]=__gcd(suffixgcd[i+1],t);
            suf[i]=lcm(suf[i+1],nums[i]);
        }
        long long ans=prefixgcd[n-1]*prelcm[n-1];
        if(n==1)return ans;
        ans=max(suffixgcd[1]*suf[1],ans);
        ans=max(prefixgcd[n-2]*prelcm[n-2],ans);
        for(int i=1;i<n-1;i++){
           long long lgcd=prefixgcd[i-1];
           long long rgcd=suffixgcd[i+1];
           long long llcm=prelcm[i-1];
           long long rlcm=suf[i+1];
           long long g=__gcd(lgcd,rgcd);
           long long l=lcm(llcm,rlcm);
           ans=max(ans,g*l);
        }
        return ans;
    }
};