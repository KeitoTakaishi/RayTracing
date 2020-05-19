/*
shared_ptrはスコープを向けると自然とメモリーがdeliteされる
*/
#include <memory>
#include <iostream>

class Hoge {
public:
	Hoge(){}
	~Hoge(){
		std::cout << "Destoractor" << std::endl;
	}
	int number;
};

int main()
{
    
    {
        /*Hoge* h1= new Hoge;
        h1->number = 30;*/
        //-----------------------------
        
        std::cout << std::endl;
        std::shared_ptr<Hoge> h1(new Hoge);
        h1->number = 30;
        {
            
            /*
            //pointer
            Hoge* h2 = h1;
            std::cout << "h1 = " << h1->number << std::endl;
            std::cout << "h2 = " << h2->number << std::endl;*/
            //------------------------------------------------------
            
            //shared_ptr
            std::shared_ptr<Hoge> h2(new Hoge);
            h2 = h1;
            std::cout << "h1 = " << h1->number << std::endl;
            std::cout << "h2 = " << h2->number << std::endl;
        
        } 
        std::cout << "h1 = " << h1->number << std::endl;
    }
    std::cout << "p1 Get out of Scope" << std::endl;
    return 0;
}