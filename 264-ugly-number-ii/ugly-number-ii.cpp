// Approach  3 -> ... Using Simple array...
// TC= O(N)

class Solution{
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1]= 1;
        
        int ptr2= 1, ptr3= 1, ptr5= 1;

        for(int i=2; i<=n; i++)
        {
            int multiply2= dp[ptr2]* 2;
            int multiply3= dp[ptr3]* 3;
            int multiply5= dp[ptr5]* 5;

            int minElement= min(multiply2, min(multiply3, multiply5));
            dp[i]= minElement;

            if(minElement== multiply2)
            {
                ptr2++;
            }
            
            if(minElement== multiply3)
            {
                ptr3++;
            }
            
            if(minElement== multiply5)
            {
                ptr5++;
            }
        }

      return dp[n];  
    }
};







// Approach 2 -> Using Min Heap (Priority_queue) and set..

 // TC= O(N* 3* 2* log n) ->  O(6* N log N)
 // TC= O(N log N)

/*

class Solution{
 public:
    int nthUglyNumber(int n) {
         priority_queue<long long,vector<long long>, greater<long long>> pq;

         vector<int> temp= {2,3,5};
         set<long long> st;
         pq.push(1);
         st.insert(1);
         
         long long top= 1;
         while(n--)
         {
             top= pq.top();
             pq.pop();
             
             for(auto it: temp)
             {
                 if(st.find(top*it) == st.end())
                 {
                    pq.push(top*it);
                    st.insert(top*it);
                 }
             }
         }
        
        // return static_cast<int> (top);
        return int(top);  
    }
 };

*/





// Approach 1 -> Brute Force Approach
// TC= O(N log N)

/*

class Solution {
public:
   // TC= O(log n)
    bool isUgly(int no)
    {
        while(no != 1)
        {
            if(no % 2 == 0)
            {
                no= no/2;
            }
            else if(no % 3== 0)
            {
                no= no/3;
            }
            else if(no % 5== 0)
            {
                no= no/5;
            }
            else
            {
                break;
            }
        }

        if(no== 1)
        {
           return true;
        }
    return false;
    }


    int nthUglyNumber(int n) {
     vector<int> uglyVector;
    
     int i= 1;
     while(uglyVector.size() !=  n)
     {
         if(isUgly(i))
         {
            uglyVector.push_back(i);
         } 
        i++; 
     }

    return uglyVector.back();
    }
};

*/