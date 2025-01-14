class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int>first, second;
        int i=0,j=0;
        vector<int>ans;
        int count = 0;
        int m = A.size();
        int n = B.size();
        while(i<m && j<n){
            if(second.find(A[i]) != second.end()){
                count++;
            }
            if(first.find(B[j]) != first.end()){
                count++;
            }
            if(A[i] == B[j]) count++;
            ans.push_back(count);
            first.insert(A[i]);
            second.insert(B[j]);
            i++;j++;
        }
        return ans;
    }
};