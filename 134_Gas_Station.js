// https://leetcode.com/problems/gas-station/
// 134. Gas Station

/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    sum = gas.reduce((pv, cv) => pv + cv, 0) - cost.reduce((pv, cv) => pv + cv, 0);
    if(sum < 0)
        return -1;

    total = 0;
    result = 0;
    for(i=0; i<gas.length; i++){
        total += (gas[i] - cost[i]);
        if(total < 0){
            total = 0;
            result = i + 1;
        }
    }
    return result;
};