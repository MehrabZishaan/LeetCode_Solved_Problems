// https://leetcode.com/problems/gas-station/
// 134. Gas Station

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int total = 0;
        int currentSum = 0;
        int startStation = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int diff = gas[i] - cost[i];
            total += diff;
            currentSum += diff;

            if (currentSum < 0) {
                currentSum = 0;
                startStation = i + 1;
            }
        }

        return (total < 0) ? -1 : startStation;
    }
};