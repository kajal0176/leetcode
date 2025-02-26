class Solution {
public:
int mod=1e9+7;

    int numOfSubarrays(vector<int>& arr) {
       int pref=0;
       int odd=0;
       for(int i=0;i<arr.size();i++){
        pref+=arr[i];
        odd+=(pref%2);
       }
       cout<<odd<<" ";
       odd+=((arr.size()-odd)%mod*(odd%mod))%mod;
       return odd;
    }
};