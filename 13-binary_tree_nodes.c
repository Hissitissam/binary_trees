#include "binary_trees.h"

/**
 * binary_tree_nodes - binary_tree_nodes
 * @tree: pointer
 *
 * Return: 0 or count
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes = nodes + (tree->left || tree->right) ? 1 : 0;
		nodes = nodes + binary_tree_nodes(tree->left);
		nodes = nodes + binary_tree_nodes(tree->right);
	}
	return (nodes);
}
