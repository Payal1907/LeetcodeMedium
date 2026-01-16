class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;
        //boundary
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> hDiffs;
        //storing all dist b/w any two fences
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hDiffs.insert(hFences[j] - hFences[i]);
            }
        }

        long long mx = -1;
        //agr whi distances vertical me mil gye to wo count kr lenge
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                long long diff = vFences[j] - vFences[i];
                if (hDiffs.count(diff)) {
                    mx = max(mx, diff);
                }
            }
        }

        return mx==-1?-1:((mx*mx) % MOD);
    }
};
