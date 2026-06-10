// ● Take input for the number of courses taken by the student.
// ● For each course, input the grade and the credit hours.
// ● Calculate the total credits and total grade points (grade × credit hours).
// ● Compute the GPA for the semester and then the overall CGPA.
// ● Display individual course grades and the final CGPA to the user.
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
class Course {
    public:
    string courseName;
    float grade;
    int creditHours;
    void inputCourseDetails() {
        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, courseName);
        cout << "Enter grade (0-10): ";
        cin >> grade;
        cout << "Enter credit hours: ";
        cin >> creditHours;
    }
    void displayCourseDetails() {
        cout << left<<setw(20)<<courseName <<setw(10)<<grade <<setw(10)<<creditHours <<setw(15)<<grade*creditHours<<endl;
    }
};

class Student{
    vector<Course> courses;
    float semesterGPA;
    float overallGPA;
    public:
    void inputdata(){
        int n;
        cout<<"Enter number of courses: ";
        cin>>n;
        courses.resize(n);
        float totalGradePoints = 0;
        int totalCreditHours = 0;
        for(int i=0;i<n;i++){
            cout<<"Course "<<i+1<<":"<<endl;
            cin.ignore();
            cout<<"Enter course name: ";
            getline(cin, courses[i].courseName);
            cout<<"Enter grade (0-10): ";
            cin>>courses[i].grade;
            cout<<"Enter credit hours: ";
            cin>>courses[i].creditHours;
            totalGradePoints += courses[i].grade * courses[i].creditHours;
            totalCreditHours += courses[i].creditHours;
        }
        semesterGPA = totalGradePoints / totalCreditHours;
        overallGPA = semesterGPA;
    }
    void displayresult(){
        cout<<left<<setw(20)<<"Course Name"<<setw(10)<<"Grade"<<setw(10)<<"Credit Hours"<<setw(15)<<"Grade Points"<<endl;
        for(int i=0;i<courses.size();i++){
            courses[i].displayCourseDetails();
        }
       cout <<"\n semester GPA: "<< fixed << setprecision(2) << semesterGPA << endl;
       cout << "Overall CGPA: " << fixed << setprecision(2) << overallGPA << endl;
    }
};

int main(){
    Student student;
    student.inputdata();
    student.displayresult();

    return 0;
}