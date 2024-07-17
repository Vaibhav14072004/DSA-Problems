// TC= O(2* N)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> sett(nums1.begin(), nums1.end());
        
       // {element of nums1, Next Greater element}
        unordered_map<int,int> mp;
        
        stack<int> st;
        for(int i= nums2.size()-1; i>= 0; i--)
        {
            // if this element is also present in nums1, find nge for it..
            if(sett.find(nums2[i]) != sett.end())
            { 
                while(!st.empty() && st.top() <= nums2[i])
                {
                    st.pop();
                }  

                if(!st.empty())
                {
                    mp[nums2[i]]= st.top();
                }
                else
                {
                    mp[nums2[i]]= -1;
                }
            }
        
        // push all elements in stack...
        st.push(nums2[i]);
        }
    
    vector<int> ans;
    for(int i=0; i<nums1.size(); i++)
    {
        ans.push_back(mp[nums1[i]]);
    }
     return ans;
    }
};