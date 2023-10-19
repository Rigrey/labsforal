#include <iostream>


using std::cout;
using std::cin;
using byte = unsigned char;
void task1();
void task2();
void threatening(std::pair<byte,byte> positionA,std::pair<byte,byte> positionB);
void task3();
void task4();

int main(){
	task1();
	task2();
	task3();
	task4();
	return 0;
}


void task1(){
	int x,y,z;
	cout << "Enter x,y,z: ";
	cin >> x >> y >> z;
	if (x%2==1 and y%2==1) cout << "1st condition is true";
	else cout << "1st condition is false";
	if (x<20 or y<20) cout << "2nd condition is true";
	else cout << "2nd condition is false";
	if (x==0 or y==0) cout << "3rd condition is true";
	else cout << "3rd condition is false";
	if (x<0 and y<0 and z<0) cout << "4th condition is true";
	else cout << "4th condition is false";
	if ((x%5==0 and y%5!=0 and z%5!=0) or (x%5!=0 and y%5==0 and z%5!=0) or (x%5!=0 and y%5!=0 and z%5==0)) cout << "5th condition is true";
	else cout << "5th condition is false";
	if (x>100 or y>100 or z>100) cout << "6th condition is true";
	else cout << "6th condition is false";
}
void task2(){
	cout << "Enter position A coordinates: ";
    byte trys = 8;
	std::pair<byte,byte> positionA, positionB;
	cin >> positionA.first >> positionA.second;
	cout << "Enter position B coordinates: ";
	cin >> positionB.first >> positionB.second;
	threatening(positionA, positionB);
}
void threatening(std::pair<byte,byte> positionA, std::pair<byte,byte> positionB){
	std::string opponent;
	if ((positionA.first == positionB.first) or (positionA.second == positionB.second)) cout << "Rock is threatening\n";
	if ((std::abs(positionA.first - positionB.first) == std::abs(positionA.second - positionB.second))) cout << "Bishop is threatening\n";
	if ((std::abs(positionA.first - positionB.first) <= 1) and (std::abs(positionA.second - positionB.second) <= 1)) cout << "King can move\n";
	if (((positionA.first == positionB.first) or (positionA.second == positionB.second)) or ((std::abs(positionA.first - positionB.first) == std::abs(positionA.second - positionB.second)))) cout << "Queen is threatening\n";
	cout << "Is there any piece (that stands on the diagonal of the pawn strike) between B and A? (yes/no)";
	cin >> opponent;
	for(auto& c : opponent){c = tolower(c);}
	if (opponent=="no"){
		if ((positionA.first == positionB.first && positionB.second == positionA.second + 1) || (positionB.first - positionA.first == 1 && abs(positionB.second - positionA.second) == 1)) {
			cout << "Pawn can move to B." << endl;
		}
	}
	if (opponent=="yes"){
		if(std::abs(positionA.first-positionB.first)==2){
			if (std::abs(positionB.second-positionA.second)==2)	cout << "Pawn can move to B\n";
			cout << "Pawn can't move to B\n";
		}
		else cout << "Pawn can't move to B\n";
	}
}

void task3(){
	int N;	
	for (int i=1;i<10;++i)cout << i <<" x 7 = "<< i*7 <<std::endl;
	cout << std::endl;
	cout << "Enter N: ";
	cin >> N;
	for (int i=1;i<10;++i)cout << i <<" x "<< N<< " = " << i*N <<std::endl;
}

void task4(){
		int a,b;
	for (int i=8;i<16;++i){
		for (int j=i;j<16;++j){
			cout << i << " x " << j << " = " << i*j<<std::endl;
		}
		cout << std::endl;
	}
	tryagain:
	cout << "Enter a value: ";
	cin >> a;
	if (a>=20 or a<=1) {cout << "a from 1 to 20\n"; goto tryagain;}
	for (int i=a;i<21;++i){
		for (int j=i;j<21;++j){
			cout << i << " x " << j << " = " << i*j<<std::endl;
		}
		cout << std::endl;
	}
	tryagain1:
	cout << "Enter b value: ";
	cin >> b;
	if (b>=20 or b<=1) {cout << "b from 1 to 20\n"; goto tryagain1;}
	for (int i=1;i<=b;++i){
		for (int j=i;j<=b;++j){
			cout << i << " x " << j << " = " << i*j<<std::endl;
		}
		cout << std::endl;
	}
	cout << "From a to b: \n";
	if (a>b){cout << "Sorry, pls do b>=a \n"; goto tryagain;}
	for (int i=a;i<=b;++i){
		for (int j=i;j<=b;++j){
			cout << i << " x " << j << " = " << i*j<<std::endl;
		}
		cout << std::endl;
	}
}
