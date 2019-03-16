#ifndef TASK1_DEAN_H
#define TASK1_DEAN_H


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>


#include <student.h>
#include <group.h>


class Deanery {
private:
    std::vector<Student *> students;
    std::vector<Group *> groups;
public:

    void createStudents();
    void createGroups();
    void addMarks(int num);
    void getStatictic();
    void changeGroup(Student* student, Group *group);
    //void fireStudent(Student* student);
    void fireStudents();
    void saveData();
    void elections();
    void about();

    Student* find(unsigned  int id);
};



#endif //TASK1_DEAN_H
