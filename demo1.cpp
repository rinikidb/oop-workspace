#include <iostream>
#include <string>

using namespace std;

class Student{
    private:
        string name;
        int ID;
        double grade;
    public:
    Student(string s_name, int s_ID, double s_grade);

    string get_name(){
        return name;
    }
    int get_ID(){
        return ID;
    }
    double get_grade(){
        return grade;
    }
        
    void set_name(string new_name){
        name = new_name; 
    }
    void set_ID(int new_ID){
        ID = new_ID;
    }
    void set_grade(double new_grade){
        grade = new_grade; 
    }
    bool is_pass();
};

//construtor function to initialise
Student::Student(string s_name, int s_ID, double s_grade){
    name = s_name;
    ID = s_ID;
    grade = s_grade;
}

bool Student::is_pass(){
    if (grade < 50){
        return false;
    }
    else{
        return true; 
    }
}

int main(){
    Student s1("Riniki", 1909018, 95.88);
    //s1.set_name("Riniki");
    //s1.set_ID(1909018);
    //s1.set_grade(95.88);

    cout << s1.get_name() << endl;
    cout << s1.get_ID() << endl;
    cout << s1.get_grade() << endl;

    cout << s1.is_pass() << endl;

    return 0;
}