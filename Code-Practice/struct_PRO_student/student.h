//
// Created by zhaochen on 2026/5/14.
//
#ifndef STRUCT_PRO_STUDENT_STUDENT_H
#define STRUCT_PRO_STUDENT_STUDENT_H
#include<iostream>

struct Student {
    int id;
    std::string name;
    float grade;

    // 成员函数打印学生信息
    void printInfo() const;
};
void addStudent(std::vector<Student>& students, int id, const std::string& name, float grade);
void displayStudents(const std::vector<Student>& students);
void findStudentById(const std::vector<Student>& students, int id);



#endif
