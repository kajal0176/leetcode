class Solution {
public:
long long cal(vector<int>&arr,vector<int>&brr){
long long ans=0;
      for(int i=0;i<arr.size();i++){
        ans+=(abs(arr[i]-brr[i]));
      }
      return ans;
}
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
      long long ans=cal(arr,brr);
     sort(arr.begin(),arr.end());
     sort(brr.begin(),brr.end());
     ans=min(ans,cal(arr,brr)+k);
     return ans;
    }
};