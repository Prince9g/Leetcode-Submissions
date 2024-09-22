class Solution {
public:
int findKthNumber(int n, int k) {
    auto count_steps = [&](long long prefix, long long n) -> int {
        int steps = 0;
        long long first = prefix, last = prefix;
        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    };

    int curr = 1;
    k--; // We start from 1, so we decrease k by 1.
    while (k > 0) {
        int steps = count_steps(curr, n);
        if (steps <= k) {
            curr++;
            k -= steps;
        } else {
            curr *= 10;
            k--;
        }
    }
    return curr;
}

};