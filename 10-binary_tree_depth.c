#include "binary_trees.h"

/**
 * binary_tree_depth - binary_tree_depth
 * @tree: pointer
 *
 * Return: 0 or depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent) {
		return 1 + binary_tree_depth(tree->parent);
	} else {
		return 0;
	}
}
