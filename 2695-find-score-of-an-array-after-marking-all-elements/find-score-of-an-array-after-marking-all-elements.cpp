// Approach 2 ->> Using sorting+ separate vec for storing pair +visited vec
// TC= O(N log N) + O(2*N) ->> O(N log N)
// SC= O(2*N)

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        vector<int> visited(n, 0);

        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({nums[i],i});
        }

        sort(vec.begin(),vec.end());

        for(int i=0; i<n; i++)
        {
            int val= vec[i].first;
            int index= vec[i].second;

            if(visited[index]){
                continue;
            }

            score+= val;
            visited[index]= 1;

            if(index-1 >= 0){
                visited[index-1]= 1;
            }

            if(index+1 < n){
                visited[index+1]= 1;
            }
        }
      return score;
    }
};






// Approach 1 -> Using min heap + visited vector
// TC= O(N) + O(N log N) =-> O(N log N)
// SC= O(N+N) ->> O(N)

/*

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        vector<int> visited(n, 0);

        // min heap...
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int,int>>>pq;

        for (int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        while (!pq.empty()){
            int top = pq.top().first;
            int index = pq.top().second;
            pq.pop();

            if(visited[index]){
                continue;
            }
                score += top;
                visited[index] = 1;

                if(index-1 >= 0){
                    visited[index-1]= 1;
                }

                if(index+1 < n){
                    visited[index+1]= 1;
                }       
        }
      return score;
    }
};

*/