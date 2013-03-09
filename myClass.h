#ifndef _MYCLASS_H_
	#define _MYCLASS_H_

#include <math.h>
#include <vector>
#include <string.h>
// classes for the class header file

class CIni {
	public:
		std::string readDataLocation;

	CIni() {
		readDataLocation="";
	}
	
	~CIni() {}
	
		
	

};

class CMarker {
		int x,y;
		
	public:
	CMarker() {
		x=0;
		y=0;
	}
		~CMarker() {}

	void set_pos (int a, int b) {
		x= a;
		y= b;
	};
	int get_x() {
		return x;
	};
	
	int get_y() {
		return y;
	};

};

class CVortex {
    double x, y, velx, vely,a0;
    int coordNum, cellx, celly;
    bool highlighted;
    bool ghost;
    
  public:
	CVortex() {
		x=0;
		y=0;
		velx=0;
		vely=0;
		coordNum=0;
		a0=0;
		cellx=0;
		celly=0;
		highlighted=false;
		ghost=false;
		
	}
	
	~CVortex() {}
	
	
	
	void set_pos (double a,double b)	{
			x = a;
			y = b;
	};
	
	void set_coordNum (int a)	{
			coordNum = a;
			
	};
    
    void set_highlighted(bool state) {
		highlighted = state;
	}
    
    bool get_highlighted() {
		return highlighted;
	}
    
    double get_x ()	{
			return x;
	};
    
    double get_y ()	{
			return y;
	};
    
    void set_vel (double vx, double vy)	{
			velx = vx;
			vely = vy;
	};
    
    double get_velx ()	{
			return velx;
	};
	
		double get_vely ()	{
			return vely;
	};
    
    int get_coordNum () {
		return coordNum;
  	};
  	
  	double get_a0 () {
			return a0;
		};
    
    void set_a0 (double a0val) {
			a0=a0val;
		};
	
	void set_cell (int a, int b)	{
			cellx = a;
			celly = b;
	  };
	
	  int get_cellx () {
			return cellx;
		};
		
		int get_celly () {
			return celly;
		};
    
    bool get_ghost() {
			return ghost;
		};
		
		void set_ghost() {
			ghost = true;
		};
	  
};

class CDelLine {
    double x1, y1, x2, y2,length;
    
   

    
  public:
	CDelLine() {
		x1=0;
		y1=0;
		x2=0;
		y2=0;
		length=0;
		
	}
	
	~CDelLine() {}
	
	
	 
    void set_points (double valx1, double valy1, double valx2, double valy2)	{
			//if (valx1<valx2) {
				x1=valx1;
				y1=valy1;
				x2=valx2;
				y2=valy2;
				length = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
			/*}
			else {
				x1=valx2;
				y1=valy2;
				x2=valx1;
				y2=valy1;
			}*/
			
			
	};
	
	bool operator ==(CDelLine const a) const
	{
		return 	(fabs(x1-a.x1)<0.00001 && fabs(y1 - a.y1) < 0.00001 && fabs(x2 - a.x2) < 0.00001 && fabs(y2 - a.y2) < 0.00001) or
				(fabs(x2 - a.x1) < 0.00001 && fabs(y2 - a.y1) < 0.00001 && fabs(x1 - a.x2) < 0.00001 && fabs(y1 - a.y2) < 0.00001);
		
	//	return x < a.x;
	};
	
	/*bool operator !=(CCoord const a) const
	{
		return x != a.x or y != a.y;
		
	//	return x < a.x;
	};*/
	
		double get_x1 ()	{
			return x1;
	};
    
    	double get_y1 ()	{
			return y1;
	};
	
		double get_x2 ()	{
			return x2;
	};
	
		double get_y2 ()	{
			return y2;
	}
    double get_length ()	{
			return length;
	}
  
    
};


class CDelTriangle {
    double Ax,Ay,Bx,By,Cx,Cy; 
    int daughter1,daughter2, daughter3;
    bool divided;    
    bool finalDaughter;
    
  public:
	CDelTriangle() {
		Ax=0;
		Ay=0;
		Bx=0;
		By=0;
		Cx=0;
		Cy=0;
		divided=false;
		daughter1=-1;
		daughter2=-1;
		daughter3=-1;
		finalDaughter=true;
	}
	
	~CDelTriangle() {}
	
		 
    void set_vertices (double valAx, double valAy, double valBx, double valBy, double valCx, double valCy)	{
			Ax=valAx;
			Ay=valAy;
			Bx=valBx;
			By=valBy;
			Cx=valCx;
			Cy=valCy;
			
	};
	
	void set_divided() {
			divided=true;
		
	};
	
	void set_finalDaughter(bool val) {
			finalDaughter=val;
		
	};
	
	void set_daughters(int valdaughter1, int valdaughter2, int valdaughter3) {
		daughter1 = valdaughter1;
		daughter2 = valdaughter2;
		daughter3 = valdaughter3;
		finalDaughter=false;
	};
	
	int get_daughter1 ()	{
			return daughter1;
	};
	
	int get_daughter2 ()	{
			return daughter2;
	};
	
	int get_daughter3 ()	{
			return daughter3;
	};
	
	bool get_finalDaughter ()	{
			return finalDaughter;
	};
	
	bool get_divided ()	{
			return divided;
	};
	
		double get_Ax ()	{
			return Ax;
	};
    
    	double get_Ay ()	{
			return Ay;
	};
	
		double get_Bx ()	{
			return Bx;
	};
	
		double get_By ()	{
			return By;
	};
	
	double get_Cx ()	{
	
			return Cx;
	};
	double get_Cy ()	{
			return Cy;
	}
    
  
    
};

class CCoord {
 public:
    double x, y;
    
  public:
	CCoord() {
		x=0;
		y=0;
				
	}
	
	~CCoord() {}
	
	CCoord operator+ (CCoord param) {
		CCoord temp;
		temp.x = x + param.x;
		temp.y = y + param.y;
		return (temp);
	};
	
	CCoord operator- (CCoord param) {
		CCoord temp;
		temp.x = x - param.x;
		temp.y = y - param.y;
		return (temp);
	};
	
	/*bool operator <(CCoord const a) const
	{
		return x < a.x && y < a.y;
		
	//	return x < a.x;
	};
	
	bool operator ==(CCoord const a) const
	{
		return x == a.x && y == a.y;
		
	//	return x < a.x;
	};
	
	bool operator !=(CCoord const a) const
	{
		return x != a.x or y != a.y;
		
	//	return x < a.x;
	};
	
	bool operator >(CCoord const a) const
	{
		return x > a.x;
		
	//	return x < a.x;
	};
	
	
	*/
	void set_coords (double a,double b)	{
			x = a;
			y = b;
			
	};
    
    double get_x ()	{
			return x;
	};
    
    double get_y ()	{
			return y;
	}
    
    
    
  
    
};

class Ca0Bin {
    double lengthSum,a0;
    int count;
    
    
  public:
	Ca0Bin() {
		lengthSum=0;
		count=0;
		a0=0;
	}
	
	~Ca0Bin() {}
	
	
	
	void set_bin (double newLengthVal)	{
			lengthSum += newLengthVal;
			count++;
			a0= lengthSum/count;
	};
	
	 
    double get_a0 ()	{
			return a0;
	};
   
  int get_count () {
		return count;
	}; 
    
     
    
};

class CPathData {
    double time;
    std::vector<CCoord> positionData;
    
    
  public:
	CPathData() {
		time=-1;
		
	}
	
	~CPathData() {}
	
	
	
	void add_pathData (double newTime, std::vector<CCoord> newData)	{
			positionData = newData;
			time = newTime;
			
	};
	
	
	 
    double get_time ()	{
			return time;
	};
    
     
    
};


class CTemporalCoord : public CCoord{  // contains all points for a single time step.
    double time;
    
    
    
  public:
	CTemporalCoord() {
		time=-1;
		x=-1;
		y=-1;
		
		
	}
	
	~CTemporalCoord() {}
	
	
	
	void add_TemporalCoord (double xval, double yval, double timeval)	{
			x = xval;
			y = yval;
			time = timeval;
			
	};
	
	
	 
    double get_time ()	{
			return time;
	};
    
  
     
    
};
#endif
