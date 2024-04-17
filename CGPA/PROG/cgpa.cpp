#include "../INCLUDE/cgpa.hpp"

void CGPA::setNumberOfSubjects(int numberOfSubjects)
{
    if (numberOfSubjects < 0)
    {
        numberOfSubjects_ = 0;
    }
    else
        numberOfSubjects_ = numberOfSubjects;
}

void CGPA::setStudentName(std::string studentName)
{
    studentName_ = studentName;
}

void CGPA::setGrades(double grade)
{
    grades_.push_back(grade);
}

void CGPA::calculateAverage()
{
    double sum = 0;
    for (double i = 0; i < grades_.size(); i++)
    {
        sum += grades_[i];
    }
    average_ = sum / numberOfSubjects_;
}

void CGPA::reset()
{
    setNumberOfSubjects(0);
    setStudentName("");
    grades_.clear();
}