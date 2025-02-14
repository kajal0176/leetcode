class ProductOfNumbers {
public:
vector<int>stream;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
         stream.push_back(num);
       
    }
    
    int getProduct(int k) {
        int n=stream.size();
      // int t=stream[n-1-k].second;
       int ans=1;
       //cout<<k<<" "<<n<<" ";
       int i=n-1;
       while(k--){
       // cout<<stream[i]<<" ";
        ans*=stream[i];
        i--;
       }
      // cout<<"\n";
       return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */