/*
 * https://leetcode.com/problems/single-number-II/
 *
 * Given an array of integers, every element appears three times except for one. Find that single one.
 * Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

/**
 * @param {number[]} A
 * @return {number}
 */
var singleNumber = function(A) {
    var xor = 0;
    var carry = 0;
    var reset = 0;

    A.forEach(function(num) {
        carry = carry | (xor & num);
        xor = xor ^ num;
        reset = carry & xor;
        xor = xor ^ reset;
        carry = carry ^ reset;
    });

    return xor;
};
