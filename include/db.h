#pragma once
#include <string>
#include <exception>
#include <iostream>
#include <ctime>

class Database {
  private: 
   	//member variable "db" is of string type
	std::string db;
	std::string username;
	std::string password;

	bool connected = false;
     
	static Database* instance;

	time_t last_activity;
	static const int TIMEOUT{5};
	
	//Public constructor and destructor
	Database(std::string db, std::string username, std::string password);	
   	~Database();	

  public:	
   	
	//General instance handling
	Database* getInstance(std::string db, std::string username, std::string password);	
    
	//Standard methods for dealing with connection status
	void connect();
	void disconnect();
	bool isConnected();
	
	//Time-based connection handling
	bool isTimeout();
	void refreshConnection();
	
	//Custom overloaded memory handling	
    void* operator new(size_t size);
    void operator delete(void* ptr);
 
    //set_username and get_username for username
	void set_username(std::string username);
   	std::string get_username();
	
    //set_password and get_password for password.
    void set_password(std::string password);
	std::string get_password();

	//The static "resetInstance" as defined below.
	static void resetInstance();
 };


