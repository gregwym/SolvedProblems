/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

/**
 * @param {string} str
 * @return {boolean}
 */

var isAlphanumeric = function(char) {
    return (char >= 'a' && char <= 'z') || (char >= 'A' && char <= 'Z') || (char >= '0' && char <= '9');
};

var isPalindrome = function(str) {
    var i = 0;
    var j = str.length - 1;
    var left, right;
    while(i < j) {
        left = str.charAt(i);
        right = str.charAt(j);
        if (!isAlphanumeric(left)) {
            i++;
            continue;
        }
        if (!isAlphanumeric(right)) {
            j--;
            continue;
        }

        if (left.toLowerCase() !== right.toLowerCase()) return false;
        i++;
        j--;
    }

    return true;
};
