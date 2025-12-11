#include <stddef.h>
#include <stdio.h>
#include "binary_trees.h"

int recursive_solver(const binary_tree_t *tree);
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure depth
 * Return: depth or 0 if failure
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	/*
	 * checking if either the tree is null
	 * or if tree->parent is null then we will be at the root
	 * which is depth 0
	 */
	if (tree == NULL || tree->parent == NULL)
		return (0);

	/*return recursive_solver but convert to size_t*/
	return ((size_t) recursive_solver(tree));
}

/**
 * recursive_solver - wanted to use ints rather than size_t so we can
 * return -1 when tree == NULL
 * @tree: pointer to the node to measure
 * Return: depth
 */
int recursive_solver(const binary_tree_t *tree)
{
	/*base case*/
	if (tree == NULL)
		return (-1);

	/*recursive call to check until we've reached the root node*/
	return (recursive_solver(tree->parent) + 1);

}
