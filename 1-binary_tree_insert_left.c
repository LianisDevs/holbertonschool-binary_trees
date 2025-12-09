#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * @parent: pointer to parent node to insert the left child in
 * @value: value to store in new node
 * Return: pointer to new node or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *temp = NULL;

	if (parent == NULL)
		return (NULL);

	/*checking if parent already has a left child and storing it in temp*/
	if (parent->left != NULL)
	{
		temp = parent->left;
		parent->left = NULL;
	}

	new_node = binary_tree_node(parent, value);

	/*if temp was used now connecting everyone again*/
	if (temp != NULL)
	{
		new_node->left = temp;
		temp->parent = new_node;
	}

	return (new_node);
}
