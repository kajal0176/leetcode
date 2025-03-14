class Solution {
public:
bool isp(vector<int>&candies,long long mid,long long k){
   long long cnt=0;
   for(int i=0;i<candies.size();i++){
    cnt+=(candies[i]/mid);
   }
   return cnt>=k;
}
    int maximumCandies(vector<int>& candies, long long k) {
        long long i=1;
        long long j=1e9;
        long long ans=0;
        while(i<=j){
            long long mid=(i+(j-i)/2);
            if(isp(candies,mid,k)){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};