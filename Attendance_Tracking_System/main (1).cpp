
#include <iostream>// no need to write if fstream is included.
#include <string>
#include <fstream>//In C++ the concept of the fstream is used for the reading and writing on the file system.
#include <cstring>//CString is neither a C nor a C++ type. It appears to be a Microsoft invention that is essentially an alternative to std::string: CString objects can grow as a result of concatenation operations.

using namespace std;

int adminView();
int studentView();
int studentLogin();
int checkCredentials(string userName, string password);
int deleteAllStudents();
int checkListOfStudentsRegistered();
int getListOfStudentsWithTheirPresenseCount();
int registerStudent();
int adminLogin();
int registerStudent();
int markMyAttendance(string username);
int countMyAttendance(string username);
int delay();

int delay()
{
for(int i = 0; i<3; i ++)
{
	cout<<"\n Saving Records ...";

}

cout<<"\n Exiting Now ...";
for(int i = 0; i<3; i ++){

}
return 0;
}

int adminView()
{
int goBack = 0;
while(1)
{
system("cls");
cout<<"\n 1 Register a Student";
cout<<"\n 2 Delete All students name registered";
cout<<"\n 3 Check List of Student registered by user name";
cout<<"\n 4 Get List of student with their attendance count";
cout<<"\n 0. Go Back <- \n";
int choice;

cout<<"\n Enter you choice: ";
cin>>choice;

switch(choice)
{
	case 1: registerStudent();break;
	case 2: deleteAllStudents(); break;
	case 3: checkListOfStudentsRegistered(); break;
	case 4
	: getListOfStudentsWithTheirPresenseCount(); break;
	case 0: goBack = 1;break;
    default: cout<<"\n Invalid choice. Enter again ";
    getchar();
}

if(goBack == 1)
{
break; //break the loop
}

}

return 0;
}

int studentLogin()
{
system("cls");
cout<<"\n -------- Student Login ---------";
studentView();
delay();
return 0;
}


int adminLogin()
{
system("cls");
cout<<"\n --------- Admin Login --------";

string username;
string password;

cout<<"\n Enter username : ";
cin>>username;
cout<<"\n Enter password : ";
cin>>password;

if(username=="anjali" && password=="anjali@12")
{
    adminView();
    getchar();
    delay();
}
else
{
cout<<"\n Error ! Invalid Credintials..";
cout<<"\n Press any key for main menu ";
getchar();getchar();
}

return 0;
}


int checkStudentCredentials(string username, string password)
{
// read file line by line & check if username-password.dat exist?
// if it exsist return 1 else 0

ifstream read;

read.open(username+".txt");

if (read) {
// The file exists, and is open for input
int recordFound = 0;
string line;
string temp = username + password;
cout<<"\n file name is : "<<temp;
while(getline(read, line)) {
	if(line == temp)
	{
		recordFound = 1;
		break;
	}
}

if(recordFound == 0)
    return 0;
else
   return 1;
}
else
{
   return 0;
}

}




int studentView()
{
cout<<"\n ------- Student Login-------- \n";

string username, password;

cout<<"\n Enter username : ";
cin>>username;

cout<<"\n Enter password : ";
cin>>password;

int res = checkStudentCredentials(username, password);

if(res  == 0)
{
   cout<<"\n Invalid Credentials !!";
   cout<<"\n Press any key for Main Menu..";
   getchar(); getchar();
   return 0;
}

int goBack = 0;
while(1)
{
system("cls");

cout<<"\n 1 Mark Attendance for Today ";
cout<<"\n 2 Count my Attendance";
cout<<"\n 0. Go Back <- \n";
int choice;

cout<<"\n Enter you choice: ";
cin>>choice;

switch(choice)
{
	case 1: markMyAttendance(username); break;
	case 2: countMyAttendance(username); break;
	case 0: goBack = 1;break;
    default: cout<<"\n Invalid choice. Enter again ";
    getchar();
}

if(goBack == 1)
{
break; //break the loop
}

}

}

int markMyAttendance(string username)
{
cout<<"\n Mark your attendance out of 8!!"<<endl;
string att;
cin>>att;
ofstream out1;
	string temp = username+"_att"+".txt";
	out1.open(temp.c_str());//It returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object
	out1<<att;
	out1.close();


cout<<"\n Please any key to continue..";


getchar();getchar();

return 0;
}

int countMyAttendance(string username)
{

ifstream read;
read.open(username+"_att"+".txt");
if(read)
{
    string line;
    getline(read, line);
    	char name[100];
    	strcpy(name, line.c_str());
    	cout<<"\n your attended "<<name<<" out of 8 lectures";
    	//cout<<int(name)<<endl;


     read.close();
}



cout<<"\n Please any key to continue..";


getchar();getchar();

return 0;
}

int deleteAllStudents()
{

ifstream read;
read.open("project.txt");
if(read)
{   int recordFound =0;
    string line;
    while( (read)) {
        line=line+".txt";
        char name[100];
        strcpy(name, line.c_str());
        remove(name);
    }
     read.close();
}
std::ifstream File;
std::string filepath="project.txt";
File.open(filepath.c_str(),std::ifstream::out | std::ifstream::trunc);
File.close();

cout<<"\n In delete all students !!";
cout<<"\n Please any key to continue..";


getchar(); getchar();
return 0;
}

int getListOfStudentsWithTheirPresenseCount()
{

ifstream read;
read.open("project.txt");
if(read)
{   int recordFound =0;
    string line;
    while(getline(read, line)) {
    	char name[100];
    	strcpy(name, line.c_str());
    	char onlyname[100];
    	strcpy(onlyname, name);
    	cout<<endl;
    	cout<<onlyname<<" ";
    	string l=onlyname;
    	ifstream read;
        read.open(l+"_att"+".txt");
        if(read)
        {
        string line;
        getline(read, line);
    	char name[100];
    	strcpy(name, line.c_str());
    	cout<<"attended "<<name<<" out of 8 lectures";
    	//cout<<int(name)<<endl;


     read.close();
}
    }
     read.close();
}
else
{
cout<<"\n No Record found :(";
}
cout<<"\n Please any key to continue..";
getchar(); getchar();
return 0;
}

int checkListOfStudentsRegistered(){
cout<<"\n - Check List of Student Registered by Username-- ";
//check if record already exist..
ifstream read;
read.open("project.txt");
if(read)
{   int recordFound =0;
    string line;
    while(getline(read, line)) {
    	char name[100];
    	strcpy(name, line.c_str());
    	char onlyname[100];
    	strcpy(onlyname, name);
    	cout<<endl;
    	cout<<onlyname<<endl;
    }
     read.close();
}
else
{
cout<<"\n No Record found :(";
}
cout<<"\n Please any key to continue..";
getchar(); getchar();
return 0;
}
int registerStudent()
{
    cout<<"\n ----- Form to Register Student ---- \n";

    string name, username, password, rollno, address, father, mother;

    cout<<"\n Enter Name : ";     cin>>name;
    cout<<"\n Enter Username : ";     cin>>username;
    cout<<"\n Enter password : ";     cin>>password;
    cout<<"\n Enter rollno : ";     cin>>rollno;
    getchar();

    char add[100];
    cout<<"\n Enter address : ";     cin.getline(add, 100);
    cout<<"\n Enter father : ";     cin>>father;
    cout<<"\n Enter mother : ";     cin>>mother;

    //check if record already exist..
    ifstream read;
    read.open("project.txt");

    if(read)
    {   int recordFound =0;
	   string line;
	    while(getline(read, line)) {
    	if(line == username )
    	{
    		recordFound = 1 ;
    	    break;
		}
        }
        if(recordFound == 1)
        {
    	cout<<"\n Username already Register. Please choose another username ";
    	getchar(); getchar();
    	delay();
    	read.close();
    	return 0;
		}
	}
    read.close();

    ofstream out;
	out.open("project.txt", ios::app);
	out<<username<<"\n";
	out.close();

	ofstream out1;
	string temp = username+".txt";
	out1.open(temp.c_str());
	out1<<name<<"\n"; 	out1<<username; 	out1<<password<<"\n";
	out1<<rollno<<"\n"; 	out1<<add<<"\n"; 	out1<<father<<"\n";
	out1<<mother<<"\n";
	out1.close();

	cout<<"\n Student Registered Successfully !!";

    cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;
}



int main(int argc, char** argv) {

while(1)
{
	system("cls");
	cout<<"\n Attendance Management System \n";
	cout<<"-------------------------------------\n\n";

	cout<<"1. Student Login\n";
	cout<<"2. Admin Login\n";

	cout<<"0. Exit\n";
	int choice;

	cout<<"\n Enter you choice: ";
	cin>>choice;

	switch(choice)
	{
	case 1: studentLogin(); break;
	case 2: adminLogin(); break;
	case 0:
	        while(1)
	        {
		    system("cls");
        	cout<<"\n Are you sure, you want to exit? y | n \n";
        	char ex;
        	cin>>ex;
        	if(ex == 'y' || ex == 'Y')
        	   exit(0);
        	else if(ex == 'n' || ex == 'N')
             {
             	 break;
             }
             else{
             	cout<<"\n Invalid choice !!!";
             	getchar();
             }

     	   }
            break;

    default: cout<<"\n Invalid choice. Enter again ";
    getchar();
	}

}

return 0;
}
