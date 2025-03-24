class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>v;
        int start=meetings[0][0];
        int last=meetings[0][1];
        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0]<=last){
                last=max(last,meetings[i][1]);
            }
            else{
                v.push_back({start,last});
                start=meetings[i][0];
                last=meetings[i][1];
            }
        }
        v.push_back({start,last});
        int cnt=0;
        for(int i=0;i<v.size();i++){
            cnt+=(v[i][1]-v[i][0]+1);
        }
        return days-cnt;
    }
};