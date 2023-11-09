#include <iostream>
#include <vector>
#include <string>

struct student {
	std::string name;
	int age;
	int math_s;
	int eng_s;
	int phy_s;
};

class Group{
    private:
        std::vector<student> students;
        std::string name;
    public:
        Group(std::string&); //Конструктор принимает имя группы
        void add_student(student&); //Функция добавления студента
        double average_age(); //Функция подсчета среднего возраста
        double average_mark(); //Функция подсчета среднего балла по 3 предметам
};

Group::Group(std::string& name) {
	this->name = name;
}

double Group::average_age() {
	double ave_age = 0.0;
	for (const auto& human : this->students) {
		ave_age += human.age;
	}
	return ave_age / this->students.size();
}

double Group::average_mark() {
	double ave_score = 0.0;
	for (const auto& human : this->students) {
		ave_score = human.math_s + human.eng_s + human.phy_s; 
	}
	return ave_score / this->students.size();
}

void Group::add_student(student& stud) {
	this->students.push_back(stud);
}

int main() {
	std::cout << "Enter group's name: ";
	std::string group_name;
	std::getline(std::cin, group_name);
	Group group1(group_name);
	for (int i = 0; i < 10; ++i) {
		std::string name;
		int age;
		int math_s;
		int eng_s;
		int phys_s;
		std::cout << "Enter student name: ";
		std::getline(std::cin,name);
		std::cout << "Enter student age: ";
		std::cin >> age;
		std::cout << "Enter math, eng and phys scores: ";
		std::cin >> math_s >> eng_s >> phys_s;
		student newhuman {name, age, math_s, eng_s, phys_s};
		group1.add_student(newhuman);
		std::cin.ignore();
	}
	std::cout << group1.average_age();
	std::cout << group1.average_mark();
}