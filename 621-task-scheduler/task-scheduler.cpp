// Approach 2 -> Greedy Approach
// TC= O(N)

class Solution{
  public:
    int leastInterval(vector<char>& tasks, int n)
    {
        vector<int> freq(26,0);
        for(char it: tasks){
            freq[it-'A']++;
        }

        sort(freq.begin(),freq.end());

        int gaddhe= freq[25]-1;
        int idleSpots= n* (gaddhe);
        
        // now start from descending order and not from 25, bcoz we have allocated firstly the element having max freq
        for(int i=24; i>=0; i--)
        {
            if(freq[i] > 0)
            {
                idleSpots-= min(freq[i], gaddhe);
                if(idleSpots== 0)
                {
                    break;
                }
            }
        }
       
       if(idleSpots <= 0)
       {
          return tasks.size();
       }

       return tasks.size()+ idleSpots;
    }
};






// Approach 1 -> Using max heap (priority_queue)
// TC= O(N* log(26)) ->> O(N)

/*

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        int ans= 0;
        vector<int> freq(26,0);
        for(int i=0; i<tasks.size(); i++)
        {
            freq[tasks[i]-'A']++;
        }
        
        priority_queue<int> maxHeap;
        for(int i=0; i<26; i++)
        {
            if(freq[i] > 0){
               maxHeap.push(freq[i]);
            }
        }

        while(!maxHeap.empty())
        {
            // pop out n+1 elements from maxHeap
            vector<int> temp;
            for(int i=1; i<= n+1; i++)
            {
                if(!maxHeap.empty())
                {
                    int topFreq= maxHeap.top();
                    maxHeap.pop();
                    topFreq--;
                    temp.push_back(topFreq);
                }
            }

            // push the frequencies again in maxHeap if it is > 0
            for(int i=0; i<temp.size(); i++)
            {
                if(temp[i] > 0){
                    maxHeap.push(temp[i]);
                }
            }

            // if maxHeap becomes empty,means it is last element, no need of idle time
            if(maxHeap.empty())
            {
                ans+= temp.size();
            }
            else
            {
                ans+= (n+1);
            }
        }
     return ans;   
    }
};

*/