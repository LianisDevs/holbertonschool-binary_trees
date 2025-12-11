#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of the node
 * @node: node to find their uncle
 * Return: pointer to uncle or NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grand_parent, *parent;

	if (node == NULL ||
			node->parent == NULL
			||
			node->parent->parent == NULL)
		return (NULL);

	parent = node->parent;

	grand_parent = node->parent->parent;

	/*checking if parent is an only child*/
	if (grand_parent->left == NULL || grand_parent->right == NULL)
		return (NULL);

	/*checking what side the parent node belongs to on grandparent*/
	if (grand_parent->left == parent)
		return (grand_parent->right);

	return (grand_parent->left);
}
