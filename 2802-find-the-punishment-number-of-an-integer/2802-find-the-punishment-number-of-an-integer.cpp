class Solution {
public:
   bool check(string s,int target){
       
      if(s==""&&target==0){
          return true;
      }
    //   if(target<0){
    //       return false;
    //   }
       bool f=0;
       for(int i=0;i<s.size();i++){
           string s1=s.substr(0,i+1);
          // cout<<(n-i);
           string s2=s.substr(i+1);
           int x=0;
         
           if(s1.size()>0)
            x=stoi(s1);
          
           //cout<<x<<" "<<y<<" ";
           if(target-x>=0&&check(s2,target-x)){
               f=1;
              break;
           }
       }
       return f;
       
   }
    int punishmentNumber(int n) {
        int sum = 0;
        // bool f=check(1296,0,3);
        // cout<<f;
    for (int i = 1; i <= n; i++) {
         int t=i*i;
       // cout<<t<<" ";
      
        if (check(to_string(t),sqrt(t))) {
           // cout<<i<<" ";
            sum += (i * i);
        }
    }
    return sum;
    }
};