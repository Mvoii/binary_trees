#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts left child
 * @parent: pointer to the node to insert the left child
 * @value: value to store in the left child
 * Return: pointer to the left child || NULL on failure or parent is NULL
 * if parent already has a left child, replace with new node and set
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    if (parent == NULL)
        return (NULL);

    binary_tree_t *new_leftnode;

    new_leftnode = malloc(sizeof(binary_tree_t));

    if (new_leftnode == NULL)
        return (NULL);

    new_leftnode->parent = parent;
    new_leftnode->n = value;

    /*replace the old one*/
    new_leftnode->left = parent->left;
    new_leftnode->right = NULL;
    parent->left = new_leftnode;

    if (new_leftnode->left != NULL)
        new_leftnode->left->parent = new_leftnode;

    return (new_leftnode);
}
