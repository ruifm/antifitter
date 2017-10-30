#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main(void){
	string equation,term;
	equation = " ";
	char c;
	ofstream out("func.cpp");
	ofstream out2("script");
	out << "#include <iostream>" << endl;
	out << "#include <cstdlib>" << endl;
	out << "#include <cmath>" << endl;
	out << "#include \"func.h\"" << endl;
	out << "using namespace std;\n" << endl;
	out << "double f(double x){" << endl;
	out << "	double pi = M_PI;" << endl;
	out << "	return ";
	
	out2 << "set title \"Anti-fitter\"" << endl;
	out2 << "set xlabel \"x\"" << endl;
	out2 << "set ylabel \"y\"" << endl;
	out2 << "plot \"data.txt\" with yerrorbars,\\" << endl;
	
	cout << "\nWelcome to Anti-fitter !\n" << endl;
	cout << "Please insert the equation you desire to generate points from, in c++ notation, with variable \"x\".\nKeep in mind you can use the following constants in the form: pi, C, H, HBAR, SIGMA, B, EPSILON, KB, NA, R.\n\nEND YOUR EQUATION WITH A \";\" TOKEN!!!!\n" << endl;
	cout << "y(x) = ";
	do{
		cin >> term;
		equation = equation + term;
		c = *term.rbegin();
	}while(c!=';');
	out << equation;
	out2 << equation;
	out << "\n}";
	cout << endl;
	out.close();
	
	out2.seekp (-1, ios::cur);
	out2 << "   ";
	out2.close();
	
	if(!system("make -s")){
		cout << "Compiled with no errors\n" <<endl;
		if(!system("run")) return 0;
	}
	else {
		cout << "Compilation errors. Please restart.\n" << endl;
		return 1;
	}
	
	return 0;
}
