Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
'

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(1,1);
        for(int i=1; i<=rowIndex; i++) {
            result.push_back(1);
            for(int j=result.size()-2; j>0; j--)
                result[j] += result[j-1];
        }
        return result;
    }
};