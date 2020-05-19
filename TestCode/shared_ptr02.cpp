#include<memory>
class hoge{
public:
   std::shared_ptr<hoge> ptr;
};
int main(){
   std::shared_ptr<hoge> pHoge1=std::make_shared<hoge>();
   std::shared_ptr<hoge> pHoge2=std::make_shared<hoge>();

   //Hoge1のメンバ変数で、pHoge2を参照する
   pHoge1->ptr=pHoge2;
   //Hoge2のメンバ変数で、pHoge1を参照する
   pHoge2->ptr=pHoge1;

   return 0;
}//shared_ptrのディストラクタが呼ばれるのに、確保した二つのhogeが解放されない。
