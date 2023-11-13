// GNU C++
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

/**
  template<
  typename Key, // Key type
  typename Mapped, // Mapped-policy
  typename Cmp_Fn = std::less<Key>, // Key comparison functor
  typename Tag = rb_tree_tag, // Specifies which underlying data structure to use
  template<
  typename Const_Node_Iterator,
  typename Node_Iterator,
  typename Cmp_Fn_,
  typename Allocator_>
  class Node_Update = null_node_update, // A policy for updating node invariants
  typename Allocator = std::allocator<char> > // An allocator type
  class tree;
*/

/**
 * Tag: tree structure (tb_tree_tag, splay_tree_tag, ov_tree_tag)
 * Node_Update: class denoting policy for updating node invariants.
 *    Default: null_node_update
 *    Other: tree_order_statistics_node_update
*/

// O(logn)
// find_by_order --> k-th largest element (couting from 0)
// order_by_order --> number of items that are strictly smaller than our item


// Example
typedef tree<
  int,
  null_type, // Change to int --> map
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update
> ordered_set;

// Example 2
#pragma once
#include <bits/extc++.h> /** keep-include */
template<class T>
using Tree = tree<
  T,
  null_type,
  less<T>,
  rb_tree_tag,
  tree_order_statistics_node_update
>;
Tree<int> ordered_set_2;

// Link: https://gcc.gnu.org/onlinedocs/libstdc++/manual/policy_data_structures_design.html#container.tree.interface
