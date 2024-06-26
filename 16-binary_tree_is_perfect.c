#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - CMNT
 * @node: CMNT
 *
 * Return: CMNT
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - CMNT
 * @tree: CMNT
 *
 * Return: CMNT
 */
size_t depth(const binary_tree_t *tree)
{
	if (tree->parent != NULL)
	{
		return (1 + depth(tree->parent));
	}
	else
	{
		return (0);
	}
}

/**
 * get_leaf - CMNT
 * @tree: CMNT
 *
 * Return: CMNT
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	if (tree->left)
	{
		return (get_leaf(tree->left));
	}
	else
	{
		return (get_leaf(tree->right));
	}
}

/**
 * is_perfect_recursive - CMNT
 * @tree: CMNT
 * @leaf_depth: CMNT
 * @level: CMNT
 *
 * Return: CMNT
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - CMNT
 * @tree: CMNT
 *
 * Return: CMNT
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
