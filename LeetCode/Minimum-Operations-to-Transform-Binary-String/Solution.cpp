    int minOperations(string s1, string s2) {
        if (s1 == "1" && s2 == "0") {
            return -1;
        }
        int res = 0, n = s1.length();
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i])
                continue;
            if (s1[i] == '0') {
                res++;
            } else if (i < n - 1) {
                res += s1[i + 1] == '1' ? 1 : 2;
                s1[i + 1] = '0';
            } else {
                res += 2;
            }
        }
        return res;
    }