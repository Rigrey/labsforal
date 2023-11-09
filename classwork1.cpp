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

double ave_age(std::vector<student>& studentvec) {
	double ave_age = 0.0;
	for (const auto& human : studentvec) {
		ave_age += human.age;
	}
	return ave_age / studentvec.size();
}

double ave_score(std::vector<student>& studentvec) {
	double ave_score = 0.0;
	for (const auto& human : studentvec) {
		ave_score = human.math_s + human.eng_s + human.phy_s; 
	}
	return ave_score / studentvec.size();
}

double ave_math_s(std::vector<student>& studentvec) {
	double ave_maths = 0.0;
	for (const auto& human : studentvec) {
		ave_maths += human.math_s;
	}
	return ave_maths / studentvec.size();
}

double ave_eng_s(std::vector<student>& studentvec) {
	double ave_engs = 0.0;
	for (const auto& human : studentvec) {
		ave_engs += human.eng_s;
	}
	return ave_engs / studentvec.size();
}
double ave_phys_s(std::vector<student>& studentvec) {
	double ave_physs = 0.0;
	for (const auto& human : studentvec) {
		ave_physs += human.phy_s;
	}
	return ave_physs / studentvec.size();
}

int main() {
	std::vector<student> studentvec;
	studentvec.reserve(10);
	for (int i = 0; i < 4; ++i) {
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
		studentvec.push_back(newhuman);
		std::cin.ignore();

	}

	std::cout << "Average age for students is: " << ave_age(studentvec) << std::endl;
	std::cout << "Average score for all subjects is: " 
			  << ave_score(studentvec) << std::endl;
	std::cout << "Average score for math is: " 
			  << ave_math_s(studentvec) << std::endl;
	std::cout << "Average score for eng is: " 
			  << ave_eng_s(studentvec) << std::endl;
	std::cout << "Average score for phys is: " 
			  << ave_phys_s(studentvec) << std::endl;
}