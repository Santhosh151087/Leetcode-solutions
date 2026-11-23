class ProductOfNumbers {
public:
    vector<int> arr;
    vector<int> zero;
    int last_zero = -1;
    int len = 1;
    ProductOfNumbers() {
        arr.push_back(1);
        
    }
    
    void add(int num) {
        if(num==0){
            last_zero = len;
            arr.push_back(1);
        }
        else{
        int last = arr[len-1];
        arr.push_back(last*num);
        }
        
        len++;
    }
    
    int getProduct(int k) {
      int ind = len - k;
        if(last_zero !=-1 && ind<=last_zero)
        return 0;
        // cout<<len<<" "<<arr[ind-1]<<" "<<arr[len-1]<<" "<<endl;
        return arr[len-1] / arr[ind-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */