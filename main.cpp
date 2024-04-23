#include <iostream>
#include <string>
using namespace std;

class A{
    protected:
        int _s;
    public:
        A(int s): _s(s){}
        /*
        A(int s){
            _s = s;
        }
        */
        A():A(-1){}

        virtual void print(){ //virtual tells to not do static binding and wait until run time
            cout << "S = " << this->_s << endl;
        }

         
};

class B: public A{
    private:
        double _k;
    public:
        B(int s, double k):A(s),_k(k){};
        B():B(0,0){};
        void print(){
            cout << "S = " << this->_s << " K = " << this->_k << endl;
        }
};

class C: public A{
    private:
        string _str;
    public:
        C(int s, string str):A(s),_str(str){};
        C():C(0,""){};
        void print(){ 
            cout << "S = " << this->_s << " Str = " << this->_str << endl;
        }
};

void test(A* a){
    a->print();
}

int main(){

    A* a[3];
    a[0] = new B();
    a[1] = new C();
    a[2] = new A();

    for(int i = 0; i < 3; i++){
        test(a[i]);
    }

    //A a1(564);
    //B b1(500,0.25865);

    //test(&a1);
    //test(&b1);
    // a pointer to a base class can point at an object from a derived class
    //a1 = &b1;
    //inheritence version of print function
    //b1.print();
    //base version
    //b1.A::print();
    
    //a1->print();

    return 0; 
}