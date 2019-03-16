#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>


#include <dean.h>


void Deanery::createStudents() {

    std::ifstream studentsStream;
    studentsStream.open("students.csv");


    std::string s;
    while (std::getline(studentsStream, s)) {
        s.push_back('\n');
        std::string name;
        unsigned int id;

        //std::cout << s << std::endl;

        if (s[0] != '\n') {
            std::istringstream ss(s);

            ss >> id;
            ss >> name;  //  ,
            ss >> name;
            //std::cout << "Student: " << id << ' ' << name << std::endl;


            students.push_back(new Student(id, name));
        }

    }
}

void Deanery::createGroups() {

    std::ifstream groupsStream;
    groupsStream.open("groups.csv");


    std::string s;
    while (std::getline(groupsStream, s)) {
        s.push_back('\n');
        std::string name;
        unsigned int id;

        std::istringstream ss(s);
        ss >> name;
        groups.push_back(new Group(name));


        ss >> name;  // ,


        while (ss) {
            ss >> name;
            if (name == ",") {
                continue;
            }


            Student* tmp = find(std::stoi(name));
            if (tmp == nullptr) {
                continue;
            }

            groups[groups.size() - 1]->addStudent( tmp );

        }

    }
}

void Deanery::addMarks(int num) {
    for (auto i : students) {
        for (int j = 0; j < num; j++)
            i->addMark(static_cast<unsigned char>(rand() % 11));

    }
}

void Deanery::getStatictic() {
    std::cout << " --- stastistic --- " << std::endl;

    for (auto group : groups) {
        std::cout << group->getName() << ": " << group->getAverage() << std::endl;

    }

    std::cout << " ------------------ " << std::endl;


    for (auto student : students) {
        std::cout << student->getName() << ": " << student->getAverage() << std::endl;
        for (int i : student->marks) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    std::cout << " ------------------ " << std::endl;
}

void Deanery::changeGroup(Student *student, Group *group) {
    for (auto group_ : groups) {
        group_->fireStudent(student);
    }

    group->addStudent(student);

}

//void Deanery::fireStudent(Student *student) {
//    for (auto group : groups) {
//        group->fireStudent(student);
//    }
//
//
//    for (int i = 0; i < students.size(); i++) {
//        if (students[i]->getId() == student->getId()) {
//            students.erase(students.begin() + i);
//
//            break;
//        }
//    }
//}

void Deanery::saveData() {

    std::ofstream groupStream;
    groupStream.open("groups.csv");

    for (auto group : groups) {
        groupStream << group->getName() << " , ";

        for (auto student : group->students) {
            groupStream << student->getId() << " , ";
        }

        groupStream << std::endl;
    }

    groupStream.close();



    std::ofstream studentStream;
    studentStream.open("students.csv");

    for (auto student : students) {
        studentStream << student->getId() << ", "<< student->getName() << std::endl;
    }

    studentStream.close();
}

void Deanery::elections() {
    for (auto group: groups) {
        group->elections();
    }
}

void Deanery::about() {

    std::cout << " ---   about   --- " << std::endl;

    for (auto group : groups) {
        std::cout << group->getName() << ": ";

        for (auto student : group->students) {
            std::cout << student->getName() << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << " ------------------ " << std::endl;


    for (auto student : students) {
        std::cout << student->getId() << ". " << student->getName() << ": " << student->getGroupName() << std::endl;
    }

    std::cout << " ------------------ " << std::endl;
}

Student *Deanery::find(unsigned int id) {
    for (auto student : students) {
        if (student->getId() == id) {
            return student;
        }
    }
    return nullptr;
}

void Deanery::fireStudents() {

    for (auto studentIter = students.begin(); students.size() != 0 && studentIter != students.end(); ++studentIter) {
        if ((*studentIter)->getAverage() < 4) {
            for (auto group : groups) {
                group->fireStudent(*studentIter);
            }
            std::cout << (*studentIter)->getName() << std::endl;

            Student * tmp = *studentIter;

            studentIter = students.erase(studentIter);
            studentIter--;

            delete tmp;
        }
    }
}