#include <iostream>

using namespace std;

class Point{
    private:
        //int _x;
        //int _y;
        int* _x;
        int* _y;
    public:
        //Point():_x(0),_y(0){};
        Point(){
            _x = new int;
            _y = new int;
            *_x = 0;
            *_y = 0;
        }
        Point(const Point &pnt){
            _x = new int;
            _y = new int;
            *_x = *(pnt._x);
            *_y = *(pnt._y);
        }
        void operator = (const Point &pnt){
            *_x = *(pnt._x);
            *_y = *(pnt._y);
        }
        void print(){cout <<*_x <<","<<*_y<<endl;}
        virtual void set_point(int x, int y){
            *_x=x; 
            *_y=y;
        }
        virtual ~Point(){
            delete _x;
            delete _y;
            cout << "_x and _y were deleted!\n";
        }
};

/*void foo(Point pnt){
    pnt.set_point(500,500);
    pnt.print();
}
*/

class Point3d : public Point{
    private:
        int* _z;
    public:
        Point3d():Point(){
            _z = new int;
        }void set_point(int x, int y, int z){
            Point::set_point(x,y);
            *_z = z;
        }
        ~Point3d(){
            delete _z;
            cout << "_z was deleted!\n";
        }

};     




int main(){

    //Point p1;
    //p1.set_point(10,10);
    //p1.print();

    //Point p2 = p1;

    //p2.print();

    //foo(p1);

    //p2 = p1;

    //p2.set_point(458,95);

    //p1.print();

    Point* p = new Point3d;
    
    delete p;

    return 0;
}