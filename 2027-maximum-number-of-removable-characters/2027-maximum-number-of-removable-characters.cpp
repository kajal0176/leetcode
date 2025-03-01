class Solution {
public:
bool isp(string s,string p,vector<int>& removable,int mid){
    string tmp="";
    for(int i=0;i<=mid;i++){
        s[removable[i]]='1';
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!='1'){
            tmp+=s[i];
        }
    }
    int i=0;
    int j=0;
    while(i<tmp.size()&&j<p.size()){
        if(tmp[i]==p[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    return j>=p.size();
}
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int ans=0;
        int i=0;
        int j=removable.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(isp(s,p,removable,mid)){
                ans=mid+1;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};