class Solution {
public:
bool isp(vector<int>&ranks,long long mid,long long car){
long long cnt=0;
for(int i=0;i<ranks.size();i++){
    cnt+=(sqrt(mid/ranks[i]));
    if(cnt>=car)return true;
}
return false;
}
    long long repairCars(vector<int>& ranks, int cars) {
        long long i=1;
        long long j=1e14;
        long long ans=-1;
        while(i<=j){
            long long mid=(i+(j-i)/2);
            if(isp(ranks,mid,cars)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;

    }
};