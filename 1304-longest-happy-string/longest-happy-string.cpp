// Approach 1 -> Using priority_queue

// We have to use the char that has max freq every time...
// Considering the fact that no 3 consecutive 'a', 'b', 'c' come together

// TC= O(a+b+c)
// SC= O(a+b+c)

class Solution {
public:
    string longestDiverseString(int a, int b, int c)
    {
        // max heap
        priority_queue<pair<int,char>> pq;
        string ans= "";

        if(a> 0) pq.push({a,'a'});
        if(b> 0) pq.push({b,'b'});
        if(c> 0) pq.push({c,'c'});

            while(!pq.empty())
            {
                int maxFreq= pq.top().first;
                char ch= pq.top().second;
                pq.pop();
                
                // if we have already appended 2 consecutive 'a', 'b' or 'c'
                if(ans.size() >= 2 && ans.back()== ch && ans[ans.length()-2]== ch)
                {
                   // get the second mostfreq element..
                   if(!pq.empty())
                   {
                       int secondFreq= pq.top().first;
                       char secondCh= pq.top().second;
                       pq.pop();

                       ans+= secondCh;
                       if(secondFreq-1 > 0)
                       {
                          pq.push({secondFreq-1, secondCh});
                       }
                       
                    // push the max freq element back into pq after we have appended secondmost freq element
                       pq.push({maxFreq,ch});
                   }
             
                   else
                   {
                      break;
                   }
                }

                else
                {
                    ans+= ch;
                    if(maxFreq- 1 > 0)
                    {
                        pq.push({maxFreq-1, ch});
                    }
                }
            }
     return ans;   
    }
};