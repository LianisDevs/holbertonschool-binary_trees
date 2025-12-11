#include <stdio.h>
#include "binary_trees.h"
int recursive_solver(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to node to measure from
 * Return: balance or 0 on failure
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (recursive_solver(tree));
}

/**
 * recursive_solver - wanted to return -1 when tree == NULL
 * so using separate function to do the recursive calls
 * @tree: pointer to node to measure from
 * Return: balance
 */
int recursive_solver(const binary_tree_t *tree)
{
	int left, right = 0;

	if (tree == NULL)
		return (-1);

	/*this counts the height of the left side*/
	left = recursive_solver(tree->left);

	/*this counts the height of the right side*/
	right = recursive_solver(tree->right);

	/*returning left- right to give us the balance factor*/
	return (left - right);
}
