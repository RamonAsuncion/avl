/*
 * Copyright (C) 2024 Ramon Asuncion <ramon@b1t.dev>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _AVL_NODE_H_
#define _AVL_NODE_H_

struct avl_node {
  struct avl_node *left, *right;
  void *key;
  int height;
};


/**
 * Allocates a new avl_node.
 *
 * @return Pointer to a new avl_node.
 */
struct avl_node *avl_node_create();

/**
 * Sets the key in the avl_node.
 *
 * @param node Pointer to the avl_node.
 * @param key Pointer to the key to store in the node.
 */
void avl_node_set_key(struct avl_node *node, void *key);

/**
 * Deallocates an avl_node but not its children.
 *
 * @param node Pointer to the avl_node.
 */
void avl_node_destroy(struct avl_node *node);

/**
 * Deallocates an avl_node and its children.
 *
 * @param node Pointer to the avl_node.
 */
void avl_node_obliterate(struct avl_node *node);

/**
 * Updates the height of the node.
 *
 * @param node Pointer to the avl_node.
 */
void avl_node_update_height(struct avl_node *node);

/**
 * Retrieves the balance factor of the node.
 *
 * @param node Pointer to the avl_node.
 * @return Balance factor (height of left subtree - height of right subtree).
 */
int avl_node_balance_factor(struct avl_node *node);

#endif /* _AVL_NODE_H_ */
