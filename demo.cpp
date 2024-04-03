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
        void set_x(double a_x){
            this->x = a_x;
        }
        void set_a(int new_a){
            if(new_a < 0){
                a = 0;
            }
            else{
                a = new_a;
            }
        }
        double foo(){
            return x*a;
        }
};

int main(){

    A a;
    B b;

    a.set_a(-50);
    cout << a.get_a() << endl;
    b.set_a(10);
    b.set_x(0.2);

    cout << b.foo() << endl;

    return 0;
}