class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n!=m){
            return false;
        }
        int cnt1=0;
       int i=0;
       int j=0;
       int pos1,pos2;
       while(i<n&&j<m){
        if(s1[i]!=s2[j]){
            cnt1++;
            if(cnt1==1){
            pos1=i;
        }
        if(cnt1==2){
            pos2=i;
        }
        }
        
        
        i++;
        j++;
       }

       if(cnt1==2){
        swap(s1[pos1],s1[pos2]);
        cout<<s1<<" ";
        return s1==s2;
       }
       return cnt1==0;
    }
};