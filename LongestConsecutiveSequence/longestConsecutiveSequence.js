/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

/**
 * @param {number[]} num
 * @return {number}
 */
var longestConsecutive = function(num) {
    var longest = 0;
    boundaries = {};

    num.forEach(function(num) {
        if (!boundaries[num]) {
            var left = boundaries[num - 1] || 0;
            var right = boundaries[num + 1] || 0;
            var length = left + right + 1;

            if (length > longest) longest = length;

            boundaries[num] = length;
            boundaries[num - left] = length;
            boundaries[num + right] = length;
        }
    });

    return longest;
};
