//(c) 24L - 6116

// TODO

/*Exercise 2: (15 points)
Every Circle has a center and a radius. Create a class CircleType that can store the center, the radius, and the color of the circle. Since the center of a circle is a point in the x-y plane, create a class PointType to store the x and y coordinate. Use class PointType to define the class CircleType. 

Provide constructors that enable objects of these classes to be initialized when they are declared. The constructors should contain default values in case no initializes are provided. 
The definition of class CircleType and class PointType is as under: (you may define additional functions if you require any).

class PointType
{
	int x;
	int y;
        public:
	//default constructor 
	//constructor so that objects are initialized
	//print the x and y- coordinates
	//determine the quadrant in which the point lies
//getter and setter functions
};
class CircleType
{
	double radius;
	char * color;
	PointType center;
public:
	//default constructor 
	//constructor so that objects are initialized
	//print the radius, center, color
	//calculate area
	//calculate circumference
//getter and setter functions
	//destructor
};

Your program should run for the following main.
int main()
{
	CircleType C(21,2,3.5,"blue");
	cout<<"\n************************\n"<<endl;
	C.print();
	cout<<"\n************************\n"<<endl;
	cout<<" Area of circle is   "<<C.calc_area();
	cout<<"\n\n************************\n\n"<<endl;

	PointType P(-20,3);
	int p=P.checkquad();
	P.print();

	switch (p)
	{
	case 0:
		cout<<"Point lies at center"<<endl;
		break; 
	case 1:
		cout<<"Point lies in I quadrant"<<endl;
		break;
	case 2:
		cout<<"Point lies in II quadrant"<<endl;
		break;
	case 3:
		cout<<"Point lies in III quadrant"<<endl;
		break;
	case 4:
		cout<<"Point lies in IV quadrant"<<endl;
		break;
	default: 
		cout<<"INVALID";
		break;
	}

	int x;
inty;
	double r;
	char col[9];

	CircleType circ(2,5,4.89,"purple");
	cout<<"\n\n***********************\n\n";
	circ.print();
	
	cout<<"\n Enter radius \n";
	cin>>r;
	cout<<"\n Enter the coordinates where the center lies \n";
	cin>>x>>y;
	cout<<"\n Enter color \n";
	cin>>col;	
	
	circ.setparam(x,y,r,col);
	cout<<"\n\n***********************\n\n";
	circ.print();
	cout<<"\n\n***********************\n\n";
  return 0;
}*/