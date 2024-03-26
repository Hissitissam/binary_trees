#include "binary_trees.h"

/**
 * ILA MA KHDEMCH UNCMNT HADCHI O MSA7 MN HEADER FILE
 * unsigned char is_leaf(const binary_tree_t *node);
 * size_t depth(const binary_tree_t *tree);
 * const binary_tree_t *get_leaf(const binary_tree_t *tree);
 * int is_perfect_recursive(const binary_tree_t *tree,
 * 		size_t leaf_depth, size_t level);
 * int binary_tree_is_perfect(const binary_tree_t *tree);
 */

/**
 * is_leaf - is_leaf
 * @node: pointer
 *
 * Return: 0 or 1
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * depth - depth
 * @tree: pointer
 *
 * Return: depth
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
 * get_leaf - get_leaf
 * @tree: pointer
 *
 * Return: leaf
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
 * is_perfect_recursive - is_perfect_recursive
 * @tree: pointer
 * @leaf_depth: depth
 * @level: Level
 *
 * Return: 0 or 1
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		if (level == leaf_depth)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - binary_tree_is_perfect
 * @tree: pointer
 *
 * Return: 0 or 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
