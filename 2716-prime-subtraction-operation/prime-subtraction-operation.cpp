// Ques of seive of Eronthesis -> TC= O(log log m)

/*
Why we are traversing from right bcoz if nums[i+1] > nums[i] then it always true
that nums[i-1] is always less than nums[i], hence maintaining the ascending
order

BUT if we travel from left to right, then it is NOT necessary that if nums[i] <
nums[i+1] then it is NOT necessary that nums[i+2] is still less than nums[i],
hence ascending order NOT maintained
*/

// Approach 1
// TC= O(N* maxNum) ~ O(N)

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        // sieve of eronthesis -> TC= O(log log m)
        vector<bool> isPrime(1001, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= 1000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 1000; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }

            bool flag = false;
            for (int no = 2; no <= nums[i] - 1; no++) {
                if (!isPrime[no]) {
                    continue;
                }

                if (nums[i] - no < nums[i + 1]) {
                    nums[i] = nums[i] - no;
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                return false;
            }
        }
        return true;
    }
};