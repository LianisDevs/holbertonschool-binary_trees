#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node or NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = node->parent;

	if (node == NULL || parent == NULL)
		return (NULL);

	/*checking if only child*/
	if (parent->left == NULL || parent->right == NULL)
		return (NULL);

	/*checking what side the node belongs to on the parent*/
	if (parent->left == node)
		return (parent->right);

	return (parent->left);
}
