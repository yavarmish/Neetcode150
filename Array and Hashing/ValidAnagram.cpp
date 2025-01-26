class Solution {
public:
    bool isAnagram(string s, string t) {
		
		// Sorting Time: O(n*log(n)) Space: O(1)
		sort(s.begin(),s.end());sort(t.begin(),t.end());
		return s == t;		
		
        // Hasing Map using array: O(n) Space: O(n);
        vector<int> f(26,0);
		for(auto &i:s) ++f[i-'a'];
		for(auto &i:t) --f[i-'a'];
		return count(f.begin(),f.end(),0) == f.size();
    }
};