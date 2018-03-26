#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "extras.hh"


/**
 * Demo the selection sort
 */
template<typename T>
void selection_sort_inplace(std::vector<T> unsorted_data_list)
{
   auto logger = [](std::string msg)
   {
      log_func("selection_sort> " + msg);
   };

   logger("");
   logger("begin");

   logger("");
   logger("input unsorted list:");
   logger(get_list_as_string(unsorted_data_list));

   ////////////////////////////////////////////////////////////////
   // Sorting
   ///
   auto progress_bar = list.begin();
   while (progress_bar != list.end())
   {
      auto runner = progress_bar;
      T small_value = *progress_bar;
      for_each(progress_bar, list.end(), get_lowest);

   }

   logger("");
   logger("end");

}

template<typename T>
void selection_sort_inplace_performance_calculator(std::vector<T> unsorted_data_list)
{
   disable_logging();
   auto diff = elapsed_time_reader(selection_sort_inplace<int>, unsorted_data_list);
   std::cout << "selection Sort elapsed time : " << diff.count() << " counts" << std::endl;
   enable_logging();

}
