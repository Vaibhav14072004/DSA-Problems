// Approach 3 ->> Storing invalid index + Binary Search
// TC= O(Q* log N)

class Solution {
public:

// binary Search func to check whether invalidIndex found in this range or NOT
    bool invalidIndex_found(int startPt, int endPt,vector<int> &invalidIndex)
    {
        int start= 0;
        int end= invalidIndex.size()-1;

         while(start <= end)
         {
            int mid= start+ (end-start)/2;
            if(invalidIndex[mid] < startPt)
            {
                start= mid+1;
            }
            else if(invalidIndex[mid] > endPt)
            {
               end= mid-1;
            }
            else
            {
                return true;
            }
         }
      return false;
    }


    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        int q= queries.size();
        vector<bool> ans(q,true);
        
        vector<int> invalidIndex;
        for(int i=1; i<n; i++)
        {
            if(nums[i-1] % 2 == nums[i] % 2)
            {
                invalidIndex.push_back(i);
            }
        }

        // if no invalid index found..
        if(invalidIndex.empty()){
            return ans;
        }

        for(int i=0; i<q; i++)
        {
            int startPt= queries[i][0];
            int endPt= queries[i][1];
            
            // apply binary Search to find whether any invalid index lies in this range (start+1 to end)
            if(invalidIndex_found(startPt+1 ,endPt,invalidIndex))
            {
               ans[i]= false;
            }
        }
        return ans;
    }
};










// Approach 2 -> By storing valid index for every index
// TC= O(2*N + Q) =>> O(N+Q)

/*

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        int q= queries.size();
        vector<int> validEndIndex(n);

        int i=0, j= 0;

        // store valid end index for every index..
        while(i < n)
        {
            if(j < i){
               j= i;
            }

            while(j+1 < n && (nums[j] % 2 != nums[j+1] % 2)){
                j++;
            }

            validEndIndex[i]= j;
            i++;
        }
        
        vector<bool> ans(q,false);
        for(int i=0; i<q; i++)
        {
            int start= queries[i][0];
            int end= queries[i][1];

            if(end <= validEndIndex[start])
            {
                ans[i]= true;
            }
        }
    return ans;
    }
};

*/










// Approach 1 -> Using Prefix sum for how many invalid idx are there till now..
// TC= O(N+Q)

/*

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        
        // to store how many invalid idx found till now...
        vector<int> prefix(n);
        prefix[0]= 0;
        
        for(int i=1; i<n; i++)
        {
            if(nums[i-1] % 2== nums[i] % 2)
            {
                prefix[i]= 1+ prefix[i-1];
            }
            else
            {
                prefix[i]= prefix[i-1];
            }
        }
        
        int q= queries.size();
        vector<bool> ans(q,false);

        for(int i=0; i<q; i++)
        {
            int start= queries[i][0];
            int end= queries[i][1];
            
            // means no invalid index found in above range..
            if(prefix[end]-prefix[start]== 0)
            {
                ans[i]= true;
            }
        }
        return ans;
    }
};

*/