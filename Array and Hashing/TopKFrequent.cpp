class Solution {
public:
    /*
        Priority Queue STL
        Max Heap implementation(default) : priority_queue<int> q;
        Min Heap implementation          : priority_queue<int,vector<int>,greater<int>> q;
        Common Operations:
        top(),push(),pop(),size(),empty()
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {                
        unordered_map<int,int> freqMap;
        for(int &i : nums) 
            freqMap[i]++;

        // Priority queue(min heap implemenation) Time: O(n*log(k)) Space: O(n)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> TopKElements;
        for(auto &[num, freq] : freqMap) {
            if(TopKElements.size() == k) {
                if(TopKElements.top().first < freq) {
                    TopKElements.pop();
                    TopKElements.push({freq, num});
                }
            }
            else TopKElements.push({freq, num});
        }
        vector<int> ans;
        while(TopKElements.size()) {
            ans.push_back(TopKElements.top().second);
            TopKElements.pop();
        }
        return ans;

        // Can also use max heap implementation Time: O(n*log(n-k)) Space: O(n)

        // Bucket Sort Time: O(n) Space: O(n). Observation: Frequency range -> 0 to n
        int n = nums.size();
        vector<vector<int>> freqBucket(n+1);
        for(auto &[num,freq] : freqMap) {
            freqBucket[freq].push_back(num);
        }
        vector<int> ans;
        for(int i = n; i >= 0 and k > 0; --i) {            
            for(int &num : freqBucket[i]) {
                if(k == 0) break;
                --k;
                ans.push_back(num);
            }
        }
        return ans;        
    }
};