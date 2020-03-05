//result function

#pragma once

#include "for_test.h"

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

////////////////////////////////////////////////////////////////////////////////////
//1.
//function that calculates the first N prime numbers and put these numbers in the array passed to it.
//size_t n - amount of numbers
//size_t * array - array for prime numbers (it is allocated in advance)
void generate_prime_number(size_t n, size_t * array)
{
	size_t i = 0;
	if (n == 0) return;
	size_t array_index = 0;
	for (size_t count = 2; count <= n + 1; i++)
	{
		size_t a = 2;
		for (; a < i; a++)
		{
			if (i % a == 0)
				break;
		}

		if (a == i)
		{
			array[array_index++] = i;
			count++;
		}
	}
}






//Для нахождения всех простых чисел не больше заданного числа n, следуя методу Эратосфена, нужно выполнить следующие шаги :

//Выписать подряд все целые числа от двух до n(2, 3, 4, …, n).
//Пусть переменная p изначально равна двум — первому простому числу.
//Зачеркнуть в списке числа от 2p до n считая шагами по p(это будут числа кратные p : 2p, 3p, 4p, …).
//Найти первое незачёркнутое число в списке, большее чем p, и присвоить значению переменной p это число.
//Повторять шаги 3 и 4, пока возможно.

//Теперь все незачёркнутые числа в списке — это все простые числа от 2 до n.

//На практике, алгоритм можно улучшить следующим образом.На шаге № 3 числа можно зачеркивать начиная сразу с числа p2, потому что все составные числа меньше него уже будут зачеркнуты к этому времени.И, соответственно, останавливать алгоритм можно, когда p2 станет больше, чем n.[2] Также, все простые числа(кроме 2) — нечётные числа, и поэтому для них можно считать шагами по 2p, начиная с p2.


//1.
//function that calculates the first N prime numbers and put these numbers in the array passed to it.
//size_t n - amount of numbers
//size_t * array - array for prime numbers (it is allocated in advance)
void generate_prime_number_screen(size_t n, size_t * array)
{

	if (n == 0) return;

	int index_found = 0;
	int current_digit = 2;
	
	int max_size = 1024;
	unsigned char digits[1024+1];
	memset(digits, 1, max_size);


	while (true)
	{
		int index = current_digit;
		//cout << "num: " << index << " erase ::";
		while (true)
		{
			index += current_digit;
			if (index > max_size) break;
			digits[index] = 0;
			//cout << index << " ";
		}
		//cout << endl;
		array[index_found++] = current_digit;
		if (index_found == n) return;

		while (current_digit < max_size)
		{
			current_digit++;
			if (digits[current_digit]) break;
		}
	}

}






















////////////////////////////////////////////////////////////////////////////

//2.
//Write a function that counts the number of words in the text for each word length
//(X words with 1 - letter length, Y words with 2 - letters length, etc.)

//std::string input - input text
void count_words_of_variable_lengths(std::string input)
{

	std::string word;

	std::istringstream iss(input, std::istringstream::in);
	std::vector<std::string> wordsVector;
	while (iss >> word)
	{
		wordsVector.push_back(word);
	}

	std::map <size_t, size_t> mp;
	for (auto w : wordsVector)
	{
		size_t size = w.size();
		auto  it = mp.find(size);
		if (it != mp.end())
			(it->second)++;
		else
			mp[size] = 1;
	}

	if (mp.size() == 0)
	{
		std::cout << "no words " << std::endl;
		return;
	}

	for (const auto &[k, v] : mp)
	{
		std::cout << "for length = " << k << " quantity =" << v << std::endl;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////




//3.
//Write a function that removes every fifth(5) element from this list.


//List * first  - input list
void remove_every5th(List * first)
{
	List * cur = first;
	List * prev = first;
	size_t count = 0;
	while (true)
	{
		if (!cur) return;
		count++;
		if (count == 5) {
			prev->next = cur->next;
			delete cur; //?? //cur->payload.~SomeDataType();//?? it depends on....
			cur = prev->next;
			count = 0;
			continue;
		}
		prev = cur;
		cur = cur->next;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//4. 
//Write a function that takes a 32 - bit unsigned integer number and returns the maximum
//and minimum 32 - bit unsigned integer numbers which can be obtained using the same
//number of bits set to 1 as in the taken number.


//unsigned int input - estimated number
//unsigned int * min - pointer for output min number
//unsigned int * max - pointer for output max number
void number_estimate(unsigned int input, unsigned int * min, unsigned int * max)
{
	int bits = 0;
	for (int i = 0; i < 32; i++)
	{
		if (input & (1 << i)) bits++;
	}
	unsigned int min_ = 0;
	unsigned int max_ = 0;
	for (int i = 0; i < bits; i++)
	{
		min_ = min_ | (1 << i);
		max_ = max_ | (1 << (31 - i));
	}
	*min = min_;
	*max = max_;
}

/////////////////////////////////////////////////////////////////////////////////////

//5.
//Write a function that calculates the depth of the tree(the maximum number of nodes in
//	the path from the root to the leaf).Return paths in the tree that have such depth


// TreeNode *node - input tree node
// std::pair<size_t, List *>  - output: 1. max depth 2. root of List of this branch
std::pair<size_t, List *> count_max_depth(TreeNode *node)
{

	if (node == nullptr)  return std::pair<size_t, List *>(0, nullptr);

	//std::vector<List*> result;
	std::vector<List*> all;
	List * a = count_max_depth_second(node, &all);
	size_t max_depth = a->payload.data;

	List * cur = a;
	while (true)
	{
		if (!cur) break;
		//result.push_back(cur);
		for (size_t i = 0; i < all.size(); i++)//delete from all storage
			if (all[i] == cur) all[i] = nullptr;
		cur = cur->next;
	}
	for (size_t i = 0; i < all.size(); i++)//delete from all storage
		if (all[i] != nullptr) delete all[i];


	return std::pair<size_t, List *>(max_depth, a);
}

List * count_max_depth_second(TreeNode *node, std::vector<List*> * list_vector)
{
	if (node == nullptr) {
		return nullptr;
	}
	auto llist = count_max_depth_second(node->leftChild, list_vector);
	auto rlist = count_max_depth_second(node->rightChild, list_vector);

	size_t ldepth = 0;
	size_t rdepth = 0;
	if (llist) 	ldepth = llist->payload.data;
	if (rlist) 	rdepth = rlist->payload.data;

	List * a = new List();
	if (ldepth > rdepth)
	{
		a->next = llist;
		a->payload.data = ldepth + 1;
		a->payload.node = node;
	}
	else
	{
		a->next = rlist;
		a->payload.data = rdepth + 1;
		a->payload.node = node;
	}
	list_vector->push_back(a);
	return a;
}




