#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include <student.h>
#include <group.h>


Student::Student(unsigned int id, const std::string&  name) {
    group = nullptr;
    num = 0;
    this->name = std::move(name);
    this->id = id;
}

void Student::enrollment(Group *group) {
    this->group = group;
    this->group->addStudent(this);
}

void Student::addMark(unsigned char mark) {
    marks.push_back(mark);
    this->num++;
}

float Student::getAverage() {
    if (num == 0) {
        return 0;
    }

    unsigned int sum = 0;

    for (auto i: marks) {
        sum += (unsigned int)i;
    }

    return (float)sum / num;
}

unsigned int Student::getId() {
    return id;
}

std::string Student::getName() {
    return name;
}

std::string Student::getGroupName() {

    if (this->group != nullptr) {
        return this->group->getName();
    }

    return "No group";
}

void Student::setGroup(Group *group) {
    this->group = group;
}


