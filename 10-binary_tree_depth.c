#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: 0 if tree is NULL, else  depth of the node.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return  (1 + binary_tree_depth(tree->parent));
	else
		return (0);
}
