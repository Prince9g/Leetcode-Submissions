 // Using unordered set.
 class Solution {
 public:
     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
         unordered_set<int>prefixes;
         for(int num:arr1){
             while(prefixes.find(num)==prefixes.end() && num>0){
                 prefixes.insert(num);
                 num/=10;
             }
        }
         int l=0;
         for(int num:arr2){
             while(prefixes.find(num)==prefixes.end() && num>0){
                 num/=10;
             }
             if(num>0){
             l=max(l,(int)log10(num)+1);
             }
         }
         return l;
     }
 };
