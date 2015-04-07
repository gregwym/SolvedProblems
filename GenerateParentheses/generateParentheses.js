/*
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

/**
 * @param {number} n
 * @returns {string[]}
 */
var generateParenthesis = function(n) {
    var generate = function(opened, closed) {
        if (opened === n && closed === n) return [''];

        var opening = [];
        if (opened < n) {
            opening = generate(opened + 1, closed).map(function(surfix) {
                return '(' + surfix;
            });
        }

        var closing = [];
        if (closed < opened) {
            closing = generate(opened, closed + 1).map(function(surfix) {
                return ')' + surfix;
            });
        }

        return opening.concat(closing);
    };

    return generate(0, 0);
};
