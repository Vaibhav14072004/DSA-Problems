class ProductOfNumbers {
public:
    vector<int> stream;
    ProductOfNumbers() {
        stream.push_back(1);  // Initialize with 1 to handle division easily.
    }

    void add(int num) {
        if (num == 0) {
            stream = {1};  // Reset if zero is encountered.
        } else {
            stream.push_back(stream.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= stream.size()) {
            return 0;  // If k is out of bounds, return 0 (zero encountered previously).
        }
        return stream.back() / stream[stream.size() - 1 - k];
    }
};