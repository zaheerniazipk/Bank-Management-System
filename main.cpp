#include <iostream>
#include <conio.h>
#include <string.h>
#include<windows.h>

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
		long long contact;
		long long cash;
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
	void searchData();
	void transactions();
	void deleteData();
	
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
		cout<<"\n\n\nChoice Menu:"<<endl;
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
//		ch=getch();
		
		// Clear Screen		
		system("CLS");	
		
		// Switch Statement
		switch(ch){
			case '1':
				Bank::personData();
				break;
				
			case '2':
				if(total==0)
				cout<<"No data is entered"<<endl;
				else
				Bank::showData();
				break;
				
			case '3':
				if(total==0)
				cout<<"No data is entered"<<endl;
				else
				Bank::updateData();
				break;
			
			case '4':
				if(total==0)
				cout<<"No data is entered"<<endl;
				else
				Bank::searchData();
				break;

			case '5':
				if(total==0)
				cout<<"No data is entered"<<endl;
				else
				Bank::transactions();
				break;
	
			case '6':
				if(total==0)
				cout<<"No data is entered"<<endl;
				else
				Bank::deleteData();
				break;
	
			case '7':
				exit(0);
				break;
	
			default:
				cout<<"Invalid input"<<endl;
				break;

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
		break;
		
		if(i==total-1){

			cout<<"No such record found"<<endl;

		}
		
	}// end of for loop
	
	
}  // enf of updateData()



void Bank::searchData(){
	cout<<"\n\nEnter id of person, those data you want to search"<<endl;
	cin>>id;


//	cout<<"*********************************************************\n";

	for(int i=0;i<total;i++){
	
		if(id==person[i].ID){
	
			cout<<"Name: "<<person[i].name<<endl;
			cout<<"ID: "<<person[i].ID<<endl;
			cout<<"Address: "<<person[i].address<<endl;
			cout<<"Contact: "<<person[i].contact<<endl;
			cout<<"Cash: "<<person[i].cash<<endl;
			
			break;
	
		}
	
		if(i==total-1){
	
			cout<<"No such record found"<<endl;
	
		}
	
	}
	
}

void Bank::transactions(){

	int cash;
	char ch;

	cout<<"Enter id of person, those data you want to transaction"<<endl;
	cin>>id;

     for(int i=0;i<total;i++){

     	if(id==person[i].ID){
		 	cout<<"Name: "<<person[i].name<<endl;
     		cout<<"Address: "<<person[i].address<<endl;
		    cout<<"Contact: "<<person[i].contact<<endl;
		    cout<<"\nExisting Cash "<<person[i].cash<<endl;
		    
		     cout<<"Press 1 to deposit"<<endl;
		     cout<<"Press 2 to withdraw"<<endl;
		     cin>>ch;
//		     ch=getch();

		     switch(ch){

		     	case '1':

		     		cout<<"How much cash you want to deposit??"<<endl;
		     		cin>>cash;

		     		person[i].cash+=cash;
		     		cout<<"Your new cash is "<<person[i].cash<<endl;

		     		break;

		     	case '2':

		     		back:
		     		cout<<"How much cash you want to withdraw??"<<endl;
		     		cin>>cash;

		     		if(cash>person[i].cash){

		     			cout<<"Your existing cash is just "<<person[i].cash<<endl;
		     			Sleep(3000);
		     			goto back;
					 }

					 person[i].cash-=cash;
					 cout<<"Your new cash is "<<person[i].cash<<endl;

					 break;

				default:
					cout<<"Invalid input"<<endl;
					break;

			 }

			 break;

		 }

		 if(i==total-1){

		 	cout<<"No such record found"<<endl;

		 }

	 }

}

void Bank::deleteData(){

	char ch;

	cout<<"Press 1 to remove specific record"<<endl;

	cout<<"Press 2 to remove full record"<<endl;
	cin>>ch;
//	ch=getch();

	switch(ch){

		case '1':

		cout<<"Enter id of person those data you want to remove"<<endl;
     	cin>>id;

	     for(int i=0;i<total;i++){
	
	     	if(id==person[i].ID){
	
	     		for(int j=i;j<total;j++){
	
	     		person[j].name==person[j+1].name;
	
	     		person[j].ID=person[j+1].ID;
	
	     		person[j].address==person[j+1].address;
	
	     		person[j].contact=person[j+1].contact;
	
	     		person[j].cash=person[j+1].cash;
	
	     		total--;
	
	     		cout<<"Your required data is deleted"<<endl;
	
	     		break;
	
				 }
	
			 }
	
			 if(i=total-1){
	
			cout<<"No such record found"<<endl;
	
			 }
	
		 }
	
		 break;

	 	case '2':

		 	total=0;
	
		 	cout<<"All record is deleted"<<endl;
	
		 	break;	

		default:
			cout<<"Invalid Input"<<endl;
			break;

	}

}


