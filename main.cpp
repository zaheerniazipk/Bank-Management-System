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
		
		cout<<"\n\nChoice Menu:"<<endl;
		cout<<"************************************************************"<<endl;
		cout<<"1. Create a new account"<<endl;
		cout<<"2. View customer's list"<<endl;
		cout<<"3. Update information of an existing account"<<endl;
		cout<<"4. Check the details of an existing account"<<endl;
		cout<<"5. Withdraw or deposit transactions"<<endl;
		cout<<"6. Remove an existing Account"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"************************************************************\n"<<endl;
		
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
				if(total==0){
				cout<<"\n************************************************************"<<endl;
				cout<<"No data is entered"<<endl;
				}
				else
				Bank::showData();
				break;
				
			case '3':
				if(total==0){
					cout<<"\n************************************************************"<<endl;
					cout<<"No data is entered"<<endl;
				}
				else
				Bank::updateData();
				break;
			
			case '4':
				if(total==0){
					cout<<"\n************************************************************"<<endl;
					cout<<"No data is entered"<<endl;
				}
				else
				Bank::searchData();
				break;

			case '5':
				if(total==0){
					cout<<"\n************************************************************"<<endl;
					cout<<"No data is entered"<<endl;
				}
				else
				Bank::transactions();
				break;
	
			case '6':
				if(total==0){
					cout<<"\n************************************************************"<<endl;
					cout<<"No data is entered"<<endl;
				}
				else
				Bank::deleteData();
				break;
	
			case '7':
				cout<<"\n************************************************************\n"<<endl;
				cout<<"        Thanks for Using our Software! \n";
				cout<<"\n************************************************************"<<endl;
				exit(0);
				break;
	
			default:
				cout<<"Invalid input"<<endl;
				break;

		}//end of switch	
		
 	} // end of while loop

} // end of choice()


void Bank::personData(){
	
	cout<<"***************************************************************\n";
	cout<<"              Creating new account \n";
	cout<<"***************************************************************\n\n";
	
	
	cout<<"Enter data of a person "<<total+1<<endl;
	cout<<"*********************************************************\n";
	
	cout<<"Person name            :  ";
	cin.ignore();
	cin.getline(person[total].name, 50);
	
	
	cout<<"ID                     :  ";
	cin>>person[total].ID;
	
	cout<<"Address                :  ";
	cin.ignore();
	cin.getline(person[total].address, 50);
	
	
	cout<<"Contact                :  ";
	cin>>person[total].contact;
	
	cout<<"Cash                   :  ";
	cin>>person[total].cash;
	
	cout<<"***************************************************************\n";
	
	total++;  	// increment	
	
	cout<<"Data entered successfully!\n\n\n";
	
} // end of personData()


void Bank::showData(){
	
	cout<<"***************************************************************\n";
	cout<<"              Record list of an account holders \n";
	cout<<"***************************************************************\n\n";
	
	// show customers data
	for (int i=0; i<total; i++){
	
		cout<<"Data of a person "<<i+1<<endl;
		cout<<"*********************************************************\n";
		cout<<"Name                :  "<<person[i].name<<endl;
		cout<<"ID                  :  "<<person[i].ID<<endl;
		cout<<"Address             :  "<<person[i].address<<endl;
		cout<<"Contact             :  "<<person[i].contact<<endl;
		cout<<"Cash                :  "<<person[i].cash<<endl;
		cout<<"***************************************************************\n";
		
	} // end of loop
	
} // end of showData()


void Bank::updateData(){
	cout<<"***************************************************************\n";
	cout<<"              Updating data of an account holder \n";
	cout<<"***************************************************************\n\n";

	cout<<"Enter id of person, whom data you want to update : ";
	cin>>id;
	
	for (int i=0; i<total; i++){
		if (id == person[i].ID){
			
			// Previous Data			
			cout<<"\n\nPrevious Data of a person "<<i+1<<endl;
			cout<<"*********************************************************\n";
			cout<<"Name                :  "<<person[i].name<<endl;
			cout<<"ID                  :  "<<person[i].ID<<endl;
			cout<<"Address             :  "<<person[i].address<<endl;
			cout<<"Contact             :  "<<person[i].contact<<endl;
			cout<<"Cash                :  "<<person[i].cash<<endl;
			cout<<"***************************************************************\n\n\n";
			
			// Updating Data
			cout<<"Update Newer Data "<<i+1<<endl;
			cout<<"*********************************************************\n";
			cout<<"Person name         :  ";
			cin.ignore();
			cin.getline(person[total].name, 50);
			
			
			cout<<"ID                  :  ";
			cin>>person[total].ID;
			
			cout<<"Address             :  ";
			cin.ignore();
			cin.getline(person[total].address, 50);
			
			
			cout<<"Contact             :  ";
			cin>>person[total].contact;
			
			cout<<"Cash                :  ";
			cin>>person[total].cash;
			
			cout<<"***************************************************************\n";			
			
		} // end of if conditonal statement
		break;
		
		if(i==total-1){
			cout<<"\n************************************************************"<<endl;
			cout<<"No such record found"<<endl;

		}
		
	}// end of for loop
	
	
}  // enf of updateData()



void Bank::searchData(){
	cout<<"***************************************************************\n";
	cout<<"              Search data of an account holder \n";
	cout<<"***************************************************************\n\n";
	
	cout<<"Enter id of person, whom data you want to search : ";
	cin>>id;


	for(int i=0;i<total;i++){
	
		if(id==person[i].ID){
			cout<<"\n\nData of a person "<<i+1<<endl;
			cout<<"*********************************************************\n";
			cout<<"Name                :  "<<person[i].name<<endl;
			cout<<"ID                  :  "<<person[i].ID<<endl;
			cout<<"Address             :  "<<person[i].address<<endl;
			cout<<"Contact             :  "<<person[i].contact<<endl;
			cout<<"Cash                :  "<<person[i].cash<<endl;
			cout<<"***************************************************************\n";
				
			break;
	
		}
	
		if(i==total-1){
			cout<<"\n************************************************************"<<endl;
			cout<<"No such record found"<<endl;
	
		}
	
	} // end of for loop
	
} // enf of searchData()


void Bank::transactions(){
	
	cout<<"***************************************************************\n";
	cout<<"              Transactions of an account holder \n";
	cout<<"***************************************************************\n\n";

	int cash, a , b;
	char ch;

	cout<<"Enter id of person, whom need to withdraw/deposit amount : ";
	cin>>id;

     for(int i=0;i<total;i++){

     	if(id==person[i].ID){
     		cout<<"\n\nData of a person "<<i+1<<endl;
     		cout<<"*********************************************************\n";
		 	cout<<"Name                :  "<<person[i].name<<endl;
     		cout<<"Address             :  "<<person[i].address<<endl;
		    cout<<"Contact             :  "<<person[i].contact<<endl;
		    cout<<"Existing Cash       :  "<<person[i].cash<<" Rupees"<<endl;
		    cout<<"***************************************************************\n";
		    
		    
		    cout<<"\n\nChoice Menu:"<<endl;
			cout<<"************************************************************"<<endl;
		    cout<<"1. Deposit amount "<<endl;
		    cout<<"2. Withdraw amount "<<endl;
		    cout<<"************************************************************\n"<<endl;
		    
		    cout<<"Your Choice : ";
		    cin>>ch;
//		     ch=getch();

		     switch(ch){

		     	case '1':
					cout<<"\n\n     Deposit amount \n";
					cout<<"***************************************************************\n";
					
		     		cout<<"How much cash you want to deposit : ";
		     		cin>>cash;
		     		
		     		a = person[i].cash;
		     		b = cash;
		     		person[i].cash+=cash;
		     		
		     		cout<<"Your new cash is "<<a<<" + "<<b<<" = "<<person[i].cash<<endl;
		     		cout<<"************************************************************\n"<<endl;

		     		break;

		     	case '2':

		     		back:
		     		
		     		cout<<"\n\n     Withdraw amount \n";
					cout<<"***************************************************************\n";
					
		     		cout<<"How much cash you want to withdraw : ";
		     		cin>>cash;

		     		if(cash>person[i].cash){

		     			cout<<"Your existing cash is just "<<person[i].cash<<endl;
		     			Sleep(3000);
		     			goto back;
					}
					
					a = person[i].cash;
		     		b = cash;
					person[i].cash-=cash;
				
					cout<<"Your new cash is "<<a<<" - "<<b<<" = "<<person[i].cash<<endl;
		     		cout<<"************************************************************\n"<<endl;

					break;

				default:
					cout<<"Invalid input"<<endl;
					break;

			 }

			 break;

		 }

		 if(i==total-1){
			cout<<"\n************************************************************"<<endl;
		 	cout<<"No such record found"<<endl;

		 }

	 } // end of for loop

} // end of transactions()



void Bank::deleteData(){
	
	cout<<"***************************************************************\n";
	cout<<"              Removing/Deleting an account from record list \n";
	cout<<"***************************************************************\n\n";

	char ch;
	
	cout<<"\nChoice Menu:"<<endl;
	cout<<"************************************************************"<<endl;
	cout<<"1. Remove specific person account from record list"<<endl;
	cout<<"2. Remove full record list of account holders"<<endl;
	cout<<"************************************************************\n"<<endl;
		 
	cout<<"Your Choice : ";	    
	cin>>ch;
//	ch=getch();

	switch(ch){
	   case '1':
	  	
		cout<<"\nEnter id of person, whom data you want to remove : ";
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
		     		
		     		cout<<"\n************************************************************\n"<<endl;
		     		cout<<"Your required data is deleted"<<endl;
	
	     			break;
	
				 } // end of inner for loop
	
			 } // end of if statement
	
			 if(i=total-1){
				cout<<"No such record found"<<endl;
				cout<<"************************************************************\n"<<endl;
			 } // end of if statement
			 
		 }  // end of for outer loop
	
	    break;

	   case '2':
		  	total=0;
		  	cout<<"\n************************************************************"<<endl;
			cout<<"All record is deleted"<<endl;
			break;	

		default:
			cout<<"\n************************************************************"<<endl;
			cout<<"Invalid Input"<<endl;
			break;

	}

}


