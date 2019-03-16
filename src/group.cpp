#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>


#include <group.h>





Group::Group(const std::string& name) {
    this->name = std::move(name);
    head = nullptr;
    num = 0;
}

void Group::addStudent(Student *student) {
    num++;
    students.push_back(student);
    student->setGroup(this);
}

void Group::elections() {
    if (num > 0) {
        head = students[rand() % students.size()];
    }
}

Student * Group::find(unsigned int id) {
    for (Student* i : students) {
        if (i->getId() == id) {
            return i;
        }
    }
    return nullptr;
}

Student * Group::find(const std::string &name) {
    for (Student* i : students) {
        if (i->getName() == name) {
            return i;
        }
    }
    return nullptr;
}

float Group::getAverage() {
    if (num == 0) {
        return 0;
    }

    float sum = 0;

    for (auto i : students) {
        sum += i->getAverage();
    }

    return sum / num;
}

void Group::fireStudent(Student *student) {
    for (auto studentIter = students.begin(); !students.empty() && studentIter != students.end(); ++studentIter) {
        if ((*studentIter) == student) {

            studentIter = students.erase(studentIter);
            studentIter--;
            //students.erase(studentIter);


        }
    }

    //students.erase( std::find(students.begin(), students.end(), student) );
}

std::string Group::getName() {
    return this->name;
}

void Group::update(const std::string &name) {

    this->students.clear();
    this->num = 0;
    this->name = std::move(name);
    this->head = nullptr;
}

