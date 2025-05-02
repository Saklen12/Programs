#include <iostream>
using namespace std;

// Base class
class Individual
{
protected:
    string fullName;
    int personAge;
public:
    Individual(string p_name, int p_age) : fullName(p_name), personAge(p_age) {};
    virtual void showDetails()
    {
        cout << "Name: " << fullName << ", Age: " << personAge << endl;
    }
};

// Student derived class
class Learner : virtual public Individual
{
protected:
    int studentID;
    string major;
    float totalMarks;
public:
    Learner(string s_name, int s_age, int s_id, string s_major, int s_marks) : Individual(s_name, s_age), studentID(s_id), major(s_major), totalMarks(s_marks) {}
    float computeCGPA()
    {
        return totalMarks / 10;
    }
    void showDetails() override
    {
        cout << "Student Information:" << endl;
        Individual::showDetails();
        cout << "Student ID: " << studentID << "\nMajor: " << major << endl;
        cout << "Total Marks: " << totalMarks << ", CGPA: " << computeCGPA();
    }
    friend class Management;
};

// Faculty derived class
class Instructor : virtual public Individual
{
protected:
    int instructorID;
    string facultyDept;
    int monthlySalary;
public:
    Instructor(string f_name, int f_age, int f_id, string f_dept, int f_salary) : Individual(f_name, f_age), instructorID(f_id), facultyDept(f_dept), monthlySalary(f_salary) {}
    void showDetails() override
    {
        cout << "\nFaculty Information:" << endl;
        Individual::showDetails();
        cout << "Instructor ID: " << instructorID << "\nDepartment: " << facultyDept << "\nSalary: " << monthlySalary << endl;
    }
    friend class Management;
};

// Multiple inheritance derived from Student and Faculty
class AssistantInstructor : public Learner, public Instructor
{
public:
    AssistantInstructor(string a_name, int a_age, int s_id, string s_major, float s_marks, int i_id, string i_dept, int i_salary) :
        Individual(a_name, a_age), Learner(a_name, a_age, s_id, s_major, s_marks), Instructor(a_name, a_age, i_id, i_dept, i_salary) {}
    
    void showDetails() override
    {
        cout << "Teaching Assistant Information:" << endl;
        Individual::showDetails();
        cout << "Student ID: " << studentID << "\nMajor: " << major << "\nInstructor ID: " << instructorID << "\nDepartment: " << facultyDept << "\nSalary: " << monthlySalary << endl;
    }
};

// Management friend class
class Management
{
public:
    void review(const Learner& student, const Instructor& faculty)
    {
        cout << "Management Review:" << endl;
        cout << "Student " << student.fullName << " from " << student.major << " secured " << student.totalMarks << " marks." << endl;
        cout << "Instructor " << faculty.fullName << " teaches in " << faculty.facultyDept << " department." << endl;
    }
};

int main()
{
    // Creating objects
    Learner student1("Atharv", 20, 310, "CSE", 90);
    Instructor faculty1("Abs", 45, 1027, "CSE", 150000);
    AssistantInstructor assistant("Xyz", 30, 3753, "CSE", 90, 2754, "AI", 50000);
    
    // Displaying details
    student1.showDetails();
    cout << endl;
    faculty1.showDetails();
    cout << endl;
    assistant.showDetails();
    cout << endl;
    
    // Management review
    Management manager;
    manager.review(student1, faculty1);
    
    return 0;
}
