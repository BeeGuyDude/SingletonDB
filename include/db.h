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
	
	
  public:	
   	
	//Public constructor and destructor
	Database(std::string db, std::string username, std::string password);	
   	~Database();

	//Copy constructor, Copy assignment, Move constructor, Move assignment
	Database(const Database& copy_db);
	Database& operator=(const Database& copy_db);	
	Database(Database&& move_db);
	Database& operator=(Database&& move_db);
	
	//General instance handling
	static Database* getInstance(std::string db, std::string username, std::string password);	
    
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


