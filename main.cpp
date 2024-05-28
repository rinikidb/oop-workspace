#include <iostream>
#include <random>
#include <time.h>

using namespace std;

class student{
    private:
        int id;
        float grade;
        static int count;

    public:
        
        student(){
            id = student::count++;
            grade = (rand()*100.0)/RAND_MAX;
        }
        int get_id(){
            return id;
        }
        static int get_count(){
            return count;
        }
        float get_grade(){
            return grade; 
        }
};

int student::count = 100000;

class ClassroomAdmin{
    public:
        static int count_above(student** c, int n, float grade){
            int ans = 0;
            for (int i = 0; i < n ; i++){
                if(c[i]->get_grade() > grade){
                    ans++;
                }
            }
            return ans;
        }

};

int main(){

    /*
    student s1;
    student s2;
    student s3;
    

    student s[100];
    for(int i=0; i < 100; i++){
        cout << s[i].get_id() << endl;
    }
    */

   //cout << student::get_count() << endl;

    srand(time(NULL));
    int n = 3000;
    student** classroom;

    classroom = new student*[n]; 
    for (int i = 0; i < n ; i++){
        classroom[i] = new student;
    }
    
    //classroom[0] = new student;
    float g = 50.0; 
    int ans = ClassroomAdmin::count_above(classroom, n, g);
    cout << ans << " students scored above " << g << endl;
    return 0;
}