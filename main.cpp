#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;


//	Base Class
class Bank {
	private:
	//	data members
	int total;
	string id;
	
	// Structure	
	struct person {
		char name[50], address[50];
		string ID;
		double contact, cash;
	} person[100]; 			//only 100 people allowed
	
	
	public:
	
	// Default Constructor
	Bank(){
		total = 0;
	}	
		 
	// Member Functions Declaration
	void choice();	
	void personData();
	void showData();
	void updateData();
	
}; // end of class


// Main Function
int main(){
	
	cout<<"************************************************************************************\n"
	    <<"*                              Bank Management System                              *\n"
		<<"************************************************************************************\n\n";	
	
	// instaniate an object	
	Bank b;
	
	// calling member functions using object
	b.choice();
	
	
	getch(); // get characters
	
} // end of main function


// Member functions definition outside class

void Bank::choice(){
	
	while (1){
		cout<<"\nChoice Menu:"<<endl;
		cout<<"************************************************************\n"<<endl;
		cout<<"1. Create a new account"<<endl;
		cout<<"2. View customer's list"<<endl;
		cout<<"3. Update information of an existing account"<<endl;
		cout<<"4. Check the details of an existing account"<<endl;
		cout<<"5. For transactions"<<endl;
		cout<<"6. Remove an existing Account"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"\n************************************************************\n"<<endl;
		
		char ch;
		cout<<"Your Choice : ";
		cin>>ch;
		
			
		// Switch Statement
		switch(ch){
			case '1':
				Bank::personData();
				break;
				
			case '2':
				Bank::showData();
				break;
				
			case '3':
				break;
			
			case '4':
				break;
			
			case '5':
				break;
			
			case '6':
				break;
			
			case '7':
				exit(0);
				break;
				
			default:
				cout<<"Please enter a valid value, Try Again \n\n";
				
	}//end of switch	
		
 } // end of while loop

} // end of choice()


void Bank::personData(){
	cout<<"\n\nEnter data of a person "<<total+1<<endl;
	
	cout<<"*********************************************************\n";
	
	cout<<"Person name : ";
	cin.ignore();
	cin.getline(person[total].name, 50);
	
	
	cout<<"ID : ";
	cin>>person[total].ID;
	
	cout<<"Address : ";
	cin.ignore();
	cin.getline(person[total].address, 50);
	
	
	cout<<"Contact : ";
	cin>>person[total].contact;
	
	cout<<"Cash : ";
	cin>>person[total].cash;
	
	cout<<"\n***************************************************************\n";
	
	total++;  	// increment	
	
} // end of personData()


void Bank::showData(){
	// show customers data
	for (int i=0; i<total; i++){
		cout<<"\n\n";
		cout<<"*********************************************************\n";
		cout<<"Data of a person "<<i+1<<endl;
		cout<<"Name : "<<person[i].name<<endl;
		cout<<"ID : "<<person[i].ID<<endl;
		cout<<"Address : "<<person[i].address<<endl;
		cout<<"Contact : "<<person[i].contact<<endl;
		cout<<"Cash : "<<person[i].cash<<endl;
		cout<<"\n***************************************************************\n";
		
	} // end of loop
	
} // end of showData()


void Bank::updateData(){
	cout<<"Enter id of person, those data you want to update : ";
	cin>>id;
	
	for (int i=0; i<total; i++){
		if (id == person[i].ID){
			
			// Previous Data			
			cout<<"Previous Data of a person : "<<endl;
			cout<<"*********************************************************\n";
			cout<<"Data of a person "<<i+1<<endl;
			cout<<"Name : "<<person[i].name<<endl;
			cout<<"ID : "<<person[i].ID<<endl;
			cout<<"Address : "<<person[i].address<<endl;
			cout<<"Contact : "<<person[i].contact<<endl;
			cout<<"Cash : "<<person[i].cash<<endl;
			cout<<"\n***************************************************************\n\n";
			
			// Updating Data
			cout<<"Enter Newer Data : "<<endl;
			cout<<"*********************************************************\n";
			cout<<"Person name : ";
			cin.ignore();
			cin.getline(person[total].name, 50);
			
			
			cout<<"ID : ";
			cin>>person[total].ID;
			
			cout<<"Address : ";
			cin.ignore();
			cin.getline(person[total].address, 50);
			
			
			cout<<"Contact : ";
			cin>>person[total].contact;
			
			cout<<"Cash : ";
			cin>>person[total].cash;
			
			cout<<"\n***************************************************************\n";			
			
		} // end of if conditonal statement
		
	} // end of for loop
	
}  // enf of updateData()


