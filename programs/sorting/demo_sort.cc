#include <iostream>
#include <vector>
#include <string>
#include "extras.hh"
#include "bubble_sort.hh"
#include "selection_sort.hh"

int main()
{
   std::cout << "Welcome to sorting demo!" << std::endl;

   std::vector<int> ints = {12,5,2,7,3,45,67,34,72,95,109,579,11,44};

   bubble_sort_inplace(ints);
   bubble_sort_inplace_performance_calculator(ints);

   log_func("-------------------------------");
   selection_sort_inplace(ints);

}
