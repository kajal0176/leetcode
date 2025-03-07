class Solution {
public:
vector<int>primes(int n){
    vector<int>prime(n+1,0);
    for(int i=2;i*i<=n;i++){
        if(!prime[i]){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=1;
            }
        }
    }
    return prime;
}
    vector<int> closestPrimes(int left, int right) {
        vector<int>isPrime=primes(1000000);
        int ind=0;
        int first=-1;
        int sc=-1;
        int mn=INT_MAX;
        vector<int>v;
        for(int i=left;i<=right;i++){
           if(!isPrime[i]&&i!=0&&i!=1){
            v.push_back(i);
           }
           
        }
        for(int i=1;i<v.size();i++){
          if(v[i]-v[i-1]<mn){
            mn=v[i]-v[i-1];
            first=v[i-1];
            sc=v[i];
          }
        }
        if(first==-1||sc==-1){
            return {-1,-1};
        }
        return {first,sc};
    }
};