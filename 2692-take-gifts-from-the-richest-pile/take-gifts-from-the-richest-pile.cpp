// Ques of Max Heap
// TC= O(N log N) + O(N)

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k){
        int n= gifts.size();

        // max heap to get max value at top at each iteration..
        priority_queue<int> pq(gifts.begin(),gifts.end());

        while(!pq.empty() && k--)
        {
            int maxi= pq.top();
            pq.pop();
            pq.push(sqrt(maxi));
        }

        long long sum= 0;
        while(!pq.empty())
        {
            sum+= pq.top();
            pq.pop();
        }
        return sum;
    }
};