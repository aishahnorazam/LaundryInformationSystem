//SCSJ2013 - DATA STRUCTURE AND ALGORITHMS
//PREPARED BY: 
//1.AISHAH AINI BINTI NOR'AZAM (A16CS0230)
//2.DALILA AL-HUSNA BINTI KHAIRUD-DIN (A16CS0032)
//3.PRASASTI TUNGGAL MALAYA (A16CS)
//4.NURUL AFIQAH BINTI ANUAR (A16CS0230)

//SECTION:03
//LECTURER: DR NOR BAHIAH BINTI HJ AHMAD
//TASK:MINI PROJECT


#include <iostream> 
#include <iomanip> 
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

ofstream outfile;
ifstream infile;

class NodeLaundry {
public:
	string custname ,month,No;
	string custID;	// data
	int type , date ;
	float price;
	NodeLaundry* next;		// pointer to next node
	NodeLaundry (string Name, string id , int Type , int Date , string Month , string no, float total)	//initilaize node
	{	
		custname=Name;
		custID=id;
		type = Type;
		date = Date;
		month = Month;
		No=no;
		price=total;	
	}
	NodeLaundry()
	{
	}	//default constructor
};

class queue
{
  public:
    queue(); // Constructor - create Q
   ~queue(); // Destructor - destroy Q
    bool isEmpty(); // check Q empty
    void enQueue(string Name, string id , int Type , int Date , string Month , string no, float total ); // insert into Q
    void deQueue(); // remove item from Q
    string getFront(); // get item at Front
    string getRear(); // get item at back Q
    NodeLaundry *backPtr, *frontPtr;    // declaration for back and front pointer
	void display();
	int FindNode(string a);	
}; 

// Write source codes for the following fucntions
// code queue(); // Constructor - create Q
queue :: queue()
{
	backPtr = NULL;
	frontPtr = NULL;
}

// code ~queue(); // Destructor - destroy Q
queue :: ~queue()
{
	while (frontPtr!=NULL)
	{
		NodeLaundry *temp = frontPtr;
		frontPtr = frontPtr->next;
		delete temp;
	}
	backPtr = NULL;
}

// code isEmpty(); // check Q empty
bool queue :: isEmpty()
{
	return bool (backPtr == NULL && frontPtr == NULL);
}

// code enQueue(char); // insert into Q
void queue :: enQueue(string Name, string id , int Type , int Date , string Month , string no, float total )
{
	NodeLaundry *newPtr= new NodeLaundry(Name , id, Type,Date,Month, no, total);
	if (newPtr == NULL) 
    {
    	cout << "Overflow" << endl;
    	return;	
	}
	newPtr->next = NULL;
	
	// for first node
	if (frontPtr == NULL)
	{
		frontPtr = backPtr = newPtr;
	}
	
    else
    {
    	backPtr->next = newPtr;
    	backPtr = newPtr;
	}		
}

// code deQueue(); // remove item from Q
void queue :: deQueue()
{
	if (frontPtr == NULL)
	{
		cout << "Overflow" << endl;
		return;
	}
    cout <<"\n\n\t\tCustomer with ID : "<< frontPtr->custID <<" has been deleted.\n\n" << endl;
	
	if (frontPtr == backPtr) // if there is only one node
		frontPtr = backPtr = NULL;
	else
		frontPtr = frontPtr->next;	
}

// code getFront(); // get item at Front
string queue :: getFront()
{
	return frontPtr->custID;
}

// code getRear(); // get item at back Q
string queue :: getRear()     
{
	return backPtr->custID;
}

void queue :: display()
{
	cout<<endl<<endl<<endl;
	cout <<" ||------------------------------CUSTOMERS RECORD----------------------------------||" << endl;
	cout <<" ||--------------------------------------------------------------------------------||" << endl;
	cout << "\tNAME\t\tID\tTYPE\tDATE\t\tPHONE NO\tPRICE (RM)"<<endl;
	cout <<" ||--------------------------------------------------------------------------------||" << endl;
  
   //output for outfile   
    outfile <<" ||------------------------------CUSTOMERS RECORD----------------------------------||" << endl;
	outfile <<" ||--------------------------------------------------------------------------------||" << endl;
	outfile << "\tNAME\t\tID\tTYPE\tDATE\tPHONE NO\tPRICE (RM)"<<endl;
	outfile <<" ||--------------------------------------------------------------------------------||" << endl;
   
   	NodeLaundry* currNode	=	frontPtr;
    
   	while (currNode != backPtr)
   	{
		cout << "\t" << currNode->custname ;
		cout << "\t\t" << currNode->custID ;
		cout << "\t" << currNode->type ;
		cout << "\t"<< currNode->date ;
		cout << " "<< currNode->month;
		cout << "\t\t"<< currNode->No;
		cout << "\t"<< fixed << setprecision(2) << currNode->price << endl;
		
		//output for outfile
		outfile << "\t" << currNode->custname ;
		outfile << "\t\t" << currNode->custID ;
		outfile << "\t" << currNode->type ;
		outfile << "\t"<< currNode->date ;
		outfile << " "<< currNode->month;
		outfile << "\t"<< currNode->No;
		outfile << "\t"<< fixed << setprecision(2) << currNode->price << endl;

		currNode	=	currNode->next;
  	 }
  	 
  	 if (backPtr)
  	 {
  	 	cout << "\t" << currNode->custname ;
		cout << "\t\t" << currNode->custID ;
		cout << "\t" << currNode->type ;
		cout << "\t"<< currNode->date ;
		cout << " "<< currNode->month;
		cout << "\t\t"<< currNode->No;
		cout << "\t"<< fixed << setprecision(2) << currNode->price << endl;
		
		//output for outfile
		outfile << "\t" << currNode->custname ;
		outfile << "\t\t" << currNode->custID ;
		outfile << "\t" << currNode->type ;
		outfile << "\t"<< currNode->date ;
		outfile << " "<< currNode->month;
		outfile << "\t"<< currNode->No;
		outfile << "\t"<< fixed << setprecision(2) << currNode->price << endl;
  	 }
  	 
  	cout <<" ||--------------------------------------------------------------------------------||" << endl;
  	outfile <<" ||--------------------------------------------------------------------------------||" << endl;
}	
	
int queue :: FindNode(string id)
{
	NodeLaundry* currNode	=	frontPtr;
	int currIndex	=	1;
	cout <<endl<<endl<<endl;
	cout <<" ||------------------------------CUSTOMERS RECORD----------------------------------||" << endl;
	cout <<" ||--------------------------------------------------------------------------------||" << endl;
	cout << "\tNAME\t\tID\tTYPE\tDATE\t\tPHONE NO\tPRICE (RM)"<<endl;
	cout <<" ||--------------------------------------------------------------------------------||" << endl;
	while (currNode && currNode->custID!= id) {
		currNode	=	currNode->next;
		currIndex++;
	}
	if (currNode) 
	{
		cout << "\t" << currNode->custname ;
		cout << "\t\t" << currNode->custID ;
		cout << "\t" << currNode->type ;
		cout << "\t"<< currNode->date ;
		cout << " "<< currNode->month;
		cout << "\t\t"<< currNode->No;
		cout << "\t"<< fixed << setprecision(2) << currNode->price << endl;
		cout <<" ||--------------------------------------------------------------------------------||" << endl;
		
		return currIndex;
	}
	
	else
	{
		cout << "\n\n\t\tCustomer ID : " << id << " is not found in system!" <<endl;
		return 0;
	}
}	

// main program
main()
{ 
	queue first;
	string name, id , month , No;
	float price;
	int date , type, qty ;
	int ch; 
	char decision;
	infile.open("Input_Cust.txt" , ios::in);
	outfile.open("Cust_List3.txt" , ios::out | ios::trunc);
	
	while(infile>> name >> id >> type >> date >> month >> No >> price)
	{
		first.enQueue(name , id, type,date,month, No, price);
	}
	
	do 
	{
		//system("cls");
		cout<<endl;
	       cout <<" ||-----------------------WELCOME TO LADIES LAUNDRY----------------------||" << endl;
	       cout <<" ||----------------------------------------------------------------------||" << endl;
	       cout <<" 			1. Add Customer Details							 " << endl;
	       cout <<" 			2. Search Customer Details        				 " << endl;
	       cout <<" 			3. Delete Customer Details          	  	     " << endl;
	       cout <<" 			4. Display All Customer Details       		     " << endl;
	       cout <<" 			5. Exit 									     " << endl;
	       cout <<" Enter your choice : ";
	       cin >> ch;
	       system("cls");
	
		switch(ch)
		{
			case 1: cout << endl<<endl;
					cout << "\tEnter Customer Details to Add Record: ";
					cout << "\n\t*************************************\n";
					cout << endl<<endl;
					cout << "Number of Customer to Add: ";
					cin >> qty;
					
					for(int x=0; x<qty; x++)
					{ 
						cout << "\nCustomer's Name   : "; cin.ignore(); getline(cin,name);
						cout <<   "Customer's ID     : "; getline(cin,id); 
						cout <<   "Laundry Type      : "; cin >> type ;
						cout <<   "Sent Date	  : "; cin >> date >> month;
						cout <<   "Phone No          : " ; cin >> No;
						cout <<   "Total Price       : RM"; cin >> price;
						first.enQueue(name, id , type , date, month , No, price);
					}
					cout << endl << endl <<"\t\tRecord has been added to file....." <<  endl; 
					cin.ignore();
	                cout<<endl;
			        cout<< "\n\n\n\t\tPress Enter to continue.."<<endl;
			        cin.get();
			        system("cls");
					break;
			case 2: cout << endl<<endl;
					cout << "\tEnter Customer ID to find the details: " << endl;
					cout << "\n\t*************************************\n";
					cout << "\nCustomer's ID : ";
					cin.ignore();
					getline(cin,id);
					first.FindNode(id);
					cout<< "\n\n\n\t\tPress Enter to continue.."<<endl;
			        cin.get();
			        system("cls");
					break;
			case 3: cout << endl<<endl;
					cout << "\tHave the customer with ID : " << first.getFront() << " take their laundry?"
						 << " (Y - yes  /  N - no)"
						 << "\n\n\t\t: ";
					cin >> decision;
					if( decision=='Y' || decision=='y')
						first.deQueue();
					else
						cout<<"\n\n\t\tCancel deletion..\n\n";
			        cin.get();
			        system("pause");
			        system("cls");
					break;
			case 4: first.display();
					system("pause");
					system("cls");
					break;
			case 5: cout << "\n\n\n\t\tPress Enter to exit.." << endl;
					break;

		}
	} while (ch != 5);

	infile.close();
	outfile.close();
    return 0;
}

