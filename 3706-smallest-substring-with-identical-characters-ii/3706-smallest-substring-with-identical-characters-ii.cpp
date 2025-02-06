class Solution {
public:
bool check(string& s, int numOps, int mid, char startChar){
    for(int i = 0; i < s.size(); ++i){
        if(startChar == s[i]) numOps--;
        startChar = (startChar == '0')?'1':'0';
    }
    return (numOps >= 0);
}
bool isp(string s,int mid,int cnt){
    if(mid==0){
        return false;
    }
    if(mid == 1) return check(s, cnt, mid, '1') || check(s, cnt, mid, '0');
    int ct=1;
    int st=0;
    for(int i=1;i<s.size();i++){
     if(s[i]==s[i-1]){
        
        ct++;
        if(ct>mid){
           
          
        if(s[i]=='1'){
        if(i+1<s.size()&&s[i]==s[i+1])
            s[i]='0';
            else
            s[i-1]='0';
         }
        else{
          if(i+1<s.size()&&s[i]==s[i+1])
            s[i]='1';
            else
            s[i-1]='1';
            
        }
        if(cnt<=0){
            return false;
        }
        cnt--;
        ct=1;
        }
     }
     else{
        ct=1;
       st=i;
     }
    }
  // cout<<s<<" ";
    return cnt>=0;
}
    int minLength(string s, int numOps) {
         int i=0;
        int j=s.size();
        int ans=s.size();
        while(i<=j){
            int mid=(i+j)/2;
            cout<<mid<<" ";
            if(isp(s,mid,numOps)){
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