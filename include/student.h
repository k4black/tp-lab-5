#ifndef TASK1_STUDENT_H
#define TASK1_STUDENT_H



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>


class Group;

class Student {
private:
    std::string name;
    unsigned int num;

    unsigned int id;

public:
    Student(unsigned int id, const std::string&  name);
    void enrollment(Group *group);
    void addMark(unsigned char mark);
    float getAverage();

    unsigned int getId();
    std::string getName();

    std::string getGroupName();

    void setGroup(Group* group);

    Group *group = nullptr;
    std::vector<unsigned char> marks;
};

#endif //TASK1_STUDENT_H
