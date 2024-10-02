// Approach 2 -> Sorting + Hashing
// TC= O(N log N) + O(N) + O(N)  ->>>> O(N log N)

class Solution{
  public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n= arr.size();

        // base case
        if(arr.size()== 0)
        {
            return {};
        }
        
        // {element, index}
        unordered_map<int,int> mp;
        
        vector<int> sortedArr= arr;
        sort(sortedArr.begin(),sortedArr.end());
        
        mp[sortedArr[0]]= 1;
        int cnt= 1;

        for(int i=1; i<n; i++)
        {
           if(sortedArr[i]!= sortedArr[i-1])
           { 
              cnt++;
           }
           mp[sortedArr[i]]= cnt;
        } 

        for(int i=0; i<n; i++)
        {
            arr[i]= mp[arr[i]];
        }
        return arr;
    }
};






// Approach 1 -> Using Priority_queue
// TC= O(N log N) + O(N) ->> O(n log n)
// SC= O(N)

/*

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n= arr.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<n; i++)
        {
           pq.push({arr[i],i});
        }
        
        vector<int> ans(n);
        int cnt= 1;
        int prev= -1;

        while(!pq.empty())
        {
            int curr= pq.top().first;
            int idx= pq.top().second;
            pq.pop();

            if(prev != curr)
            {
                ans[idx]= cnt++;
            }
            else
            {
                ans[idx]= cnt-1;
            }

            prev= curr;
        }
     return ans;   
    }
};

*/