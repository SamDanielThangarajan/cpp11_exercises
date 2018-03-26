
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "extras.hh"


/**
 * Demo the bubble sort
 */
template<typename T>
void bubble_sort_inplace(std::vector<T> unsorted_data_list)
{
   /**
    * Notes go here!
    */
   auto logger = [](std::string msg)
   {
      log_func("bubble_sort> " + msg);
   };

   logger("");
   logger("begin");

   logger("");
   logger("input unsorted list:");
   logger(get_list_as_string(unsorted_data_list));

   ////////////////////////////////////////////////////////////////
   // Sorting
   ///
   int iteration = 0; // only for printing
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

template<typename T>
void bubble_sort_inplace_performance_calculator(std::vector<T> unsorted_data_list)
{
   disable_logging();
   auto diff = elapsed_time_reader(bubble_sort_inplace<int>, unsorted_data_list);
   std::cout << "Bubble Sort elapsed time : " << diff.count() << " counts" << std::endl;
   enable_logging();

}
