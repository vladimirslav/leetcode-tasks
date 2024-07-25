#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// https://leetcode.com/problems/binary-tree-maximum-path-sum

/**
 * Definition for a binary tree node.
 */
   struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };
 /*
 */
class Solution {
public:

	int maxStraightSum = 0;

	int calculateMaxOnePathSum(TreeNode* node)
	{
		if (node->left == NULL && node->right == NULL)
		{
			if (node->val > maxStraightSum)
			{
				maxStraightSum = node->val;
			}

			return node->val;
		}

		int leftVal = 0;
		int rightVal = 0;
		if (node->left != NULL)
		{
			leftVal = calculateMaxOnePathSum(node->left);
		}

		if (node->right != NULL)
		{
			rightVal = calculateMaxOnePathSum(node->right);
		}

		int lSum = node->left != NULL ? leftVal + node->val : node->val;
		int rSum = node->right != NULL ? rightVal + node->val : node->val;

		int maxPathSum = std::max({ lSum, rSum, node->val });

		vector<int> maxValRoute;

		int totalSum = node->val;
		if (node->left != NULL)
		{
			maxValRoute.push_back(leftVal);
			totalSum += leftVal;
		}

		if (node->right != NULL)
		{
			maxValRoute.push_back(rightVal);
			totalSum += rightVal;
		}

		maxValRoute.push_back(totalSum);

		int maxCombinedSum = *std::max_element(maxValRoute.begin(), maxValRoute.end());
		int maxTwo = std::max(maxPathSum, maxCombinedSum);

		if (maxTwo > maxStraightSum)
		{
			maxStraightSum = maxTwo;
		}

		return maxPathSum;
	}

	int maxPathSum(TreeNode* root) {
		maxStraightSum = root->val;
		return std::max(maxStraightSum, calculateMaxOnePathSum(root));
	}
};

int main()
{
	Solution s;

	std::cout << s.maxPathSum(new TreeNode(1, new TreeNode(2), new TreeNode(3)));

	return 0;
}