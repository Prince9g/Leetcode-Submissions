class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    unordered_map<int, int> ball_colors;
    unordered_map<int, int> color_count;
    unordered_set<int> distinct_colors;
    vector<int> result;

    for (const auto& query : queries) {
        int ball = query[0];
        int color = query[1];

        if (ball_colors.find(ball) != ball_colors.end()) {
            int old_color = ball_colors[ball];
            color_count[old_color]--;
            if (color_count[old_color] == 0) {
                distinct_colors.erase(old_color);
            }
        }

        ball_colors[ball] = color;
        color_count[color]++;
        distinct_colors.insert(color);

        result.push_back(distinct_colors.size());
    }

    return result;
    }
};