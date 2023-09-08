#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;




struct Contact{
	

	string name;
	string address;
	string phone;
	
	
};

    int size=0;
     struct Contact data;


void Add(struct Contact);
void Search(string);
void Delete(string);
void Update(string);
void Display();

int main(){
	

	string user;
	
	do{
		
		cout<<"Enter which function want to use : "<<endl;
		cout<<"add / delete / search / update / display / exit"<<endl;	
		cin>>user;
		
		
		if(user=="add"){
			
			//taking input info and writing to the file
			Add(data);
			
		}else if(user=="search"){
			
			string name;
			cout<<"Enter name to find record :";
			cin>>name;
			
			Search(name);
			
		}else if(user=="delete"){
			
			string d;
			cout<<"Enter name to delete record :";
			cin>>d;
			
			Delete(d);
			
		}else if(user=="update"){
			
			string u;
			cout<<"Enter name to update record :";
			cin>>u;
	
			Update(u);
			
		}else if(user=="display"){
		
			Display();
			
		}
		
	
	}while(user!="exit");
	
	
	
	

	

	
	
	return 0;
}


void Add(Contact data){
	
	char check;
	ofstream datafile("datafile.txt");
	
	do{

		cout<<"Enter new record:"<<endl;
		cout<<"-----------------------"<<endl;
	
		cin.ignore();
			
		cout<<"Enter Full Name: ";
		getline(cin,data.name);
		
		cout<<"Enter Address: ";
		getline(cin,data.address);
		
		cout<<"Enter Mobile No: ";
		getline(cin,data.phone);
	
		cout<<"Do you want to enter more record(Y/N):";
    	cin>>check;	
    
    	if(datafile.is_open()){
			datafile<<data.name<<"\t  ";
			datafile<<data.address<<"\t  ";
			datafile<<data.phone<<"\n";
		}
    

	}while(check=='Y' || check=='y');
	
	
}

void Search(string name){
	
	string str;
	ifstream file("datafile.txt");
		
	if(file.is_open()){
			
		while(getline(file,str)){

			if(str.compare(0,4,name,0,4)==0){			//condition will check first 4 character from lines of file
				cout<<str<<'\n';
				break;
			}		
		}				
			
	}	

}


void Delete(string name){
	
	string str;
	ifstream file;
	file.open("datafile.txt"); 
	
	ofstream newfile;
	newfile.open("newdata.txt");			//new file where data will store after deleting
		
	if(file.is_open()){
			
		while(getline(file,str)){

			if(str.compare(0,4,name,0,4)!=0){			//condition will check first 4 character from lines of file if equal than cant go into if body
			
				newfile<<str<<endl;

			}		
		}				
			
	}		
}


void Update(string name){
	
	cout<<"\n\nin update func\n\n";
	string str;
	ifstream file("datafile.txt");
	
	ofstream newfile;
	newfile.open("newdata.txt");
		
	if(file.is_open()){
			
		while(getline(file,str)){

			
			if(str.compare(0,4,name,0,4)==0){				//condition will check first 4 character from lines of file
						
					cout<<"Enter new record:"<<endl;
					cout<<"-----------------------"<<endl;
	
					cin.ignore();
			
					cout<<"Enter Full Name: ";
					getline(cin,data.name);
		
					cout<<"Enter Address: ";
					getline(cin,data.address);
		
					cout<<"Enter Mobile No: ";
					getline(cin,data.phone);
	

				
				
				if(newfile.is_open()){
					
					newfile<<data.name<<"\t  ";
					newfile<<data.address<<"\t  ";
					newfile<<data.phone<<"\n";
				}		
	
			}else{
				newfile<<str<<endl;
			}
			
			
			
	
		}				
			
	}
	
	
	
	
}


 void Display(){
	
    	string str;
	    ifstream file("datafile.txt");
	
	ifstream newfile;
	newfile.open("newfile.txt");
	
	if(file.is_open()){
		
		while(getline(file,str)){
			
			cout<<str<<endl;
		}
	}
}
	
