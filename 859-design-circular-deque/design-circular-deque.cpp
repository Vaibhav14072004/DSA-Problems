// Approach 1 -> Using Array...
// TC= O(1)

class MyCircularDeque {
public:
    int size;
    int K;
    vector<int> vec;
    int front;
    int rear;

    MyCircularDeque(int k) {
        K= k;
        vec.resize(K,0);
        size= 0;
        front= 0;
        rear= K-1;
    }
    
    bool insertFront(int value) {
        if(size== K)
        {
          return false;
        }
       front= (front-1+K)% K;
       vec[front]= value;  
       size++;
       return true;  
    }
    
    bool insertLast(int value) {
       if(size== K){
          return false;
       } 
       rear= (rear+1) % K;
       vec[rear]= value;
       size++;
       return true;
    }
    
    bool deleteFront() {
        if(size== 0){
            return false;
        }
        front= (front+1)% K;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size== 0){
          return false;
        }
        rear= (rear-1+K) % K;
        size--;
        return true;
    }
    
    int getFront() {
        if(size== 0){
            return -1;
        }
        return vec[front];
    }
    
    int getRear() {
        if(size== 0){
            return -1;
        }
        return vec[rear];
    }
    
    bool isEmpty() {
       return size== 0;
    }
    
    bool isFull() {
       return size== K; 
    }
};



/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */