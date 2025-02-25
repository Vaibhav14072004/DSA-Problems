// Brute Force Approach ->> TC= O(K) for getProduct func

class ProductOfNumbers {
public:
    vector<int> arr;

    ProductOfNumbers() {
    }
    
    void add(int num) {
      arr.push_back(num);
    }
    
    int getProduct(int k) {
         int prod= 1;
         int n= arr.size();
         for(int i=n-k; i<n; i++)
         {
            prod= prod* (arr[i]);
         }
       return prod;   
    }
};


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */