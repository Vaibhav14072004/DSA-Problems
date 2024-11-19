// Approach 2 -> Sliding Window
// TC= O(N)

class Solution{
public: 
    vector<int> decrypt(vector<int>& code, int k) {
        int n= code.size();
        
        vector<int> ans(n,0);
        if(k== 0)
        {
            return ans;
        }
        
        int i=-1, j= -1;
        int sum= 0;

        if(k > 0)
        {
            i= 1;
            j= k;
        }
        else
        {
            i= n- abs(k);  
            j= n-1;
        }
        
        // calculate the sum of the curr window of next 3 elements,starting from i to j
        for(int idx= i; idx<= j; idx++)
        {
            sum+= code[idx % n];
        }
        
        // now run a loop and remove the (i)th element and add (j+1) th element in sum
        for(int idx= 0; idx<n; idx++)
        {
            ans[idx]= sum;
            sum-= code[i % n];
            i++;
            sum+= code[(j+1) % n];
            j++;
        }
        return ans;
    }
};







// Approach 1 -> Brute Force Approach
// TC= O(N*k)

/*

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n= code.size();
        
        vector<int> ans(n,0);
        if(k== 0)
        {
            return ans;
        }

        for(int i=0; i<n; i++)
        {
            int sum= 0;

            if(k> 0)
            {
                for(int j=i+1; j<= i+k; j++)
                {
                    sum+= code[j % n];
                }
                ans[i]= sum;
            }
            
            // if(k < 0)
            else
            {
                for(int j= i-1; j>= i+k; j--)
                {
                    sum+= code[(j+n) % n];
                }
                ans[i]= sum;
            }
        }
        return ans;
    }
};

*/