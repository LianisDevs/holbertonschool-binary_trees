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
	int left, right;

	if (tree == NULL)
		return (0);

	left = recursive_solver(tree->left);
	right = recursive_solver(tree->right);

	if (left == right)
		return (1);
	return (0);
}

/**
 * recursive_solver - handles recursive call
 * @tree: pointer to the node to check
 * Return: 0 if tree's nodes have either 0 or 2 leaves
 */
int recursive_solver(const binary_tree_t *tree)
{
	int left, right = 0;

	if (tree == NULL || (tree->right != NULL && tree->left != NULL))
		return (0);

	left = recursive_solver(tree->left);
	right = recursive_solver(tree->right);

	return ((left > right) ? left + 1 : right + 1);
}
