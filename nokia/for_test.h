// data and functions for test

#pragma once

#include <iostream>
//1
#include <vector>
//2
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
//5
#include <list>
#include <utility>

/////////////////////////////////////////////need clean
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>

#include <condition_variable>
#include <mutex>
#include <shared_mutex >
#include <thread>
#include <vector>
#include <variant>
#include <future>
#include <chrono>
#include <iostream>


using namespace std;
using namespace std::chrono;


//3.  &  5.
//Write a function that removes every fifth(5) element from this list.
struct TreeNode;

class SomeDataType {//stub
public:
	size_t data{ 0 };
	TreeNode * node{ nullptr };
	~SomeDataType()
	{
		//std::cout << "~SomeDataType" << std::endl;
	}
};

typedef struct List {
	struct List* next;
	SomeDataType payload;
} List;


///////


List * generate_list(size_t num)
{
	List * ret = new List();
	List * cur = ret;
	List * prev = ret;
	ret->payload.data = 1;
	for (size_t i = 2; i <= num; i++)
	{
		List * next = new List();
		next->payload.data = i;
		prev->next = next;
		prev = next;
	}
	prev->next = nullptr;
	return ret;
}

void free_list(List * first)
{
	if (!first) return;
	List * cur = first;
	List * next;
	while (true) {
		next = cur->next;
		delete cur;
		if (!next) break;
		cur = next;
	}
	first = nullptr;
}

void print_List(List * first)
{
	if (!first) return;
	List * cur = first;
	while (true)
	{
		std::cout << cur->payload.data << " ";
		cur = cur->next;
		if (!cur) break;
	}
	std::cout << std::endl;
}

//5.
//Write a function that calculates the depth of the tree(the maximum number of nodes in
//	the path from the root to the leaf).Return paths in the tree that have such depth

typedef struct TreeNode {
	struct TreeNode* leftChild{ 0 };
	struct TreeNode* rightChild{ 0 };
} TreeNode;

void create_binary_node(TreeNode ** first_)
{
	TreeNode * first = *first_;
	first = new TreeNode();
	TreeNode * left = new TreeNode();
	TreeNode * right = new TreeNode();
	first->leftChild = left;
	first->rightChild = right;
	*first_ = first;
}

void delete_binary_node(TreeNode ** first_)
{
	TreeNode * first = *first_;
	delete first->leftChild;
	delete first->rightChild;
	delete first;
}



//preluminary
List * count_max_depth_second(TreeNode *node, std::vector<List*> * list_vector);





void create_binary_tree(TreeNode ** first_)
{
	TreeNode * cur = *first_;
	create_binary_node(&cur);
	create_binary_node(&cur->leftChild->leftChild);
	create_binary_node(&cur->rightChild->rightChild);
	create_binary_node(&cur->rightChild->rightChild->rightChild->rightChild);
	//create_binary_node(&cur->rightChild->rightChild->rightChild->leftChild);
	*first_ = cur;
}

void delete_binary_tree(TreeNode ** first_)
{
	TreeNode * cur = *first_;
	delete_binary_node(&cur->rightChild->rightChild->rightChild->rightChild);
	//delete_binary_node(&cur->rightChild->rightChild->rightChild->leftChild);
	delete_binary_node(&cur->leftChild->leftChild);
	delete_binary_node(&cur->rightChild->rightChild);
	delete_binary_node(&cur);
}



class LogDuration {
public:
	explicit LogDuration(const string& msg = "")
		: message(msg + ": ")
		, start(steady_clock::now())
	{
	}

	~LogDuration() {
		auto finish = steady_clock::now();
		auto dur = finish - start;
		//printf("%s ", message.c_str());
		std::cout << message.c_str() << duration_cast<milliseconds>(dur).count() << " ms" << std::endl;


	}
private:
	string message;
	steady_clock::time_point start;
};

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
  LogDuration UNIQ_ID(__LINE__){message};
