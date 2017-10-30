#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include "func.h"


using namespace std;

/*
double f(double x){
// inserir função aqui
	x= x*1e-9;
	return (2*H*C*C)/(x*x*x*x*x*(exp(H*C/(x*KB*300))-1));
}


double f(double x){
  return x*x;
}*/

double random(double a, double b){
	return a+(b-a)*((double)rand()/(double)RAND_MAX);
}



int main(void){
	srand (time(NULL));
	double b, a,d,ey2,dx,ex,k;
	int N,div;
	cout << endl;
	cout << "x_min = ";
	cin >> a;
	cout << "x_max = ";
	cin >> b;
	cout << "N = ";
	cin >> N;
	cout << "e_y_max = ";
	cin >> ey2;
	cout << "e_x = ";
	cin >> ex;
	cout << "# of subdivisions (5 is recommended) = ";
	cin >> k;
	cout << "Constant divisions? (no=0) = ";
	cin >> div;
	cout << endl;
	cout << endl;
	if(div) div=1;
	if(k<1) k=5;
	d=(b-a)/(k*(double)N);
	double x[N],y[N],ey[N];
	  
	ofstream out("data.txt");

	for(int i=0; i<N;i++){
	  dx=random(-d,d);
	  x[i]=a+(b-a)*i/((double)N)+div*dx;
	  //ey[i]=random(ey1,ey2)+abs((f(a+(b-a)*i/((double)N)+dx/2)-f(a+(b-a)*i/((double)N)-dx/2))/dx);
 		ey[i]=random(0,ey2)+ex*fabs((f(x[i]+d)-f(x[i]))/d);
	  y[i]=f(x[i])+random(-ey[i],ey[i]);
	  cout << x[i] << "\t" << y[i] << "\t" << ey[i] << endl;
	  out << x[i] << "\t" << y[i] << "\t" << ey[i] << endl;	
	}
	cout << "\nOutput written on \"data.txt\"\n" << endl;
	if(!system("gnuplot -persist script &")) return 0;
	return 0;
}
