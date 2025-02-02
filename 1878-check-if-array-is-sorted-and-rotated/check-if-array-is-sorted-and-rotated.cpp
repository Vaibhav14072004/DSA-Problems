/*         4 Case EXISTS  => check
 (nums[i-1] > nums[0]) { cnt++ }
 (nums[n-1] > nums[0]) {cnt++}
    

1st ->> [1,2,3,4,5] =>sorted  ............. count= 1
2nd =>  [4,5,1,2,3] => sorted and rotated  ....... count= 1
3rd =>  [1,1,1] => equal elements ..........  count= 0

// return false
4th =>  [3,5,7,1,6] =>> Neither sorted NOR Rotated  ... count= 2 > 1

*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n= nums.size();
       int count= 0;

        for(int i=1; i<n; i++){
            
            if(nums[i-1] > nums[i]){
        count++;
            }
        }

        if(nums[n-1] > nums[0]){
            count++;
        }

        if(count<=1){
            return true;
        }
        return false;
    }
};