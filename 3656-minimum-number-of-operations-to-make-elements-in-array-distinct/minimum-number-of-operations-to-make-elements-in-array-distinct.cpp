// Approach 2 -> Optimized
// TC= O(N)

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(int i=n-1; i>=0; i--)
        {
           if(st.count(nums[i]))
           {
              return ceil((i+1)/3.0);
           }
           st.insert(nums[i]);
        }
      return 0;  
    }
};





// Approach 1 -> Brute Force Approach
// TC= O(N^2)

/*

class Solution {
public:
    bool checkDuplicate(int i,vector<int> &nums)
    {
        unordered_set<int> st;
        for(int j=i; j<nums.size(); j++)
        {
            if(st.count(nums[j]))
            {
                return true;
            }
            st.insert(nums[j]);
        }
        return false;
    }

    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt= 0;

        for(int i=0; i<n; i+=3)
        {
           if(checkDuplicate(i,nums))
           {
              cnt++;
           } 
           else
           {
              return cnt;
           }
        }
    return cnt;
    }
};

*/








/*

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
     
       unordered_map<int,int> mp;
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++; 
            q.push(nums[i]);
        }


        int ans= 0;
        while(!q.empty())
        {
            bool duplicate= false;
            
             for(auto it: mp)
             {
                // if duplicate found...
                if(it.second > 1)
                {
                    duplicate= true;
                    break;
                }
             }

                 if(duplicate== false)
                 {
                     break;
                 }
                
                    int k= 3;
                    while(!q.empty() && k--)
                    {
                      int front= q.front();
                        q.pop();
                        mp[front]--;

                        if(mp[front]== 0)
                        {
                            mp.erase(front);
                        }
                    }
                ans++;
         }
       return ans; 
    }
};

*/