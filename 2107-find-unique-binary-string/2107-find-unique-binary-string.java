class Solution {
    void solve(int n,String temp,HashSet<String>arr){
        if(n<=0){
            arr.add(temp);
            return;
        }
        solve(n-1,temp+"0",arr);
        solve(n-1,temp+"1",arr);
        return ;
    }
    public String findDifferentBinaryString(String[] nums) {
        HashSet<String>arr=new HashSet<>();
        HashSet<String>h=new HashSet<>();
        solve(nums.length,"",arr);
        for(String s:nums){
            h.add(s);
        }
        for(String s:arr){
            if(!h.contains(s)){
                return s;
            }
        }
        return "";
    }
}