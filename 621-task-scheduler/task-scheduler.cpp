// Approach 1 -> Using max heap (priority_queue)
// TC= O(N* log(26)) ->> O(N)

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

