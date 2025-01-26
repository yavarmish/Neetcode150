class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {		
        // Bruteforce Time: O(n^2) Space: O(1)
        for(int i = 0; i < nums.size(); ++i) {
        	for(int j = i+1; j < nums.size(); ++j) 
        		if(nums[i]+nums[j] == target) return {i,j};
        }
        return {-1,-1};			

        // Sorting Time: O(n*log(n)), Space: O(n)
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();++i) {
        	v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i = 0, j = v.size() - 1;
        while(i<j) {
        	int n1 = v[i].first, n2 = v[j].first;
        	if(n1 + n2 == target) return {v[i].second,v[j].second};
        	else if(n1 + n2 < target) ++i;
        	else --j;
        }
		return {-1,-1};

		// Hashing(using map) Time: O(n) Space: O(n)
		unordered_map<int,int> m;
		for(int i = 0; i < nums.size(); ++i) {
			if(m.count(target - nums[i])) return {i, m[target - nums[i]]};			
			m[nums[i]] = i;
		}
		return {-1,-1};		
    }
};