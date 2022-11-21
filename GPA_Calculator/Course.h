
#ifndef COURSE_H
#define COURSE_H
#include <string>

class Course {
public:
	std::string name;
	std::string grade;
	double credit;
	Course(std::string name, std::string grade, double credit);
	double getGradePoints();
	double getCreditPoint();
};

#endif
