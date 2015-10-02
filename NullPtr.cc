#include <iostream>
#include <cstddef>

/*
 * Compiling:
 * g++ -std=c++11 NullPtr.cc
 */ 

class NullPtr{

    public:
        NullPtr(){
        }


        void testFunctionCalls(){

            std::cout << "Invoking function : function1(NullPtr)" << std::endl;
            function1(NullPtr);

            std::cout << "Invoking function : function1(10)" << std::endl;
            function1(10);

            std::cout << "Invoking function : function1(0)" << std::endl;
            function1(0);

            std::cout << "Invoking function : function1((NullPtr_t)NULL)" << std::endl;
            function1((NullPtr_t)NULL);

            /*
             * std::cout << "Invoking function : function1((NullPtr_t)NULL)" << std::endl;
             * function1(NULL) // Ambigious call
             */ 
            std::cout << "View file for more comments " << std::endl;
        }

        void testVariableAssignments() {
            std::cout << "\n\n";
            std::cout << "A NullPtr can be assigned only to a bool, for other types compilation issue is raised.\n \
                          TODO: find why? \n\n " << std::endl;

            bool b = NullPtr;
            /*int i = NullPtr;
            char c = NullPtr;
            long l = NullPtr;
            */
        }

    private:
        void function1(int a){
            std::cout << "function invoked : void function1(int a)" << std::endl;
        }
        void function1(void * p){
            std::cout << "function invoked : void function1(void * p)" << std::endl;
        }

};

int main(){

    NullPtr s;
    s.testFunctionCalls();
    s.testVariableAssignments();

    return 0;
}
