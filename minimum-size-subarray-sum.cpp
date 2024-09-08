class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int l = nums.size();
        vector<int> sum(l + 1, 0);
        for (int i = 1; i <= l; i++) {

            sum[i] = sum[i - 1] + nums[i - 1];
        }

        for (auto x : sum)
            cout << x << " ";
        cout << endl;
        int left = 1;
        int right = 1;
        int miniLength = INT_MAX;
        int flag = 0;
        while (left <= right && right <= l) {

            if (sum[right] - sum[left - 1] >= target) {

                flag = min(miniLength, right - left + 1);
                miniLength = flag;
                left += 1;

            } else {

                right += 1;
            }
        }

        return flag;
    }
};