/*
unique_ptrはメモリの所有権を持つ所有者が１つに限られていたのに関して，
shared_ptrはメモリを同一のメモリの所有権を複数で共有することが出来る．
*/

#include <memory>
#include <iostream>

int main(){
    std::shared_ptr<int> ptr=std::make_shared<int>(10);
    std::shared_ptr<int> ptr2(ptr);
    
    if(ptr){
        std::cout << "true" << std::endl;
        std::cout<<"use_count="<<ptr.use_count()<<std::endl;
        if(ptr.unique()){
            std::cout << "unique" << std::endl;
        }
    }else{
        std::cout << "false" << std::endl;
    }

    ptr.reset();

     if(ptr){
        std::cout << "true" << std::endl;
    }else{
        std::cout << "false" << std::endl;
    }

    return 0;
}