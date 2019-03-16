#ifndef TASK1_GROUP_H
#define TASK1_GROUP_H


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>


#include <student.h>


class Group {
private:
    unsigned int num;
    Student *head = nullptr;
    std::string name = "";
public:
    explicit Group(const std::string&  name);
    void update(const std::string& name);
    void addStudent(Student *student);
    void elections();
    Student* find(unsigned  int id);
    Student* find(const std::string &name);
    float getAverage();
    void fireStudent(Student *student);
    std::string getName();

    std::vector<Student*> students;
};




#endif //TASK1_GROUP_H
