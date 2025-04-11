class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int result = 0;

        for(int i = low; i <= high; i++) {
            string numStr = to_string(i);

            //if number length not even, it cannot be symmetric
            if(numStr.size() % 2 != 0) continue;

            //Calculate left and right sums
            int leftSum = 0, rightSum = 0, halfSize = numStr.size() / 2;
            for(int i = 0; i < halfSize; i++) {
                leftSum += numStr[i] - '0';
                rightSum += numStr[i + halfSize] - '0';
            }

            if(leftSum == rightSum) result++;
        }

        return result;
    }
};