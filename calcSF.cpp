/*	
 * 	This program takes a space delimited text file of
 * 	x and y positions and returns a file containing
 *  the structure factor - SFplotdata.txt.
 * 
 *  The calculations are based on real space lattice
 *  spacings of a0=1e-7m
 * 
 *  The data set must be at least as large as
 *  10e-7 < xval < 60e-7 
 *  2e-7  < yval < 50e-7
 *  for everything outside this range is trimmed before
 *  calculation.
 * 
 *  The range/resolution in reciprocal space is 
 *  -3pi to 3pi in qx and qy in steps of pi/20.0
 * 
 * 
 *  Modifications need to be made to this program to allow
 *  for different densities and parameters to be specified.
 * 
 *  
 *  
 * 	This was written by Jon Watkins - 2012
 * 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>

using namespace std;

double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
double a0=1e-7;

class CVortex {
    double x, y, z;
    
    
  public:
	CVortex() {
		x=0;
		y=0;
		z=0;
		
	}
	
	~CVortex() {}
	
	
	
	void set_pos (double a,double b,double c)	{
			x = a;
			y = b;
			z = c;
	};
	
	   
    double get_x ()	{
			return x;
	};
    
    double get_y ()	{
			return y;
	};
   
    double get_z ()	{
			return z;
	};
	  
};




void initialiseVortices(list<CVortex>& vorticesList, bool& file){
	
	ostringstream oss;
	char renderChar[100];
	string renderStr;
	oss.str("");
	oss << "posdata.txt";
	cout <<"oss: " << oss << endl;
	renderStr = oss.str();
	cout << renderStr << endl;
	strcpy(renderChar,renderStr.c_str());
			
  ifstream myfile (renderChar);
  cout << "initialise Vortices" << endl;
  
	if (myfile.is_open()) {
		cout << "Initial Vortex Positions From File" << endl;
		file = true;
		double xval;
		double yval;
    
    while ( myfile.good() )
    {
      myfile >> xval;
      myfile >> yval;
     
      
      CVortex newVortex;
      if (xval > 10e-7 && xval < 60e-7 && yval > 2e-7 && yval < 50e-7 ) {
					newVortex.set_pos
					(xval/a0,yval/a0,0);
			
				vorticesList.push_back(newVortex);
			}
    }
    myfile.close();

	}
	
   
  cout << "initialised" << endl;
}

double S(double qx, double qy,list<CVortex> posdata) {
	
	double sumpq=0;
	
	for (list<CVortex>::iterator p=posdata.begin();
				p!=posdata.end(); ++p ){
				
		double sumq=0;
		
		for (list<CVortex>::iterator q=posdata.begin();
				q!=posdata.end(); ++q) {
			sumq+=cos(qx*(q->get_x()-p->get_x())+qy*(q->get_y()-p->get_y()));
			
		}
		
	sumpq+=sumq;
		
	}
	return sumpq;
}


int main() {
	double numRecip=3.0;
	list<CVortex> posdata;
	
	bool file;
	initialiseVortices(posdata, file);
	ofstream plotdata;
	plotdata.open("SFplotdata.txt");
  plotdata.precision(6);
  cout << "posdata size: " << posdata.size() << endl;
  
	for (double qx=-numRecip*pi;qx<=numRecip*pi;qx+=2*pi/40.0) {
		for (double qy=-numRecip*pi;qy<=numRecip*pi;qy+=2*pi/40.0) {
			double sf=S(qx,qy,posdata);
			cout << setw(10) << qx << setw(10) << qy << setw(20) << sf << endl;
			plotdata << setw(20) << qx << setw(20) << qy << setw(20) << sf << endl;
		
		}
	}
	
  plotdata.close();
  cout << "Structure Factor plot data written to SFplotdata.txt" << endl;
	
	return 0;
	
}
