#include <iostream>
#include <type_traits>

class ExtendableClass{
    public:
        virtual void hello(){
            std::cout << " Hello "<< std::endl;
        }
};

class ConcreteClass{
    public:
        ConcreteClass(){
            std::cout << "ConcreteClass () " << std::endl;
        }

};

template<typename T> void causeCompileFailureForExtendableClass() {
    static_assert(!std::is_polymorphic<T>::value, "Class is polymorphic");
}

template<typename T> void hasProperDestructorsImplemented() {
    static_assert(!(std::is_polymorphic<T>::value && !std::has_virtual_destructor<T>::value), "Destructors are not proper, might cause to leak!!!");
}

int main(){
    std::cout << "is Concrete class polymorphic : " << std::is_polymorphic<ConcreteClass>::value << std::endl;
    std::cout << "is ExtendableClass class polymorphic : " << std::is_polymorphic<ExtendableClass>::value << std::endl;

    causeCompileFailureForExtendableClass<int>();
    causeCompileFailureForExtendableClass<ConcreteClass>();
    /*
     * Below line will cause compilation failure
     */ 
    causeCompileFailureForExtendableClass<ExtendableClass>();


    hasProperDestructorsImplemented<ConcreteClass>();
    /*
     * Below line will cause compilation failure
     */ 
    hasProperDestructorsImplemented<ExtendableClass>();

    return 0;
}
