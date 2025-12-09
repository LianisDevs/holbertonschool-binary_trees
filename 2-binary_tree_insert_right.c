#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

binary_tree_t *parent_right(binary_tree_t *new_node, binary_tree_t *parent);

/**
 * binary_tree_insert_right - inserts a node as the right child of another node
 * @parent: pointer to the node to insert the right child in
 * @value: value to store in new node
 * Return: pointer to new node or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *temp = NULL;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	/*checking if parent already has a right child and storing it in temp*/
	if (parent->right != NULL)
	{
		temp = parent->right;
		parent->right = NULL;
	}

	new_node = setup(new_node, parent, value);

	/*if temp was used now connecting everyone again*/
	if (temp != NULL)
	{
		new_node->right = temp;
		temp->parent = new_node;
	}

	return (parent_right(new_node, parent));
}

/**
 * parent_right - connects parent to new node
 * @new_node: pointer to new node to connect
 * @parent: pointer to parent
 * Return: new node
 */
binary_tree_t *parent_right(binary_tree_t *new_node, binary_tree_t *parent)
{
	parent->right = new_node;

	return (new_node);
}
