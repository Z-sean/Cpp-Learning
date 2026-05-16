#include <iostream>
#include<vector>
#include "student.h"
int main() {
    using namespace std;


    std::vector<Student> students;
    int choice;
    do {
        std::cout << "\n===== 学生信息管理系统 =====" << std::endl;
        std::cout << "1. 添加学生" << std::endl;
        std::cout << "2. 显示所有学生" << std::endl;
        std::cout << "3. 根据ID查找学生" << std::endl;
        std::cout << "4. 退出" << std::endl;
        std::cout << "请选择（1-4）：";
        std::cin >> choice;

        if (choice == 1) {
            int id;
            std::string name;
            float grade;
            cout << "输入id:";
            cin >> id;
            cout << "输入名字:";
            cin >> name;
            cout << "输入成绩:";
            cin >> grade;

            addStudent(students, id, name, grade);
        }else if (choice == 2) {
            displayStudents(students);
        }else if (choice == 3) {
            int id;
            cout << "输入要查询的学生ID:";
            cin >> id;
            findStudentById(students, id);
        }else if (choice == 4) {
            cout << "再见！";
        }else {
            cout << "无效输入";
        }

    }while (choice != 4);

    return 0;
}
