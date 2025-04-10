// Approach 1 -> Using extra space + 2 Pointers
// TC= O(M*N)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int merged[n+m];

        int i=0, j=0, idx= 0;
        while(i< m && j < n)
        {
            if(nums1[i] <= nums2[j])
            {
                merged[idx++]= nums1[i++];
            }
            else
            {
                merged[idx++]= nums2[j++];
            }
        }

        // if nums1 is finished but nums2 is NOT
        while(j < n)
        {
            merged[idx++]= nums2[j++];
        }

        // if nums2 is finished but nums1 is NOT
        while(i < m)
        {
            merged[idx++]= nums1[i++];
        }

        // now copy elements of merged into nums1 
        for(int i=0; i<n+m; i++)
        {
            nums1[i]= merged[i];
        }
    }
};