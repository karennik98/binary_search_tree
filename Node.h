#pragma once

template<typename TValue>
struct Node
{
	using node_ptr_type = Node<TValue>*;

	Node() = default;
	Node(TValue key = TValue(), node_ptr_type parent = nullptr, node_ptr_type left = nullptr, node_ptr_type right = nullptr)
		: key(key)
		, parent(parent)
		, left(left)
		, right(right)
	{

	}

	node_ptr_type parent;
	node_ptr_type left;
	node_ptr_type right;
	TValue key;
};