//参照外し
#include <memory>
#include <iostream>

class Hoge {
public:
	Hoge(){}
	~Hoge(){
		std::cout << "Destoractor" << std::endl;
	}
	int number_;
};

int main()
{
    
   {
		std::shared_ptr<Hoge> hoge1(new Hoge);
		hoge1->number_ = 15;

        {
            Hoge hoge2 = *hoge1;

            std::cout << "hoge1->number_ : " << hoge1->number_ << std::endl;
            std::cout << "hoge2.number_ : " << hoge2.number_ << std::endl;

            //std::cout << std::endl << "hoge2.number_ = 3" << std::endl << std::endl;
            hoge2.number_ = 3;

            std::cout << "hoge1->number_ : " << hoge1->number_ << std::endl;
            std::cout << "hoge2.number_ : " << hoge2.number_ << std::endl;
        }
        std::cout << "p2 get out of " << std::endl;
	}
	return 0;
}