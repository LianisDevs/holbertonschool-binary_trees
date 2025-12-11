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
	int left, right;

	if (tree == NULL)
		return (0);

	/*returns the greatest height of tree->left*/
	left = recursive_solver(tree->left);


	/*returns the greatest height of tree->right*/
	right = recursive_solver(tree->right);

	/*to get the balance factor= left - right*/
	return (left - right);
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

	/*
	 * using ternary operator to return the greater value
	 * condition ? expression if true : expression if false
	 */
	return ((left > right) ? left + 1 : right + 1);
}
