// Approach -> Using vector inc to store what we have to increment till that index
// Lazy Propagation
// TC= O(1) 


class CustomStack {
public:
    vector<int> inc;
    int size;
    stack<int> st;

    CustomStack(int maxSize) {
       size= maxSize;
       inc.resize(size,0);
    }
    
    void push(int x) {
        if(size== st.size())
        {
            return;
        }

        st.push(x);
        inc[st.size()-1]= 0;
    }
    
    int pop() {
        if(st.size()== 0)
        {
            return -1;
        }
        
        int idx= st.size()-1;
       
       // before removing inc[idx] value add it in prev inc[idx-1] -> Lazy Propagation
       if(idx >=1)
       {
          inc[idx-1]+= inc[idx];
       }

        int sum= st.top()+ inc[idx];
        st.pop();
        inc[idx]= 0;
        return sum;
    }
    
    void increment(int k, int val)
    {
        int idx= min((int)st.size(), k)- 1;

        if(idx >= 0)
        {
           inc[idx]+= val;
        }
    }
};



/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */