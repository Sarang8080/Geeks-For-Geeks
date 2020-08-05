int cost(vector<int> B)
{
    int left = 0, right = 0;
    for (int i = 1; i < B.size(); ++i)
    {
        int leftOld = left, rightOld = right;
        left = max(leftOld, rightOld + B[i - 1] - 1);
        right = max(rightOld + B[i - 1] - B[i], leftOld + B[i] - 1);
    }
    return max(left, right);
}