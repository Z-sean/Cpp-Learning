#include <iostream>
#include <vector>
#include"student.h"

void Student::printInfo() const {
    std::cout << "学生ID: " << id
                      << ", 姓名: " << name
                      << ", 成绩: " << grade << std::endl;
}

// 添加学生
void addStudent(std::vector<Student>& students, int id, const std::string& name, float grade) {
    Student newStudent = {id, name, grade};
    students.push_back(newStudent);
    std::cout << "添加学生成功。" << std::endl;
}

// 显示所有学生
void displayStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "没有学生信息。" << std::endl;
        return;
    }
    std::cout << "所有学生信息：" << std::endl;
    for (const auto& student : students) {
        student.printInfo();
    }
}

// 根据ID查找学生
void findStudentById(const std::vector<Student>& students, int id) {
    for (const auto& student : students) {
        if (student.id == id) {
            std::cout << "找到学生：" << std::endl;
            student.printInfo();
            return;
        }
    }
    std::cout << "未找到ID为 " << id << " 的学生。" << std::endl;
}

