class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>diff(s.size()+1,0);
        for(int i=0;i<shifts.size();i++){
            int l=shifts[i][0];
            int r=shifts[i][1];
            int val=shifts[i][2];
            if(val==0){
            diff[l]-=1;
            diff[r+1]+=1;
            }
            else{
                diff[l]+=1;
                diff[r+1]-=1;
            }
        }
        int cnt=0;
       
        for(int i=0;i<s.size();i++){
            cnt+=diff[i];
            int k=cnt%26;
            int p=(s[i]-'a'+k+26)%26;
            s[i]=char('a'+p);
        }
        return s;
    }
};