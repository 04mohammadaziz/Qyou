#include "course.h"

Course::Course(std::string name, std::string grade, double credit) {
  this->name = name;
  this->grade = grade;
  this->credit = credit;
}

double Course::getCreditPoint(){
  double ret = 0;
  if (grade == "A+"       || grade == "a+")  ret = 4.3;
    else if (grade == "A"  || grade == "a")  ret = 4.00;
    else if (grade == "A-" || grade == "a-") ret = 3.7;
    else if (grade == "B+" || grade == "b+") ret = 3.3;
    else if (grade == "B"  || grade == "b")  ret = 3.00;
    else if (grade == "B-" || grade == "b-") ret = 2.7;
    else if (grade == "C+" || grade == "c+") ret = 2.3;
    else if (grade == "C-" || grade == "c-") ret = 1.7;
    else if (grade == "C"  || grade == "c")  ret = 2.00;
    else if (grade == "D+"  || grade == "d+")  ret = 1.3;
    else if (grade == "D"  || grade == "d")  ret = 1.00;
    else if (grade == "D-"  || grade == "d-")  ret = 0.7;
    else if (grade == "F"  || grade == "f")  ret = 0.00;
  else ret = -1;
    return ret;
}

double Course::getGradePoints() {
  double ret = 0;
 if (grade == "A+"       || grade == "a+")  ret = 4.3;
    else if (grade == "A"  || grade == "a")  ret = 4.00;
    else if (grade == "A-" || grade == "a-") ret = 3.7;
    else if (grade == "B+" || grade == "b+") ret = 3.3;
    else if (grade == "B"  || grade == "b")  ret = 3.00;
    else if (grade == "B-" || grade == "b-") ret = 2.7;
    else if (grade == "C+" || grade == "c+") ret = 2.3;
    else if (grade == "C-" || grade == "c-") ret = 1.7;
    else if (grade == "C"  || grade == "c")  ret = 2.00;
    else if (grade == "D+"  || grade == "d+")  ret = 1.3;
    else if (grade == "D"  || grade == "d")  ret = 1.00;
    else if (grade == "D-"  || grade == "d-")  ret = 0.7;
    else if (grade == "F"  || grade == "f")  ret = 0.00;
  else ret = -1;
  return ret;
}
