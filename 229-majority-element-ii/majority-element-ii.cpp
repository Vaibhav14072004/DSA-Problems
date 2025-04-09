// Approach 2 -> Moore Voting algorithm
// TC= O(2*N)
// SC= O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int cnt1= 0, cnt2= 0;
        int element1, element2;
        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            if(cnt1== 0 && nums[i] != element2)
            {
                cnt1= 1;
                element1= nums[i];
            }
            else if(cnt2== 0 && nums[i] != element1)
            {
                cnt2= 1;
                element2= nums[i];
            }
            else if(nums[i]== element1)
            {
                cnt1++;
            }
            else if(nums[i]== element2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
    
    // now again cross verify whether element1 & 2 both appear more than n/3 times
    cnt1= 0, cnt2= 0;
    for(int i=0; i<n; i++)
    {
        if(nums[i]== element1) cnt1++;
        else if(nums[i]== element2) cnt2++;
    }

    if(cnt1 > n/3)
    {
        ans.push_back(element1);
    }
    if(cnt2 > n/3)
    {
        ans.push_back(element2);
    }

    return ans;
  }
};







// Approach 1 -> Using unordered_map
// TC= O(N)
// SC= O(N)

/*

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> mp;
        int needed= n/3;
        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > needed)
            {
                if(ans.empty())
                {
                    ans.push_back(nums[i]);
                }
                else if(ans.back() != nums[i])
                {
                    ans.push_back(nums[i]);
                }

                if(ans.size()== 2)
                {
                    break;
                }
            }
        }
        return ans;
    }
};

*/