    int maximumWidth(vector<int>& A) {
        unordered_map<int, int> count, res;
        for (int x : A) {
            count[x]++;
            res[x]++;
        }

        for (auto const& pair_a : count) {
            for (auto const& pair_b : count) {
                int a = pair_a.first, b = pair_b.first;
                if (a < b) {
                    res[a + b] += min(count[a], count[b]);
                }
                if (a == b) {
                    res[a + b] += count[a] / 2;
                }
            }
        }

        int max_val = 0;
        for (auto const& pair : res) {
            max_val = max(max_val, pair.second);
        }

        return max_val;
    }