#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to node of tree to measure the size
 * Return: size or 0 if failure
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/*checking if it's a leaf*/
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/*recursive call adding left and right together*/
	return (binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);

}
