#pragma once

#include "Node.h"

#include <memory>
#include <functional>

template <typename TValue>
class Tree
{
public:
	//using pointer_type = std::unique_ptr<Node<TValue>>;
	using node_type     = Node<TValue>;
	using node_ptr_type = Node<TValue>*;
public:
	//class Iterator
	//{

	//};
public:
	Tree() = default;

	Tree(TValue key)
		: m_root(node_type(key))
	{

	}

	void erase(TValue node );

	void insert(TValue key);

	node_ptr_type search(TValue key); 

	node_type max_el(node_ptr_type node = m_root);

	node_type min_el(node_ptr_type node = m_root);

	void in_order_traverse(std::function<void(TValue)> process);

	void pre_order_traverse(std::function<void(TValue)> process);

	void post_order_traverse(std::function<void(TValue)> process);

	void level_order_traverse(std::function<void(TValue)> process);

private:
	node_ptr_type search(node_ptr_type node ,TValue key);

	void transplant(node_ptr_type first, node_ptr_type second);

	void in_order_traverse(node_ptr_type node, std::function<void(TValue)> process);

	void pre_order_traverse(node_ptr_type node, std::function<void(TValue)> process);

	void post_order_traverse(node_ptr_type node, std::function<void(TValue)> process);
private:
	//pointer_type m_root = nullptr;
	node_ptr_type m_root = nullptr;
};

#include"binary_search_tree_impl.h"