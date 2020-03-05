
#include "pch.h"
#include "nokia.h"


int main()
{

	int times = 1;
#if 1
	{
		std::cout << std::endl << " 1 TEST" <<  std::endl << std::endl;

		LOG_DURATION("prime number");
		//size_t n;
		//std::cout << "enter number of prime numbers " << std::endl;
		//std::cin >> n;
		size_t n = 101;
		std::vector<size_t> numbers(n);//array for prime numbers

		for(int y=0; y< times; y++)
			generate_prime_number(n, &numbers[0]);

		std::cout << " first " << n << " prime numbers: " << std::endl;
		for (size_t j : numbers)
			std::cout << j << " ";
		std::cout << std::endl;
	}
#endif

#if 1
	{
		std::cout << std::endl << " 1 TEST" << std::endl << std::endl;

		LOG_DURATION("prime number");
		//size_t n;
		//std::cout << "enter number of prime numbers " << std::endl;
		//std::cin >> n;
		size_t n = 101;
		std::vector<size_t> numbers(n);//array for prime numbers

		for (int y = 0; y < times; y++)
			generate_prime_number_screen(n, &numbers[0]);

		std::cout << " first " << n << " prime numbers: " << std::endl;
		for (size_t j : numbers)
			std::cout << j << " ";
		std::cout << std::endl;
}
#endif




#if 0
	{
		std::cout << std::endl << " 2 TEST" << std::endl << std::endl;

		std::string input = "wsd d dfg eeee gtfhh  tttt  sssssjygfd ";
		count_words_of_variable_lengths(input);

		std::cout  << std::endl;

		std::string input2 = " ";
		count_words_of_variable_lengths(input2);

	}
#endif

#if 0
	{
		std::cout << std::endl << " 3 TEST" << std::endl << std::endl;

		List * a = generate_list(100);
		std::cout << "before" << std::endl;
		print_List(a);//before
		remove_every5th(a);
		std::cout << "after" << std::endl;
		print_List(a);//after
		free_list(a);
	}
#endif

#if 0
	{
		std::cout << std::endl << " 4 TEST" << std::endl << std::endl;

		unsigned int  min = 0;
		unsigned int  max = 0;
		number_estimate(24234, &min, &max);
		std::cout << "input=" << 24234 << " min= " << min << " max =" << max << std::endl;
		number_estimate(4294967295, &min, &max);
		std::cout << "input=" << 4294967295 << " min= " << min << " max =" << max << std::endl;
		number_estimate(0, &min, &max);
		std::cout << "input=" << 0 << " min= " << min << " max =" << max << std::endl;
	}
#endif

#if 0
	{

		std::cout << std::endl << " 5 TEST" << std::endl << std::endl;

		TreeNode * first=nullptr;
		create_binary_tree(&first);
		auto a = count_max_depth(first);
		std::cout << "max_depth = " << a.first << std::endl;
		print_List(a.second);
		free_list(a.second);
		delete_binary_tree(&first);
	}
#endif

}

