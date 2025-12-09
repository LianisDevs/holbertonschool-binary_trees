#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

binary_tree_t *setup(binary_tree_t *new_node,
		binary_tree_t *parent, int value);
binary_tree_t *parent_setup(binary_tree_t *new_node, binary_tree_t *parent);
/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to parent node of the node to create
 * @value: value to add to new node
 * Return: pointer to new node or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node = setup(new_node, parent, value);

	if (parent == NULL)
		return (new_node);

	return (parent_setup(new_node, parent));
}

/**
 * setup - sets up all elements inside node
 * @new_node: pointer to new_node
 * @parent: pointer to parent of new_node
 * @value: value to add to new_node
 * Return: new_node
 */
binary_tree_t *setup(binary_tree_t *new_node, binary_tree_t *parent, int value)
{
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * parent_setup - connect parent to new node
 * @new_node: pointer to new node to connect
 * @parent: pointer to parent
 * Return: new_node
 */
binary_tree_t *parent_setup(binary_tree_t *new_node, binary_tree_t *parent)
{
	if (parent->left != NULL)
		parent->right = new_node;
	else
		parent->left = new_node;

	return (new_node);
}
