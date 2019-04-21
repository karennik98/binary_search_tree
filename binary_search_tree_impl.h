#pragma once

#include "binary_search_tree.h"

#include <memory>
#include <cassert>
#include <queue>
#include <exception>

template <typename TValue>
void Tree<TValue>::insert(TValue key)
{
	if (nullptr == m_root)
	{
		m_root = new node_type(key);
		return;
	}

	node_ptr_type current = m_root;
	node_ptr_type prev = nullptr;
	while (nullptr != current)
	{
		prev = current;
		if (key <= current->key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	if (key <= prev->key)
	{
		prev->left = new node_type(key);
	}

	else
	{
		prev->right = new node_type(key);
	}
}

////////////////////////////////////////////////////////////////////////

template <typename TValue>
typename Tree<TValue>::node_type Tree<TValue>::max_el(node_ptr_type node ) 
{
	assert(nullptr != node);

	while (nullptr != node->right)
	{
		node = node->right;
	}

	return *node;
}

////////////////////////////////////////////////////////////////////////

template <typename TValue>
typename Tree<TValue>::node_type Tree<TValue>::min_el(node_ptr_type node) 
{
	assert(nullptr != node);

	while (nullptr != node->left)
	{
		node = node->left;
	}

	return *node;
}

////////////////////////////////////////////////////////////////////////

template<typename TValue>
typename Tree<TValue>::node_ptr_type Tree<TValue>::search(node_ptr_type node, TValue key)
{

	if (nullptr == node || node->key == key)
	{
		return node;
	}

	if (key <= node->key)
	{
		return search(node->left, key);
	}

	else
	{
		return search(node->right, key);
	}
}
template <typename TValue>
typename Tree<TValue>::node_ptr_type Tree<TValue>::search(TValue key)
{
	return search(m_root, key);
}

////////////////////////////////////////////////////////////////////////

template<typename TValue>
void Tree<TValue>::transplant(node_ptr_type first, node_ptr_type second)
{
	if (nullptr == first->parent)
	{
		m_root = second;
	}

	else if (first == first->parent->left)
	{
		first->parent->left = second;
	}

	else 
	{
		first->parent->right = second;
	}

	if (nullptr != second)
	{
		second->parent = first->parent;
	}
}
template <typename TValue>
void Tree<TValue>::erase(TValue key)
{
	node_ptr_type node = search(m_root, key);

	if (nullptr == node->left)
	{
		transplant(node->right, node);
	}
	
	else if (nullptr == node->right)
	{
		transplant(node->left, node);
	}

	else
	{
		node_ptr_type tmp_node = &min_el(node->right); 

		if (tmp_node->parent != node)
		{
			transplant(tmp_node, tmp_node->right);
			tmp_node->right = node->right;
			tmp_node->right->parent = tmp_node;
		}
		 
		transplant(node, tmp_node);
		tmp_node->left = node->left;
		tmp_node->left->parent = tmp_node;
	}
}

////////////////////////////////////////////////////////////////////////

template <typename TValue>
void Tree<TValue>::post_order_traverse(node_ptr_type node, std::function<void(TValue)> process) // (Left, Right, Root)
{
	if (nullptr == node)
	{
		return;
	}
	post_order_traverse(node->left, process);
	post_order_traverse(node->right, process);
	process(node->key);
}
template <typename TValue>
void Tree<TValue>::post_order_traverse(std::function<void(TValue)> process) // (Left, Right, Root)
{
	post_order_traverse(m_root, process);
}

////////////////////////////////////////////////////////////////////////

template<typename TValue>
void Tree<TValue>::pre_order_traverse(node_ptr_type node, std::function<void(TValue)> process)
{
	if (nullptr == node)
	{
		return;
	}

	process(node->key);

	pre_order_traverse(node->left, process);

	pre_order_traverse(node->right, process);
}
template <typename TValue>
void Tree<TValue>::pre_order_traverse(std::function<void(TValue)> process) // (Root, Left, Right)
{
	pre_order_traverse(m_root, process);
}

////////////////////////////////////////////////////////////////////////

template<typename TValue>
void Tree<TValue>::in_order_traverse(node_ptr_type node, std::function<void(TValue)> process)
{
	if (nullptr == node)
	{
		return;
	}

	in_order_traverse(node->left, process);

	process(node->key);

	in_order_traverse(node->right, process);
}
template <typename TValue>
void Tree<TValue>::in_order_traverse(std::function<void(TValue)> process) // (Left, Root, Right)
{
	in_order_traverse(m_root, process);
}

////////////////////////////////////////////////////////////////////////

template <typename TValue>
void Tree<TValue>::level_order_traverse(std::function<void(TValue)> process) // (Level by Level)
{
	std::queue<node_ptr_type> queue;

	if (!m_root)
	{
		//throw nullptr_exeption();
	}

	queue.push(m_root);

	node_ptr_type tmp_root = nullptr;

	while (!queue.empty())
	{
		tmp_root = queue.front();
		queue.pop();
		process(tmp_root->key);
		if (tmp_root->left)
		{
			queue.push(tmp_root->left);
		}
		if (tmp_root->right)
		{
			queue.push(tmp_root->right);
		}
	}
}