// Approach 2 -> Using Max Heap
// TC= O(N) + O(26) + O(26* (log26+ N)) ->> O(N)
// SC= O(26)->> O(1)

class Solution {
public:
    string repeatLimitedString(string str, int repeatLimit) {
        int n= str.length();
        vector<int> freq(26,0);

        // max heap to give highest lexographically char that has freq>0
        priority_queue<char> pq;

        for(int i=0; i<n; i++)
        {
            freq[str[i]-'a']++;
        }
        
        // put all characters in max heap having freq>0
        for(int i=0; i<26; i++)
        {
            if(freq[i] > 0)
            {
                char ch= i+'a';
                pq.push(ch);
            }
        }
        
        string ans= "";
        while(!pq.empty())
        {
            char top= pq.top();
            // push pop operations takes log(26)
            pq.pop();

            int cnt= min(freq[top-'a'],repeatLimit);

            // appending takes O(N) time
            ans.append(cnt,top);      
            freq[top-'a']-= cnt;
            
            // if freq is still > 0, add prev char in between
            if(freq[top-'a'] > 0 && !pq.empty())
            {
                int nextCh= pq.top();
                pq.pop();

                ans+= nextCh;
                freq[nextCh-'a']--;
                
                if(freq[nextCh-'a'] > 0)
                {
                    pq.push(nextCh);
                }
               pq.push(top); 
            }
        }
    return ans;
    }
};







// Approach 1 -> Sliding Window
// TC= O(N) + O(26 + N)  ->> O(N)
// SC= O(26) -> O(1)

// ans+=string(cnt,ch) or ans.append(cnt,ch) ->> Takes O(N) time

/*

class Solution {
public:
    string repeatLimitedString(string str, int repeatLimit) {
        int n= str.length();
        vector<int> freq(26,0);

        for(int i=0; i<n; i++)
        {
            freq[str[i]-'a']++;
        }

        int j= 25;
        string ans= "";
        while(j >=0)
        {
            if(freq[j]== 0)
            {
                j--;
                continue;
            }

            int cnt= min(freq[j],repeatLimit);
            char ch= j + 'a';
            ans+= string(cnt, ch);  // Takes O(N) Time 
            // ans.append(cnt, ch);

            freq[j]-= cnt;

            // now append one previous char..
                if(freq[j] > 0)
                {
                   int i= j-1;
                   while(i>=0 && freq[i]== 0)
                   {
                      i--;
                   }

                   if(i< 0)
                     break;

                   ans+= (char) (i+ 'a');
                   freq[i]--;
                }
        }
        return ans;
    }
};

*/