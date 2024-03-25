#include "binary_trees.h"

/**
 * binary_tree_height - binary_tree_height
 * @tree: pointer
 *
 * Return: NULL or height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		if (tree->left)
		{
			l = 1 + binary_tree_height(tree->left);
		}
		else
		{
			l = 0;
		}
		if (tree->right)
		{
			r = 1 + binary_tree_height(tree->right);
		}
		else
		{
			r = 0;
		}
		if (l > r)
		{
			return (l);
		}
		else
		{
			return (r);
		}
	}
	return (0);
}
