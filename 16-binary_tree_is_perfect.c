#include <stdio.h>
#include "binary_trees.h"

int recursive_is_full(const binary_tree_t *tree);
int recursive_is_balance(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 *
 * perfect tree= balanced and full
 * balanced tree meaning all leaf nodes are at the same level
 * full tree all nodes have 2 leaves
 *
 * @tree: pointer to the node to check
 * Return: 1 if true 0 if false
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == 0)
		return (0);

	left = recursive_is_balance(tree->left);
	right = recursive_is_balance(tree->right);

	if (left != right)
		return (0);

	/*if the tree isn't full return 1 it's false*/
	if (recursive_is_full(tree) != 0)
		return (0);

	return (1);
}

/**
 * recursive_is_full - handles recursive calli to check if tree is full
 * @tree: pointer to the node to check
 * Return: 0 if tree's nodes all have 2 leaves else 1
 */
int recursive_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	if (tree->left == NULL || tree->right == NULL)
		return (1);

	if (tree->right != NULL && tree->left != NULL)
	{
		left += recursive_is_full(tree->left);
		right += recursive_is_full(tree->right);
	}

	return (left + right);
}

/**
 * recursive_is_balance - handles recurisve call to check if tree is balanced
 * @tree: pointer to the node to check in tree
 * Return: balance or 0
 */
int recursive_is_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (-1);

	left = recursive_is_balance(tree->left);
	right = recursive_is_balance(tree->right);

	return ((left > right) ? left + 1 : right + 1);
}
