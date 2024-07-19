// Approach 2 -> Optimized (Using stack)

// Store the previous greater element and its index in stack...
// If stack is empty store {-1,-1}, bcoz when we do currIdx -(-1) it will return 1 as output

// (Curr Index- prevGreaterElement Idx) will give no of days when stock price was less than or equal to the price of that day.

class StockSpanner {
public:
    vector<int> arr;
    stack<pair<int,int>> st;
    int index;

    StockSpanner()
    {
        arr= {};
        st= {};
        index= -1;
    }

    int next(int price)
    {
        index++;

        // pop out all arr elements <= price.. bcoz we need next greter element
         while(!st.empty() && st.top().first <= price)
         {
            st.pop();
         }

         int cnt;
        // if stack is empty, we should return 1 in this case to count only curr day.
         if(st.empty())
         {
            cnt= index- (-1);
         }
         else
         {
            cnt= index- st.top().second;
         }

         st.push({price,index});
        return cnt; 
    }
};







// Approach 1 -> Brute Force Approach 
// TC= O(len of arr)

/*

class StockSpanner {
public:
    vector<int> arr;

    StockSpanner()
    {
        arr= {};
    }
    
    int next(int price)
    {
        arr.push_back(price);
        
        if(arr.size()== 1){
            return 1;
        }

         int cnt= 0;
        for(int i= arr.size()-1; i>=0; i--)
        {
            if(arr[i] <= price)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
     return cnt;  
    }
};

*/







/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */