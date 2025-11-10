class Solution {
public:
    static int minOperations(vector<int>& nums) {
        size_t curr_stack_len{0};
        int count{0};

        for (const int &num: nums) {
            if (num == 0) {
                count += static_cast<int>(curr_stack_len);
                curr_stack_len = 0;
            } else {
                while (curr_stack_len > 0 && nums[curr_stack_len - 1] > num) {
                    count += 1;
                    curr_stack_len -= 1;
                }

                if (curr_stack_len > 0 && nums[curr_stack_len - 1] == num) {
                    continue;
                }

                nums[curr_stack_len] = num;
                curr_stack_len += 1;
            }
        }

        return count + static_cast<int>(curr_stack_len);
    }
};