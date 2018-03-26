#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <functional>

/**
 * Lambdas for logging
 */ 
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
 * Function to execute a function and return
 * the elased duration counts.
 */
template<typename F, typename... Args>
std::chrono::duration<double>
elapsed_time_reader(F call, Args&& ...args)
{
   auto start = std::chrono::system_clock::now();
   call(std::move(args)...);
   return std::chrono::system_clock::now() - start;
}

auto log_func = [](std::string msg)
{
   if (not is_logging_enabled())
      return;
   std::cout << msg << std::endl;
};
