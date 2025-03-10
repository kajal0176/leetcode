class Solution {
public:
bool isVowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
        return true;
    }
    return false;
}
    long long countOfSubstrings(string word, int k) {
        long long ans=0;
       unordered_map<char,int>mp;
       int cnt=0;
       int i=0;
       int j=0;
       long long res=0;
       vector<int> next(word.size());
       int ind=word.size();
       for (int i = word.size() - 1; i >= 0; i--) {
            next[i] = ind;
            if (!isVowel(word[i])) {
                ind = i;
            }
        }
       
       while(j<word.size()){
        if(isVowel(word[j])){
            mp[word[j]]++;
        }
        else{
            cnt++;
        }
       while(cnt>k){
        if(isVowel(word[i])){
            mp[word[i]]--;
            if(mp[word[i]]==0)
            mp.erase(word[i]);
        }
        else{
            cnt--;
        }
        i++;
       }
      while(i<word.size()&&mp.size()==5&&cnt==k){
        ans+=next[j]-j;
        if(isVowel(word[i])){
            mp[word[i]]--;
            if(mp[word[i]]==0)
            mp.erase(word[i]);
        }
        else{
            cnt--;
        }
        i++;
      }
        j++;
       }
       return ans;
    }
};