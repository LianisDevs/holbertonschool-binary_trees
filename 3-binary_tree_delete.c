#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - deletes entire binary tree
 * @tree: pointer to root node of tree to delete
 * Return: nothing/ void
 */

void binary_tree_delete(binary_tree_t *tree)
{
	/*base case*/
	if (tree == NULL)
		return;
	/*recursive call for both sides of the tree*/
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);

	tree = NULL;
}
