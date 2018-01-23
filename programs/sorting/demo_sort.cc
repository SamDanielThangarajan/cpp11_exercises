#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

static bool _logging = true;

auto enable_logging = []() { _logging = true; };
auto disable_logging = []() { _logging = false; };
auto is_logging_enabled = []() { return _logging; };

/**
 * Prepare the incoming list in a string, separated by spaces
 */
template<typename T>
std::string get_list_as_string(std::vector<T> list)
{
   std::string op = "";

   auto append_to_op = [&op](T item)
   {
      op += " ";
      op += std::to_string(item);
   };

   for_each(list.begin(),
           list.end(),
           append_to_op);

   return op;
}


/**
 * Lambda to swap two locations
 */
auto swap = [](auto& a, auto& b)
{
   auto tmp = a;
   a = b;
   b = tmp;
};

/**
 * Demo the bubble sort
 */
template<typename T>
void bubble_sort_inplace(std::vector<T> unsorted_data_list)
{
   /**
    * Notes go here!
    */
   auto logger = [=](std::string msg)
   {
      if (not is_logging_enabled())
         return;

      std::cout << "bubble_sort> " << msg << std::endl;
   };

   logger("");
   logger("begin");

   logger("");
   logger("input unsorted list:");
   logger(get_list_as_string(unsorted_data_list));

   int iteration = 0;
   bool swap_happened = false;
   do
   {
      ++iteration;
      swap_happened = false;
      for (unsigned int i=0; i<unsorted_data_list.size()-1; i++)
      {
         if (unsorted_data_list[i] > unsorted_data_list[i+1])
         {
            swap_happened = true;
            swap (unsorted_data_list[i], unsorted_data_list[i+1]);
         }
      }
      logger("");
      logger("End of Iteration " + std::to_string(iteration));
      logger(get_list_as_string(unsorted_data_list));

   }while(swap_happened);

   logger("");
   logger("end");

}


int main()
{
   std::cout << "Welcome to sorting demo!" << std::endl;

   std::vector<int> ints = {12,5,2,7,3,45,67,34,72,95,109,579,11,44};
   bubble_sort_inplace(ints);

   disable_logging();
   bubble_sort_inplace(ints);
   enable_logging();

}
