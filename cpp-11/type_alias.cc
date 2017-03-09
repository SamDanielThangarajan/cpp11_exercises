#include <iostream>
#include <vector>
#include <typeinfo>

/*
 * In < c++11, we cannot typedef a template class with templated arguments
 * Eg:
 * typedef std::vector<T> myvector
 *
 * below alternative can be used
 * myClass<int>::myclass iobj;
 */

namespace test {

template <typename T>
class MyClass {
    public:
        MyClass(){
            std::cout << "Type Id: " << typeid(T).name() << std::endl;
        }
};
}

// < c++98 solution -- start

template<typename T>
struct myClass {
    typedef test::MyClass<T> myclass;
};

// < c++98 solution -- end

// c++11 --start
template <typename T> using myclass_new = test::MyClass<T>;
// c++11 --end

int main(){

    //c++03 way
    myClass<int>::myclass iobj;
    myClass<char>::myclass cobj;
    myClass<myClass<float>::myclass >::myclass mobj;

    myclass_new<int> cpp11_iobj;
    myclass_new<char> cpp11_cobj;
    myclass_new<myclass_new<float> > cpp11_fobj;
}

