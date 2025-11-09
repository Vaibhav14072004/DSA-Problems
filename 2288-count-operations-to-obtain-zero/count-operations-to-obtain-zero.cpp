class Solution {
public:
    int countOperations(int nums1, int nums2) {
        int cnt= 0;
        while(true)
        {
            if(nums1== 0 || nums2== 0) break;

            if(nums1 >= nums2)
            {
                nums1-= nums2;
                cnt++;
            }
            else
            {
                nums2-= nums1;
                cnt++;
            }
        }
    return cnt;    
    }
};