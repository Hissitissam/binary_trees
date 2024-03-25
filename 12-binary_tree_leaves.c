#include "binary_trees.h"

/**
 * binary_tree_leaves - binary_tree_leaves
 * @tree: pointer
 *
 * Return: tree counts
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves = leaves + (!tree->left && !tree->right) ? 1 : 0;
		leaves = leaves + binary_tree_leaves(tree->left);
		leaves = leaves + binary_tree_leaves(tree->right);
	}
	return (leaves);
}
