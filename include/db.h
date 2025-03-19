#pragma once
#include <string>

class Database {
     //member variable "db" is of string type
	std::string db;
	std::string username;
	std::string password;

	bool connected = false;
     
	static Database* instance = nullptr;
	
   	//Public constructor and destructor
	Database(std::string db, std::string username, std::string password);	
   	~Database();	

	//General instance handling
	Database getInstance();	
    
	//"getInstance" that creates and returns the instance of the database (Database*). 
	//If called first time it sets the username and password. 
	//However, subsequent time, it matches the database name, 
	//		username and password and returns the previous instance if matched 
	//		else it throws std::runtime_error("invalid database name, username or password"). 
	//We are using Singleton Design Pattern that creates only one instance of the databse. 
	//The instance is still created by the constructor.
 
	void connect();
	void disconnect();
	bool connected();
 
     //overload the new operator that allocates memory using malloc of given size and returns pointer of type void and prints " overloaded new " (cout is okay in this case). std::cout << "overloaded new ";
     //If the memory allocation fails it should throw std::bad_alloc()
    void* operator new(size_t size);
 
     //overload the delete operator that deallocates memory and prints "overloaded delete " (cout is okay in this). std::cout << "overloaded delete ";
    void* operator delete();
 
    //set_username and get_username for username
	void set_username(std::string username);
   	std::string get_username();
	
    //set_password and get_password for password.
    void set_password(std::string password);
	std::string get_password();

	//The static "resetInstance" as defined below.
	static void resetInstance();
 };


