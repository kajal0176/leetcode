class Solution {
public:
bool isPrime(int num){
   if(num==1||num==0){
    return false;
   }
   for(int i=2;i*i<=num;i++){
    if(num%i==0)return false;
   }
   return true;
}
    bool completePrime(int num) {
      
      string s= to_string(num);
      string pre="";
    //   for(int i=0;i<p.size();i++){
    //     cout<<i<<"->"<<p[i]<<"\n";
    //   }
      for(int i=0;i<s.size();i++){
        pre+=s[i];
        if(!isPrime(stoi(pre)))return false;
      }
      string suf="";
      for(int i=s.size()-1;i>=0;i--){
        suf=s[i]+suf;
       // cout<<suf<<" ";
        if(!isPrime(stoi(suf))) return false;
      }
      return true;
    }
};