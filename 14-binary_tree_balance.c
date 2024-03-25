#include "binary_trees.h"

/**
 * binary_tree_balance - binary_tree_balance
 * @tree: pointer
 *
 * Return: 0 or balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}

	return (0);
}

/**
 * binary_tree_height - binary_tree_height
 * @tree: pointer
 *
 * Return: 0 or height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		if (tree->left) {
			l = 1 + binary_tree_height(tree->left);
		} else {
			l = 1;
		}
		if (tree->right) {
			r = 1 + binary_tree_height(tree->right);
		} else {
			r = 1;
		}
		if (l > r) {
			return l;
		} else {
			return r;
		}
	}
	return 0;
}
