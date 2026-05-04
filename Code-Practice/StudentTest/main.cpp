#include <iostream>
#include <vector>

struct Student {
    int id;
    std::string name;
    float score;
    void printInfo() const{
        std::cout << "学生id:"<<id<<std::endl;
        std::cout << "学生名字:" << name << std::endl;
        std::cout << "学生成绩:" << score << std::endl;
    }


    Student(int id, std::string name, float score) : id(id), name(name), score(score) {};
};

void addStudent(std::vector<Student> &students,int id,float score,std::string name) {
    Student newStudent = {id, name, score};
    students.push_back(newStudent);
    std::cout << "添加学生成功。" << std::endl;

}
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

int main() {

    return 0;
}
