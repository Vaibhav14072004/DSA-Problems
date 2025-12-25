// Approach 2 -> Using priority_heap
// TC= O(N* log N)+ O(N* log N)

class Solution{
 public:
   long long maximumHappinessSum(vector<int> &happiness, int k)
   {
       int n= happiness.size();
       long long ans= 0;
       priority_queue<int> maxHeap(happiness.begin(),happiness.end());


        int cnt= 0;
       while(!maxHeap.empty() && (k--))
       {
           int temp= maxHeap.top();
           maxHeap.pop();
           temp-= cnt;
           if(temp > 0) ans+= temp;
           cnt++;
       }
     return ans;  
   }
};




// Approach 1 -> Sorting
// TC= O(N* log N)+ O(N)

/*

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        int n= happiness.size();
        sort(happiness.rbegin(),happiness.rend());

        int cnt= 0;
        long long ans= 0;
        for(int i=0; i<k; i++)
        {
           int temp= (happiness[i]-cnt);
           if(temp > 0) ans+= temp;
           cnt++;
        }
      return ans;  
    }
};

*/