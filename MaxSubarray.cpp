class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    long long sum = 0;
    long long maxi = INT_MIN;
    for (int x = 0; x < nums.size(); x++) {
      sum += nums[x];
      if (sum > maxi)
        maxi = sum;
      if (sum < 0)
        sum = 0;
    }

    return maxi;
  }
};

UPVOTE1.jpg
