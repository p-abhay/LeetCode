class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = 0;
        for (int i = 0; i < k; i++) total += cardPoints[i];
        int score = total;
        for (int i = k - 1, j = cardPoints.size() - 1; ~i; i--, j--)
            total += cardPoints[j] - cardPoints[i], score = max(score, total);
        return score;
    }
};