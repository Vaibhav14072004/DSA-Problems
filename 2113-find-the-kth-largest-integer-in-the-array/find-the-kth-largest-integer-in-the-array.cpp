// kth largest element ->> use min heap
// Kth smallest element ->> use max heap

//  stoi()  ->> to convert string to integer...
//  stoll() ->> to convert string to long long...
//  stod()  ->> to convert string to double...
//  to_string() ->> to convert integer to string...


// Approach 2 -> Making a comparator function for priority_queue
// TC= O(n log k)

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k)
    {
        int n= nums.size();

        auto cmp= [](string &a, string &b)
        {
            if(a.size() == b.size())
            {
                return a > b;   // sort in descending order..
            }
            return a.size() > b.size();
        };

        // min heap with custom comparator...
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);

        for(int i=0; i<n; i++)
        {
            pq.push(nums[i]);
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
       return pq.top(); 
    }
};










/*   ...... Giving Runtime error .... 

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k)
    {
        int n= nums.size();

        // min heap ->> smallest element on top..
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for(auto ch: nums)
        {
            pq.push(stoll(ch));

            if(pq.size() > k)
            {
                pq.pop();
            }
        } 

      return to_string(pq.top());  
    }
};

*/