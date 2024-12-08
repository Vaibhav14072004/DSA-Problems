class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        int maxValue = 0; 
        int result = 0; 

        for (const auto& event : events) {
            int start = event[0];
            int end = event[1];
            int value = event[2];
            
            while (!pq.empty() && pq.top().first < start) {
                maxValue = max(maxValue, pq.top().second);
                pq.pop();
            }
            result = max(result, value + maxValue);
            result = max(result, value);
            pq.push({end, value});
        }
        
        return result;
    }
};