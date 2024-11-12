// Approach 2 -> Optimized (Sorting+ BinarySearch)
// TC= O(N* log N) + O(N) + O(q* log N)

class Solution{
public: 
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
         int q= queries.size();
         int n= items.size();

         // sort in ascending order of price
         sort(items.begin(),items.end());

         int maxBeauty= items[0][1];
        
         // update max beauty found till now directly in items vector
         for(int i=1; i<n; i++)
         {
             if(maxBeauty < items[i][1])
             {
                maxBeauty= items[i][1];
             }
             items[i][1]= maxBeauty;
         }
         
        vector<int> vec;
         for(int i=0; i<q; i++)
         {
             int price= queries[i];
             int maxBeauty= 0;

             // now apply binary search
             int start= 0;
             int end= n-1;

             while(start<= end)
             {
                 int mid= start+ (end-start)/2;
                 if(items[mid][0] <= price)
                 {
                    maxBeauty= items[mid][1];
                    start= mid+1;
                 }
                 else
                 {
                    end= mid-1;
                 }
             }

            vec.push_back(maxBeauty);
            // if(end >=0)  vec.push_back(items[end][1])
         }
         return vec;
    } 
};









// Approach 1 -> Brute Force Approach
// TC= O(q*n)

/*

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
         int q= queries.size();
         int n= items.size();

        vector<int> ans;
        for(int i=0; i<q; i++)
        {
            int price= queries[i];
             int maxi= 0;
            for(int j=0; j<n; j++)
            {
                if(items[j][0] <= price)
                {
                    maxi= max(maxi,items[j][1]);
                }
            }

            ans.push_back(maxi);
        }    
        return ans;
    }
};

*/