#include <iostream>
#include <assert.h>

int main(){
    static_assert(1,"Nothing happens here");
    static_assert(0,"Compilation Aborts happens here");
}
