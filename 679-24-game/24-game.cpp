class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        const string kOps = "+-*/";
        const int D = cards.size();
        const int kOpsN = D - 1;
        const int kMaxMask = 1 << (2 * kOpsN);

        // Sort cards to enable systematic permutation enumeration
        ::sort(cards.begin(), cards.end());
        string ops(kOpsN, '\0');
        vector<int> ops_order(kOpsN);

        // Expression evaluator using precedence-aware stack-based algorithm
        // Handles operator precedence by deferring low-precedence operations
        auto calc_expr = [D, kOpsN, &cards, &ops, &ops_order,
                          args_stk = vector<double>(),
                          ops_stk = vector<int>()]() mutable -> double {
            args_stk.clear();
            ops_stk.clear();
            // Process numbers and operators left-to-right with precedence handling
            for (int i = 0; i < D; ++i) {
                if (i)
                    ops_stk.push_back(i - 1);  // Push operator index
                args_stk.push_back(cards[i]);
                // Execute pending operations with higher precedence
                // This maintains correct evaluation order according to operator precedence
                while (ops_stk.size() && (i == kOpsN || ops_order[ops_stk.back()] < ops_order[i])) {
                    double arg_b = args_stk.back();
                    args_stk.pop_back();
                    if (!exec(args_stk.back(), ops[ops_stk.back()], arg_b)) return -1;
                    ops_stk.pop_back();
                }
            }
            return args_stk.back();
        };

        // Exhaustive search over all possible configurations
        // Three nested loops cover the complete solution space
        do {
            // Enumerate all operator combinations using bit manipulation
            // Each operator needs 2 bits (4 possibilities: +, -, *, /)
            for (int mask = 0; mask < kMaxMask; ++mask) {
                for (int i = 0; i < kOpsN; ++i) {
                    ops[i] = kOps[(mask >> (i * 2)) & 3];
                    ops_order[i] = i;  // Initialize precedence order
                }
                // Try all precedence orderings for current operator combination
                // This simulates different parenthesization patterns
                do {
                    if (::abs(calc_expr() - kWant24) < kEps) return true;
                } while (::next_permutation(ops_order.begin(), ops_order.end()));
            }
        } while (::next_permutation(cards.begin(), cards.end()));  // Try all card arrangements

        return false;
    }

private:
    static constexpr double kEps = 1e-5;
    static constexpr double kWant24 = 24;

    // Execute binary operation with division-by-zero protection
    inline static bool exec(double& arg_a, char op, double arg_b) {
        switch (op) {
        case '+':
            arg_a = arg_a + arg_b;
            return true;
        case '-':
            arg_a = arg_a - arg_b;
            return true;
        case '*':
            arg_a = arg_a * arg_b;
            return true;
        case '/':
            if (::abs(arg_b) < kEps) return false;  // Prevent division by zero
            arg_a = arg_a / arg_b;
            return true;
        default:
            return false;
        }
    }
};