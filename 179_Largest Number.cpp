Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.



bool cmp(const string s1, const string s2) {
    return (s1 + s2) > (s2 + s1);
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> s_num(num.size());
        stringstream stream;
        for (int i = 0; i < num.size(); ++i) {
            stream << num[i];
            stream >> s_num[i];
            stream.clear();
        }
        sort(s_num.begin(), s_num.end(), cmp);
        string tmp_res;
        for (int i = 0; i < s_num.size(); ++i) {
            tmp_res += s_num[i];
        }
        string res;
        bool flag = false;
        for (int i = 0; i < tmp_res.size(); ++i) {
            if (tmp_res[i] != '0') {
                res.push_back(tmp_res[i]);
                flag = true;
            } else if (flag) {
                res.push_back(tmp_res[i]);
            }
        }
        if (!flag) res.push_back('0');
        return res;
    }
};