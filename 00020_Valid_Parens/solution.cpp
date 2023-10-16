class Solution {
public:
    /// Strategy
    ///  - add open parens to the stack and pop as we receive close parens. If they don't match then it is invalid
    ///  - runtime linear
    ///  - space linear
    bool isValid(const string& s) {
        std::stack<char> stack;
        for (char c : s) {

            if (isOpen(c)) {
                stack.push(c);
                continue;
            } 

            // Invalid character I suppose
            if (!isClose(c)) {
                return false;
            }

            // No opens right now meaning this is imbalanced
            if (stack.empty()) {
                return false;
            }

            if (!isMatch(stack.top(), c)) {
                return false;
            }

            stack.pop();
        }

        return (stack.empty());
    }

    bool isOpen(const char c) {
        return (c == '(' || c == '{' || c == '[');
    }

    bool isClose(const char c) {
        return (c == ')' || c == '}' || c == ']');
    }

    bool isMatch(const char c1, const char c2) {
        return 
            (c1 == '(' && c2 == ')') ||
            (c1 == '{' && c2 == '}') ||
            (c1 == '[' && c2 == ']');
    }
};
