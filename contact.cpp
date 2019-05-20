#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class contact{
private:
	string name;
	string familly;
	string phone;
	string address;
	string email;
	
public:
	contact *next;
	/**
	 * constructor without any parameter
	 * 
	 */
	contact(){};

	/**
	 * constructor with seting information to class
	 * 
	 * @param string name [name of contact]
	 * @param string familly [famillynamename of contact]
	 * @param string phone [phone of contact]
	 * @param string address [address of contact]
	 * @param string email [email of contact]
	 * 
	 */
	contact(string name,string familly,string phone , string address , string email ){

		this->name = name ; this->familly = familly ; this->phone = phone ; this->address = address ; this->email = email; next = NULL;	
	}

	/**
	 * geting the name of contact
	 * @return string name
	 */
	string getName(){ return name;}

	/**
	 * geting the familly name of contact
	 * @return string familly 
	 */
	string getFamilly(){ return familly;}

	/**
	 * geting the phonenumber of contact
	 * @return string phone 
	 */
	string getPhone(){return phone;}

	/**
	 * geting the address of contact
	 * @return string address 
	 */
	string getAddress() { return address;}

	/**
	 * geting the email of contact
	 * @return string email 
	 */
	string getEmail() { return email; }

	/**
	 * seting information for a contact
	 * 
	 * @param string name [name of contact]
	 * @param string familly [famillynamename of contact]
	 * @param string phone [phone of contact]
	 * @param string address [address of contact]
	 * @param string email [email of contact]
	 */
	void setContact(string name,string familly, string phone , string address , string email ){

        this->name = name ; this->familly = familly ; this->phone = phone ; this->address = address ; this->email = email;
    }

    /**
     *
     *  printing all of information for a contact
     */ 
	void getContact(){ cout << name << " " << familly << "  " << phone << "  " << email << "  " << address << endl;  }
};

class contactsList{

private:

	contact *head;
	contact *last;
	int size;

public:
	   contactsList();
	   contact* find(string);
	   void addBegin(string , string ,string , string , string );
	   void addEnd(string , string ,string , string , string );
	   void deleteContact(string);
	   contact* findContact(string);
	   void showContacts();
	   void insertAfter(contact*, string , string , string , string , string );
	   void insertBefore(string, string , string , string , string , string);
};

/**
 *  consructor for contactsList without any paramater
 * 
 */
contactsList::contactsList(){

	head = NULL ; last = NULL; size = 0;

}

/**
 * add contact to end of contactslist
 * 						 equals to push_back in vector
 * 
 * @param string name [name of contact]
 * @param string familly [famillyname of contact]
 * @param string phone [phone of contact]
 * @param string address [address of contact]
 * @param string email [email of contact]
*/
void contactsList::addEnd(string name , string familly ,string phone , string address , string email){

		contact* new_contact = new contact(name, familly , phone , address , email );

		if(last == NULL){

			head = new_contact;
			last = new_contact;
		}

		else{

			last->next = new_contact;
			last = new_contact;

		}

		size++;

	}

/**
 * add contact to begining of contactslist
 * 						 equals to push_front in vector
 * 
 * @param string name [name of contact]
 * @param string familly [famillyname of contact]
 * @param string phone [phone of contact]
 * @param string address [address of contact]
 * @param string email [email of contact]
*/
void contactsList::addBegin(string name , string familly ,string phone , string address , string email){

	contact* new_contact = new contact(name, familly , phone , address , email );

	if( last == NULL || head == NULL ){

		head = new_contact;
		last = new_contact;
	}

	else{

		new_contact->next = head;
		head = new_contact;

	}

	size++;

}

/**
 *
 *	searching list by name or family name or both
 *
 * 	you can type name of contact , famillyname of contact or both with one space seprated in serachQuery parameter
 * 
 * @param string serachQuery [string for searching list]
 * @return contact*   [returing founded contact]
 */
contact* contactsList::find(string serachQuery ){

	contact* n = NULL;

    for( n = head ; n != NULL ; n = n->next)   

    	if( n->getName() == serachQuery || n->getFamilly() == serachQuery || ( n->getName() + " " + n->getFamilly() ) == serachQuery )  {
    	
    	return n;

        }

    return n;

}

/**
 *
 *	printing founded contact in list
 *
 * 	you can type name of contact , famillyname of contact or both with one space seprated in serachQuery parameter
 * 
 * @param string serachQuery [string for searching list]
 * @return contact*   [returing founded contact]
 */
contact* contactsList::findContact(string serachQuery){

	contact* f = find(serachQuery);

	if ( f == NULL ) cout << "\n ================ \n i can't find :|" << endl; else{

		cout << "\n\n" << "----------------------------------------------------------" << endl;
		f->getContact();
		cout << "----------------------------------------------------------" << endl;

	}

	return f;

}

/**
 *
 *	deleting contact in list
 *
 * 	you can type name of contact , famillyname of contact or both with one space seprated in serachQuery parameter
 * 
 * @param string serachQuery [string for searching list]
 * 
 */
void contactsList::deleteContact(string serachQuery){

	if( head->getName() == serachQuery || head->getFamilly() == serachQuery || ( head->getName() + " " + head->getFamilly() ) == serachQuery )  {

		contact* temp = head->next;

		delete head;

		head = temp;

		size--;

		return;

	}
	
	contact* temp = head;
	
	if( temp->next == NULL ){  		
		 cout << "\n ================ \n i can't find :|" << endl;
		 return;	
	}
	
	while( temp->next->getName() != serachQuery && temp->next->getFamilly() != serachQuery && ( head->getName() + " " + head->getFamilly() ) != serachQuery && temp != NULL ){ 

		temp = temp->next;

		if ( temp->next == NULL ) {
			 cout << "\n ================ \n i can't find :|" << endl;
			 return;
		};

	}

    if( temp != NULL ){

	contact* temp2 = temp->next;
	temp->next = temp2->next;
	delete temp2;

	if( last->getName() == serachQuery || last->getFamilly() == serachQuery || ( last->getName() + " " + last->getFamilly() ) == serachQuery ) {

 		last = temp;
	}

	size--;

    }

}

/**
 *
 * inserting new contact to the list after specific contact 
 * 
 * @param contact* n_contact [founded contact by find method of this class]
 * @param string name [name of contact]
 * @param string familly [famillyname of contact]
 * @param string phone [phone of contact]
 * @param string address [address of contact]
 * @param string email [email of contact]
*/
void contactsList::insertAfter(contact* n_contact,string name , string familly , string phone , string address , string email){

	if ( n_contact == NULL ){ cout << "\n ================ \n i can't find :|" << endl; return; }

	contact* new_contact = new contact(name, familly , phone , address , email );

	new_contact->next = n_contact->next;

	n_contact->next = new_contact;

    if(n_contact == last) last = n_contact;

    size++;

}
/**
 *
 * searching specific contact in the list based on searchQuery parameter and add new contact before founded case
 * 
 * @param string sreachQuery [string for searching in the list]
 * @param string name [name of contact]
 * @param string familly [famillyname of contact]
 * @param string phone [phone of contact]
 * @param string address [address of contact]
 * @param string email [email of contact]
*/
void contactsList::insertBefore(string serachQuery,string name , string familly , string phone , string address , string email){

	if( head == NULL ){ cout << "nothing" << endl; return; };

	if( head->getName() == serachQuery || head->getFamilly() == serachQuery || ( head->getName() + " " + head->getFamilly() ) == serachQuery )  {

		addBegin(name,familly,phone,address,email);
		
		return;

	}
	contact* temp = head;

	while( temp->next->getName() != serachQuery && temp->next->getFamilly() != serachQuery && ( head->getName() + " " + head->getFamilly() ) != serachQuery && temp != NULL ){ 

		temp = temp->next;

		if ( temp->next == NULL ) {
			 cout << "\n ================ \n i can't find :|" << endl;
			 return;
		};

	}

    if( temp != NULL ){

	contact* new_contact = new contact(name, familly , phone , address , email );

	new_contact->next = temp->next;
	temp->next = new_contact;



	size++;

    }

}
/**
 * printing all of contacts in the list
 */
void contactsList::showContacts(){

	cout << "\n\n" << "----------------------------------------------------------" << endl;

	if(last == NULL || head == NULL){
 		
 		cout << "nothing" << endl;
 		cout<< "----------------------------------------------------------" << endl;
 		return;

	}
	int c = 1;
	for(contact* n = head ; n != NULL ; n = n->next ) {
		cout << c << ") "; c++;
		n->getContact();
		cout<< "----------------------------------------------------------" << endl;
	}

};

/**
 * prototype for printing dashboard
 * 
 * @return [boolean for Infinite loop]
 */
bool printDashboard();

int main(){

	int n;
	string name , familly , phone , address , email , searching;
	contact* f;
	contactsList a;
    
    while(printDashboard()){

    	cin >> n;

    	switch(n){


    		case 1:

    		  cout << "please enter name , famillyname , phone , address , email by order ( seprate by one space or enter ) :" << endl << " :==> ";
    		  cin >> name >> familly >> phone >> address >> email;
    		  a.addBegin(name,familly,phone,address,email);
    		  cout << "done :D" << endl;

    		break;

    		case 2:

    		  cout << "please enter name , famillyname , phone , address , email by order ( seprate by one space or enter ) :" << endl << " :==>  ";
    		  cin >> name >> familly >> phone >> address >> email;
    		  a.addEnd(name,familly,phone,address,email);
    		  cout << "done :D" << endl;

    		  break;


    		case 3:

    		  cout << "=== searching by name or familly or both ===== \n" << endl << "enter serachQuery :==>";
    		  cin >> searching; f = a.find(searching);
    		  cout << "\n please enter name , famillyname , phone , address , email by order ( seprate by one space or enter ) :" << endl << " :==>  ";
    		  cin >> name >> familly >> phone >> address >> email;
    		  a.insertAfter(f,name,familly,phone,address,email);
    		  break;
    		case 4:
              
              cout << "=== searching by name or familly or both ===== \n" << endl << "enter serachQuery :==>";
    		  cin >> searching;
    		  cout << "\n please enter name , famillyname , phone , address , email by order ( seprate by one space or enter ) :" << endl << " :==>  ";
    		  cin >> name >> familly >> phone >> address >> email;
    		  a.insertBefore(searching,name,familly,phone,address,email);

    		case 5:

    		  cout << "=== searching by name or familly or both ===== \n" << endl << "enter serachQuery :==>";
    		  cin >> searching; f = a.findContact(searching);

    		break;

    		case 6:

    		  cout << "=== searching by name or familly or both ===== \n" << endl << "enter serachQuery :==>";
    		  cin >> searching;
    		  a.deleteContact(searching);

    		case 7:

    		a.showContacts();

    		break;

    		case 8:

    		return 0;

    		break;

    		defult:

    		break;

    	}


    }

	return 0;
}

bool printDashboard(){

	cout << "\n";
	cout << "Select an option by number :" << "\n\n";
	cout << "1 ) add Contact to begining of list" << endl;
	cout << "2 ) add Contact to end of list" << endl;
	cout << "3 ) add Contact after specific contact by searching" << endl;
	cout << "4 ) add Contact before specific contact by searching" << endl;
	cout << "5 ) find specific contact in list by searching based on name and famillyname" << endl;
	cout << "6 ) delete specific contact by searching" << endl;
	cout << "7 ) show all of contacts" << endl;
	cout << "8 ) exit" << endl << "\n";
	cout << "   select : ";
	return true;
}
