#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>


#include <student.h>
#include <group.h>
#include <dean.h>



void createFiles(int groupsNum, int studentsNum) {
    std::string s;

    std::ifstream groupSource;
    groupSource.open("groups_source.txt");




    std::ofstream groupStream;
    groupStream.open("groups.csv");

    for (int i = 0; i < groupsNum && getline(groupSource, s); i++) {
        groupStream << s << " , ";

        for (int j = 0; j < (studentsNum / groupsNum); j++)
            groupStream << j + i * studentsNum / groupsNum << " , ";


        groupStream << std::endl;

    }

    groupSource.clear();
    groupStream.close();




    std::ifstream studentsSource;
    studentsSource.open("students_source.txt");


    std::ofstream studentStream;
    studentStream.open("students.csv");

    for (int i = 0; i < studentsNum && getline(studentsSource, s); i++) {
        studentStream << i << ", "<< s << std::endl;
    }

    studentsSource.close();
    studentStream.close();
}


int main() {
    createFiles(5, 30);

    Deanery d;


    d.createStudents();
    d.createGroups();

    d.about();
    d.getStatictic();

    d.addMarks(10);
    d.getStatictic();

    d.fireStudents();

    d.about();
    d.getStatictic();

    d.saveData();

    return 0;
}