#include <stdio.h>
#include "binary_trees.h"

int recursive_solver(const binary_tree_t *tree);
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the node to check
 * Return: 1 if true 0 if false
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (recursive_solver(tree) == 0)
		return (1);

	return (0);
}

/**
 * recursive_solver - handles recursive call
 * @tree: pointer to the node to check
 * Return: 0 if tree's nodes have either 0 or 2 leaves else 1
 */
int recursive_solver(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	/*check if it's a leaf*/
	if (tree->right == NULL && tree->left == NULL)
		return (0);

	/*check if it has 1 child*/
	if (tree->right == NULL || tree->left == NULL)
		return (1);
	/*continue to traverse*/
	if (tree->right != NULL && tree->left != NULL)
	{
		left += recursive_solver(tree->left);
		right += recursive_solver(tree->right);
	}

	return (left + right);
}
