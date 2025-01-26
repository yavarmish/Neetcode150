class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {        
		// BruteForce Time: O(n^2) Space: O(1)
		for(int i = 0; i < nums.size(); ++i) {
			for(int j = i + 1; j < nums.size(); ++j) 
				if(nums[i] == nums[j]) return true;
		}
		return false;		
		
		// Sorting Time: O(n*log(n)) Space: O(1)
		sort(nums.begin(),nums.end());
		for(int i = 0; i < nums.size()-1 ; ++i) 
			if(nums[i] == nums[i+1]) return true;        
		return false;
		
		
		// Using set(hashing) Time: O(n) Space: O(n)
		unordered_set<int> s;
		for(auto &i : nums) {
			if(s.count(i)) return true;
			s.insert(i);
		}
		return false;
				
        // Alternative implementation
        unordered_set<int> s(nums.begin(),nums.end());
        return s.size() != nums.size();
		
        // Can use a hashmap as well
    }
};