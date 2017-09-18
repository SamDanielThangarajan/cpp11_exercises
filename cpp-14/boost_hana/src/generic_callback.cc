#include <iostream>
#include <functional>

namespace test
{
   template<typename F, typename... Args>
   void callback_dispatcher(F call, Args&& ...args )
   {
      std::cout << "callback_dispatcher>" << __PRETTY_FUNCTION__ << "enter <<< " << std::endl;
      call(std::forward<Args>(args)...);
   }
}

struct plo_callback_tester
{
   void handler()
   {
      std::cout << "void Handler called from plo_callback_tester" << std::endl;
   }
   void test_callback()
   {
      test::callback_dispatcher(std::bind(&plo_callback_tester::handler, std::placeholders::_1),this);
   }
};


int main()
{
   std::cout << "Main entered..." << std::endl;

   test::callback_dispatcher([](){
            std::cout << "lambda payload dispatched!" << std::endl;
        });

   test::callback_dispatcher([](int a)
         {
         std::cout << "void(int) lambda dispatched with a = " << a << std::endl;
         },5);

   std::cout << "Main exited..." << std::endl;
}



