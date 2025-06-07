// Approach 2 -> Using 




// Approach 1 -> Using min heap
// TC= O(N log N)

class Solution {
public:
    string clearStars(string str) {
        int n= str.length();

        // lambda function...
        auto cmp= [] (const pair<char,int> &a, const pair<char,int> &b)
        {
            // if chars of both a and b are equal, sort in descending order of index
            if(a.first== b.first){
               return a.second < b.second;
            }

            // else in ascending order of character
          return a.first > b.first;
        };

        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(cmp)> pq;
        for(int i=0; i<n; i++)
        {
            if(str[i]== '*')
            {
                if(!pq.empty())
                {
                    int idx= pq.top().second;
                    pq.pop();
                    str[idx]= '*';
                }
            }
            else
            {
               pq.push({str[i],i});
            }
        }

        string ans= "";
        for(int i=0; i<n; i++)
        {
            if(str[i]== '*') continue;
            ans+= str[i];
        }
      return ans;  
    }
};