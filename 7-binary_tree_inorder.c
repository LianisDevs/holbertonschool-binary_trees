#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: pointer to the root of the tree
 * @func: pointer to a function to call for each node
 * Return: nothing/void
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/*
	 * recursive call to traverse to the left most leaf
	 * pass func so it lets you do the thing
	 */
	binary_tree_inorder(tree->left, func);

	/*do the thing*/
	func(tree->n);

	/*
	 * recursive call to traverse to the right
	 * pass func so it lets you do the thing
	 */
	binary_tree_inorder(tree->right, func);
}
