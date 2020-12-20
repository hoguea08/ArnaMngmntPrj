#ifndef STAFF_H_INCLUDED
#define STAFF_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

/// Staff class

class Staff
{
private:
    int empID;
    std::string firstName;
    std::string lastName;
    std::string jobTitle;
    double salary;

public:
    Staff()
    {
        empID = 0;
        firstName = " ";
        lastName = " ";
        jobTitle = " ";
        salary = 0.0;
    }

    int getEmpID() {return empID;}
    void setEmpID(int id) {empID = id;}

    std::string getFirstName() {return firstName;}
    void setFirstName(std::string first) {firstName = first;}

    std::string getLastName() {return lastName;}
    void setLastName(std::string last) {lastName = last;}

    std::string getJobTitle() {return jobTitle;}
    void setJobTitle(std::string job) {jobTitle = job;}

    double getSalary() {return salary;}
    void setSalary(double s) {salary = s;}

    void readStaffData(std::fstream&);
};

    void staffOptions(std::vector <Staff>&, int&);
	void printStaff(std::vector <Staff>&, int&);
	void printByID(std::vector <Staff>&, int&);
	void printByPosition(std::vector <Staff>&, int&);
	void hireStaff(std::vector <Staff>&, int&);
	void fireStaff(std::vector <Staff>&, int&);
	void changeStaff(std::vector <Staff>&, int&);

#endif // STAFF_H_INCLUDED
