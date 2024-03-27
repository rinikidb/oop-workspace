#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        string name;
        int ID;
        double grade;

    public:
    Student();
    Student(string s_name, int s_ID, double s_grade);
    Student(string s_name, int s_ID);

    ~Student();
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
Student::Student(){
    name = "";
    ID = 0;
    grade = 0;
    //cout << "An object of class student was created\n";
}
Student::Student(string s_name, int s_ID, double s_grade){
    name = s_name;
    ID = s_ID;
    grade = s_grade;
}
Student::Student(string s_name, int s_ID){
    name = s_name;
    ID = s_ID;
    grade = 0;
}

bool Student::is_pass(){
    if (grade < 50){
        return false;
    }
    else{
        return true; 
    }
}

Student::~Student(){
    //cout << "A student object was deleted\n";
}