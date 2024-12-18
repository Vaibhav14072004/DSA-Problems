// Best Approach ->> Stack
// TC= O(2*N)

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n= prices.size();

        stack<int> st;
        for(int i=0; i<n; i++)
        {
            // if next element is smaller than previous... discount can be applied
            while(!st.empty() && prices[st.top()] >= prices[i])
            {
                prices[st.top()]-= prices[i];
                st.pop();
            }
          st.push(i);    
        }
        return prices;
    } 
};






// Brute Force Approach
// TC= O(N^2)

/*
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n= prices.size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(prices[j] <= prices[i])
                {
                    prices[i]-= prices[j];
                    break;
                }
            }
        }
    return prices;
    }
};

*/