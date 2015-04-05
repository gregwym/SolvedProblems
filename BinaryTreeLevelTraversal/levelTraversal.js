/**
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 *
 * Definition for binary tree
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @param {TreeNode} root
 * @returns {number[][]}
 */
var levelOrder = function(root) {
    var queue = [root];
    var levels = [];
    var level = null;
    while(queue.length) {
        var node = queue.shift();
        if (node) {
            if (!level) {
                queue.push(null);
                level = [];
                levels.push(level);
            }
            level.push(node.val);
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        } else {
            level = null;
        }

        if (!queue.length) {
            break;
        }
    }
    return levels;
};
