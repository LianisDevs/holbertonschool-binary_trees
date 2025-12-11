#include <stddef.h>
#include <stdio.h>
#include "binary_trees.h"

int recursive_solver(const binary_tree_t *tree);

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to root node of tree to measure
 * Return: height or 0 if failure
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/*if tree is empty*/
	if (tree == NULL)
		return (0);

	/*return recursive_sovlver but convert to size_t*/
	return ((size_t) recursive_solver(tree));
}

/**
 * recursive_solver - wanted to use ints rather than size_t for this
 * recursive function
 * @tree: pointer to root node of tree to measure
 * Return: height of tree as an int
 */
int recursive_solver(const binary_tree_t *tree)
{
	int left, right = 0;

	/*base case*/
	if (tree == NULL)
		return (-1);

	/*recursive calls*/
	left = recursive_solver(tree->left);
	right = recursive_solver(tree->right);

	/*
	 * using ternary operator to to return the greater value
	 * (almost like short hand for if else statement
	 * condition ? expression if true : expression if false
	 */
	return ((left > right) ? left + 1 : right + 1);
}

