#include "pch.h"
#include <iostream>
#include "binary_search_tree.h"

int main()
{
	Tree<char> tree;
	tree.insert('F');
	tree.insert('B');
	tree.insert('A');
	tree.insert('D');
	tree.insert('C');
	tree.insert('E');
	tree.insert('G');
	tree.insert('I');
	tree.insert('H');
	std::cout << "*****Post Order******\n";
	tree.post_order_traverse([](char key)->void {std::cout << key << std::ends; });
	std::cout << "\n*****Pre Order******\n";
	tree.pre_order_traverse([](char key)->void {std::cout << key << std::ends; });
	std::cout << "\n*****In Order******\n";
	tree.in_order_traverse([](char key)->void {std::cout << key << std::ends; });
	std::cout << "\n*****Level Order******\n";
	tree.level_order_traverse([](char key)->void {std::cout << key << std::ends; });
	/*Node<int>* node = tree.search(3);
	std::cout << node->key << std::endl;*/
}
