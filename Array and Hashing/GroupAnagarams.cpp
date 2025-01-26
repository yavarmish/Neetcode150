class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        // Hashing + Sorting Time: O(len(str)*n) (using counting sort) Space: O(n)
        unordered_map<string,vector<string>> m;
        for(auto &i:s) {
            string temp = i;
            sort(temp.begin(),temp.end());
            m[temp].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto &i:m) ans.push_back(i.second);
        return ans;
    }
};