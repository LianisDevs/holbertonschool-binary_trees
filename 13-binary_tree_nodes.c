#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in binary tree
 * @tree: pointer to the node to count the number of nodes with children
 * Return: number of nodes or 0 on failure
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/*base case*/
	if (tree == NULL)
		return (0);

	/*
	 * checking if either tree->left or tree->right have children
	 * adding 1 and calling recursion
	 */
	if (tree->left != NULL || tree->right != NULL)
		return (1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));

	return (0);
}
