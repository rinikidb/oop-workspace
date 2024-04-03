#include <iostream>
#include <string>

using namespace std;

class A{
    public:
        int a;
        void set_a(int new_a){
            this->a = new_a;
        }
        int get_a() const{
            return a;
        }
};

class B : public A {
    private:
        double x;
    public:
        double fool(){
            return x*a;
        }
};

int main(){

    B b;

    b.set_a(10);

    return 0;
}