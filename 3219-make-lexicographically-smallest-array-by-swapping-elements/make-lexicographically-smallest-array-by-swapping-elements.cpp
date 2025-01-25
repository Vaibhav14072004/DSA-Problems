#define pi pair<int,int>
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        priority_queue<pi, vector<pi>, greater<pi>> minheap;
        for(int i = 0;i<nums.size();i++) minheap.push({nums[i],i});

        while(!minheap.empty()){
            pi temp = minheap.top();
            multiset<int> value, index;
            while(!minheap.empty() && temp.first + limit >= minheap.top().first){
                pi t = minheap.top(); minheap.pop();
                value.insert(t.first); index.insert(t.second);
                temp = t;
            }

            auto it1 = index.begin();  auto it2 = value.begin();
            while(it1 != index.end()){
                nums[*it1] = *it2;
                it1++; it2++;
            }
        }return nums;
    }
};