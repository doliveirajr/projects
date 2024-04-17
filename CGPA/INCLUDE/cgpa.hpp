#ifndef CGPA_HPP
#define CGPA_HPP
#include <iostream>
#include <vector>

class CGPA
{
private:
    int numberOfSubjects_{0};
    double average_{0};
    std::string studentName_;
    std::vector<double> grades_;

public:
    CGPA() { reset(); };
    void reset();
    void setNumberOfSubjects(int numberOfSubjects);
    void setStudentName(std::string studentName);
    void setGrades(double grade);

    int getNumberOfSubjects() { return numberOfSubjects_; };
    std::string getStudentName() { return studentName_; };
    double getAverage() { return average_; }

    void calculateAverage();
};

#endif