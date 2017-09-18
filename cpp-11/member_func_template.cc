#include <iostream>
#include <functional>

struct sample
{
   void func1(int data)
   {
      std::cout << "Func 1 , data = " << data << std::endl;
   }
   void func2(int data)
   {
      std::cout << "Func 2 , data = " << data << std::endl;
   }
   void func3(int data)
   {
      std::cout << "Func 3 , data = " << data << std::endl;
   }
   void func4(int data)
   {
      std::cout << "Func 4 , data = " << data << std::endl;
   }
};

void invoker(std::function<void(int)> call, int param)
{
   static int _param;

   if (param) _param = param;

   call(_param);
}



int main()
{

   sample s;

   using namespace std::placeholders;
   invoker(std::bind(&sample::func1, &s, _1),1);
   invoker(std::bind(&sample::func2, &s, _1),2);
   invoker(std::bind(&sample::func3, &s, _1),0);
   invoker(std::bind(&sample::func4, &s, _1),4);


}










