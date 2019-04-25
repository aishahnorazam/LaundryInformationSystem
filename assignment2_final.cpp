//SCSJ2013 - DATA STRUCTURE AND ALGORITHMS
//PREPARED BY: 
//1.AISHAH AINI BINTI NOR'AZAM (A16CS0230)
//2.DALILA AL-HUSNA BINTI KHAIRUD-DIN (A16CS0032)
//3.PRASASTI TUNGGAL MALAYA (A16CS)
//4.NURUL AFIQAH BINTI ANUAR (A16CS0230)

//SECTION:03
//LECTURER: DR NOR BAHIAH BINTI HJ AHMAD
//TASK:ASSIGNMENT 2


#include <iostream> 
#include <iomanip> 
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std; 

ifstream infile;
ofstream outfile;

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
	NodeLaundry()	//default constructor
	{
	}
};

class List {
public:
	List(void) { head = NULL; }	// constructor
//	~List(void);				// destructor

	bool IsEmpty() { return head == NULL; }
	void InsertNode(string Name, string id , int Type , int Date , string Month , string no, float total);	
	int FindNode(string a);	
	int DeleteNode(string x);
	void DisplayList(void);
private:
	NodeLaundry* head;
};

void List::InsertNode(string Name, string id , int Type , int Date , string Month , string no, float total )
{		
	int currIndex	=	0;
	NodeLaundry* currNode	=	head;
	NodeLaundry* prevNode	=	NULL;
	while (currNode != NULL  && id > currNode->custID) {
		prevNode = currNode;
        currNode = currNode->next;
		currIndex++;
	}
		
	NodeLaundry* newNode	=	new	NodeLaundry(Name , id, Type,Date,Month, no, total);
//	newNode->data	=	x;	
	if (currIndex == 0) {
		newNode->next	=	head;
		head		=	newNode;
	}
	else {
		newNode->next	=	prevNode->next;
		prevNode->next	=	newNode;
	}
	//return newNode;
}

void List::DisplayList()
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
   
   	int num		=	0;
   	NodeLaundry* currNode	=	head;
    
   	while (currNode != NULL)
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
		num++;
  	 }
  	 cout <<" ||--------------------------------------------------------------------------------||" << endl;
  	 outfile <<" ||--------------------------------------------------------------------------------||" << endl;
	
}

int List::FindNode(string id) {
	NodeLaundry* currNode	=	head;
	int currIndex	=	1;
	cout <<endl<<endl<<endl;
	cout <<" ||------------------------------CUSTOMERS RECORD------------------------------||" << endl;
	cout <<" ||----------------------------------------------------------------------------||" << endl;
	cout << "\tNAME\t\tID\tTYPE\tDATE\tPHONE NO\tPRICE (RM)"<<endl;
	cout <<" ||----------------------------------------------------------------------------||" << endl;
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
		cout << "\t"<< currNode->No;
		cout << "\t"<< fixed << setprecision(2) << currNode->price << endl;
		return currIndex;
	}
	
	else
	{
		cout << "\n\n\t\tCustomer ID : " << id << " is not found in system!" <<endl;
		return 0;
	}
}

int List::DeleteNode(string id) 
{

	NodeLaundry* prevNode	=	NULL;
	NodeLaundry* currNode	=	head;
	int currIndex	=	1;
	while (currNode && currNode->custID != id) {
		prevNode	=	currNode;
		currNode	=	currNode->next;
		currIndex++;
	}
	if (currNode) {
		if (prevNode) {
			prevNode->next	=	currNode->next;
			delete currNode;
			currNode = NULL;
			cout << "\n\n\t\t!! ID has been deleted !!"<< endl;
		}
		else {
			head		=	currNode->next;
			delete currNode;
			currNode = NULL;
			cout << "\n\n\t\t!! ID has been deleted !! " << endl;
		}
		return currIndex;
	}
	return 0;
}


int main(void)
{ 
	List aList;
	string name, id , month , No;
	float price;
	int date , type, qty ;
	int ch; 
	
	infile.open("Input_Cust.txt" , ios::in);
	outfile.open("Cust_List2.txt" , ios::out | ios::trunc);
	
	while(infile>> name >> id >> type >> date >> month >> No >> price)
	{
		aList.InsertNode(name , id, type, date, month, No, price);
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
						aList.InsertNode(name, id , type , date, month , No, price);
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
					aList.FindNode(id);
					cout<< "\n\n\n\t\tPress Enter to continue.."<<endl;
			        cin.get();
			        system("cls");
					break;
			case 3: cout << endl<<endl;
					cout << "\tEnter Customer ID to Delete Customer Details: " << endl;
					cout << "\n\t*************************************\n";
					cout << "\nCustomer's ID : ";
					cin.ignore();
					getline(cin,id);
					if (aList.FindNode(id) > 0)
					{
					
						aList.DeleteNode(id);
					}
					else
						cout << "\n\n\t\tCustomer ID : " << id << " is not found in system!" <<endl;
					cout<< "\n\n\n\t\tPress Enter to continue.."<<endl;
			        cin.get();
			        system("cls");
					break;
			case 4: aList.DisplayList();
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
