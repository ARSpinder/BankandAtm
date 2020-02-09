#include<iostream>
#include<iomanip>
#include<fstream>
#include<cctype>
using namespace std;
fstream myfile; //For Bank MANAGEMENT SYSTEM FILE HANDLING
struct node // Node FOR LINK LIST
{

string name; // data member
int Account;
int Address;
int Deposit;
node*next; //node increment
// Constructure
 node()
 {
 next=NULL;
 }
};
// Class OF BANK MANAGEMENT

class bank_Management
{
//pointers to handle the linklist
node *head,*tail,*temp;
// ASSESSMODIFERS

public:
// Head IS NULL
bank_Management()
{
 head=NULL;
}
//function to create nodes
void account (string n,int a,int ad, int de)
{
 //create 1st node...
 if(head==NULL)
 {
 head=new node;
 head->next=NULL;
 head->name=n;
 head->Account=a;
 head->Address=ad;
 head->Deposit=de;
// CREATE A FILE
myfile.open ("bank_Management.txt",ios::out | ios::app);
myfile<<"Name_:_"<<head->name<<"__|__ACCOUNT:_"<<head->Account<<"__|__ADDRESS_:_"<<head->Address<<"__|__DEPOSIT_:_"
<<head->Deposit;
myfile.close();
 }
 //to create new node..
 else
 {
 tail=head;
 while(tail->next!=NULL)
 {
 tail=tail->next;
 }
 temp=new node;
 temp->name=n;
 temp->Account=a;
 temp->Address=ad;
 temp->Deposit=de;
temp->next=NULL;
 tail->next=temp;
 myfile.open ("bank_Management.txt",ios::out | ios::app);

myfile<<"Name_:_"<<temp->name<<"__|__ACCOUNT:_"<<temp->Account<<"__|__ADDRESS_:_"<<temp->Address<<"__|__DEPOSIT_:_"
<<temp->Deposit;
myfile.close();
 }
 }

// Delete Account
void Delete_account(string n)
 {
 tail=head;
 if(head->name==n)
 {
 temp=head;
 head=head->next;
 delete temp;
 }
 else
 {
 while(tail->name!=n)
 {
 if(tail->next==NULL)
 {

 cout<<"Any case of"<<n<<" does not exist"<<endl;
 return ;
 }
 temp=tail;
 tail=tail->next;
 }
 temp->next=tail->next;
 delete tail;
 }

}
// Print IF DELETE ACCount
void print_now()
{
tail=head;
int c;
cout<<"Name "<<" ---> ACCOUNT \tADDRESS \tDeposit"<<endl;
for(c=1;tail->next!=NULL;c++)
{
cout<<"NAME "<<c<<" ---> "<<tail->name<<"\t"<<tail->Account<<"\t"<<tail->Address<<"\t"<<tail->Deposit<<endl;
tail=tail->next;
}
cout<<"NAME "<<c<<" ---> "<<tail->name<<"\t"<<tail->Account<<"\t"<<tail->Address<<"\t"<<tail->Deposit<<endl;
}

// SEARCH ACCOUNT
void search(string n)
{
tail=head;
while(tail!=NULL)
{
if(tail->name==n)
{
char mod;
cout<<"\n\t_________DATA FOUND__________\n\n";
cout<<"Name : "<<tail->name<<endl;
cout<<"ACCOUNT : "<<tail->Account<<endl;
cout<<"ADDRESS : "<<tail->Address<<endl;
cout<<"\nDo You want to modify Phone Number (y/n) : ";
cin>>mod;
if(mod=='y' || mod=='Y')

{
cout<<"Enter YOUR NAME ";
cin>>tail->name;
cout<<"Enter YOUR ADDRESS ";
cin>>tail->Address;
cout<<"Enter YOUR MONEY ";
cin>>tail->Deposit;
cout<<"\n\t_________Data Updated________"<<endl;
}
break;
}
tail=tail->next;
}
if(tail==NULL)
cout<<"\n\t_______DATA NOT FOUND_________\n\n";
}
// SHOW PRINT
void print()
{
//this function reads the data from file
string s;
myfile.open("bank_Management.txt",ios::in);
while(!myfile.eof())
{
myfile>>s;

cout<<s<<endl;
}
myfile.close();
}



};

// ATM CLASS
class Atm
{

  int atm_account;
  char atm_name[50];
  int atm_deposit;
  int atm_widh;

public:
  void createatm_account();
  void show_account() const; //The const declaration creates a read-only reference
  void dep(int); // Deposit Funstion
  void draw(int); //Widhdrawl Money
  void report() const; // Report
  int retacno() const; // Report Account
  int retdeposit() const; // Report Deposit

};

void Atm::createatm_account()
{

	cout<<"\n\t\t\tEnter the Account No. : ";
	cin>>atm_account;
	cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(atm_name,50);
	cout<<"\n\t\t\tEnter MONEY TO Deposit : ";
	cin>>atm_deposit;
	cout<<"\n\n\t\t\tAccount Created..";
}

void Atm::show_account() const
{
	cout<<"\n\t\t\tAccount No. : "<<atm_account;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<atm_name;
	cout<<"\n\t\t\tBalance amount : "<<atm_deposit;
}
// Increament Deposit
void Atm::dep(int x)
{
	atm_deposit+=x;
}

// Widhdrawl
void Atm::draw(int x)
{
	atm_deposit-=x;
}
// Show Report
void Atm::report() const
{
	cout<<atm_account<<setw(10)<<" "<<atm_name<<setw(10)<<" "<<atm_deposit<<endl;
}

int Atm::retacno() const
{
	return atm_account;
}

int Atm::retdeposit() const
{
	return atm_deposit;
}


// File Handling OF ATM

void write_account();
void display_sp(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);

// MAin FUNCTION
int main()
{
  	Atm ac;
 bank_Management obj; // Call Class

   int num;
int i,p,ch;
string n;
int a,ad,de;
int Na;
char user;
char atmch;

cout<<setw (50)<<"BANK MANAGEMENT SYSTEM 2020 "<<endl;
cout<<endl;
cout<<endl;
cout<<"[A] TO BANK MANAGEMENT SYSTEM "<<endl;
cout<<"[B] TO GO TO ATM MANAGEMENT SYSTEM"<<endl;
cout<<endl;

cin>>user;

if (user=='a' || user=='A')

{

  do
  {
    cout<<setw (50)<<"BANK MANAGEMENT SYSTEM 2020 "<<endl;
    cout<<endl;
    cout<<endl;
    cout<< setw (20)<<"[1] Create A NEW ACCOUNT"<<endl;
    cout<<setw (20)<< "[2] DELETE OR CLOSE YOUR ACCOUNT "<<endl;
    cout<<setw (20)<< "[3] SEARCH AND MODIFY YOUR ACCOUNT "<<endl;
    cout<<setw (10)<< "[4] SELL ALL ACCOUNT LIST "<<endl;
    cout<<setw (5)<< "[5] EXIT"<<endl;
    cout<< setw (20)<< "Select Your Option (1-4): "<<endl;
  cin>>ch;
  switch(ch)
  {
   case 1:
  cout<<"\n\t============CREATING A NEW  ACCOUNT============================\n\n";
   cout<<"Enter DATA To OPEN A NEW ACCOUNT'"<<endl;
   cout<<"\nPlease Enter Your Full Name \t";
   cin>>n;
   cout<<"\nEnter Your Account Number \t";
   cin>>a;
   cout<<"Please Enter Full Address \t";
   cin>>ad;
   cout<<"Please Enter Money to  Deposit \t";
   cin>>de;
   obj.account(n,a,ad,de);
   cout<<"Your Account "<<n<<" has been Created "<<endl;
   break;
   case 2:
  cout<<"\n\t============DELETE YOUR ACCOUNT============================\n\n";
   cout<<"\nEnter name of person whose ACCOUNT you want to delete\n"<<endl;
   cin>>n;
   obj.Delete_account(n);
   cout<<"YOUR ACCOUNT "<<n<<" Has been removed from OUR list"<<endl;
   break;
   case 3:
  cout<<"\n\t============-> SEARCH AND MODIFY YOUR ACCOUNT <-=========================\n\n";
   cout<<"Enter NAME of Person to search it from list\t";

   cin>>n;
   obj.search(n);
   break;
  case 4:
  cout<<"\n\t============-> SEE ALL LIST <-=========================\n\n";
   obj.print();
    break;


   default:
   cout<<"\t----------Invalid----------"<<endl;
  }
  }
  while(ch!=5);
  cout<<"\nTHANK YOU"<<endl;
}


else if (user=='b' || user=='B')
{

  do
  {

  cout<<"\n\n\t\t\t\t======================"<<endl;
  cout<<setw (50)<<"ATM MANAGEMENT SYSTEM"<<endl;
  cout<<setw (50)<<"======================\n"<<endl;

    cout<<setw (20)<<"::MAIN MENU::\n"<<endl;
    cout<<setw (20)<<"[1] CREATE A NEW ACCOUNT"<<endl;
    cout<<setw (15)<<"[2] DEPOSIT AMOUNT"<<endl;
    cout<<setw (18)<<"[3] WITHDRAW AMOUNT"<<endl;
    cout<<setw (18)<<"[4] BALANCE ENQUIRY"<<endl;
    cout<<setw (20)<<"[5] ALL ACCOUNT HOLDER LIST"<<endl;
    cout<<setw (20)<<"[6] CLOSE AN ACCOUNT"<<endl;
    cout<<setw (5)<<"[7] EXIT"<<endl;
    cout<<"Select Your Option (1-7): "<<endl;
    cin>>atmch;

    switch(atmch)
    {
    case '1':
      write_account();
      break;
    case '2':
      cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
      deposit_withdraw(num, 1);
      break;
    case '3':

      cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
      deposit_withdraw(num, 2);
      break;
    case '4':
      cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
      display_sp(num);
      break;
    case '5':
      display_all();
      break;
      case '6':

        cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
        delete_account(num);
        break;

       default :cout<<"\a";
}
cin.ignore();
cin.get();
}
while(ch!='7');
return 0;


}

}

// FILE HANDLING FUNCTION CALL

void write_account()
{
	Atm ac;
	ofstream outFile;
	outFile.open("atmaccount.dat",ios::binary|ios::app);
	ac.createatm_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Atm));
	outFile.close();
}


void display_sp(int n)
{
		Atm ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("atmaccount.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Atm)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist";
}

void delete_account(int n)
{
	Atm ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("atmaccount.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Atm)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Atm));
		}
	}
    inFile.close();
	outFile.close();
	remove("atmaccount.dat");
	rename("Temp.dat","atmaccount.dat");
	cout<<"\n\nRecord Deleted ..";
}

void display_all()
{
	system("CLS");
	Atm ac;
	ifstream inFile;
	inFile.open("atmaccount.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           ACCOUNT  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Atm)))
	{
		ac.report();
	}
	inFile.close();
}

void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	Atm ac;
	fstream File;
    File.open("atmaccount.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Atm));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\t\t\tTO DEPOSITSS AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(Atm));
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}
