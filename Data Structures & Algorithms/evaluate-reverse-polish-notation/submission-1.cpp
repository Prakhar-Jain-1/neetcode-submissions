class Solution {
public:
    bool isnum(string s) {
        if (s.empty()) return false;

        int start = 0;

        if (s[0] == '-') {
            if (s.size() == 1) return false;
            start = 1;
        }

        for (int i = start; i < s.size(); i++) {
            if (!isdigit(s[i]))
                return false;
        }

        return true;
    }

    int tonum(string s) {
        int sign = 1;
        int start = 0;

        if (s[0] == '-') {
            sign = -1;
            start = 1;
        }

        int ret = 0;

        for (int i = start; i < s.size(); i++) {
            ret *= 10;
            ret += (s[i] - '0');
        }

        return sign * ret;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(string ops:tokens){
            if(isnum(ops)){
                s.push(tonum(ops));
            }
            else{
                int i = s.top();s.pop();
                int j = s.top();s.pop();
                switch (ops[0]) {
                    case '+':
                        s.push(i+j);
                        break;

                    case '-':
                        s.push(j-i);
                        break;
                    case '*':
                        s.push(i*j);
                        break;
                    case '/':
                        s.push(j/i);
                        break;

                    default:
                }
            }
        }
        return s.top();
    }
};
