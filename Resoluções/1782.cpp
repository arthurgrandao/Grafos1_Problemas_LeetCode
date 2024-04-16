class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {

        map<pair<int, int>, int> shared;
        vector<int> degree(n+1);

        for (auto & e : edges) {
            degree[e[0]]++;
            degree[e[1]]++;
            pair<int, int> p = {min(e[0], e[1]), max(e[0], e[1])};
            shared[p]++;
        }
        
        vector<int> sortedDegree = degree;
        vector<int> ans;
        sort(sortedDegree.begin(), sortedDegree.end());
        for (auto query : queries) {
            int sum = 0;    
            int l = 1, r = n;
            while (l < r) {
                if (sortedDegree[l] + sortedDegree[r] > query) {                     
                    sum += (r - l); 
                    r--;
                } else {
                    l++;
                }
            } 

            for (auto & s : shared) {
                if ((degree[s.first.first] + degree[s.first.second]) > query &&
                    (degree[s.first.first] + degree[s.first.second]) - s.second <= query)
                    sum--;
            }

            ans.push_back(sum);
        
        }
        return ans;
    }
};