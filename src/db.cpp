#include "db.h" 

void* Database::operator new(size_t size) {
	void* p_db = std::malloc(size);
	std::cout << "overloaded new ";
	
	//Confirm that the pointer was set properly
	if (!p_db) {
		throw std::bad_alloc();
	}
	//Return once allocated
	return p_db;	
}

void Database::operator delete(void* ptr) {
	std::cout << "overloaded delete ";
	std::free(ptr);
}


//Default constructor
Database::Database(std::string db, std::string username, std::string password) {
	this->db = db;
	this->username = username;
	this->password = password;
}

//Singleton instance handling
Database* Database::instance = nullptr;
Database* Database::getInstance(std::string db, std::string username, std::string password) {
	if (instance == nullptr) {
		instance = new Database(db, username, password);
		return instance;
	} else {
		if (db != instance->db || 
			username != instance->username || 
			password != instance->password) {
			throw std::runtime_error("invalid database name, username, or password");
		} else {
			return instance;
		}	
	}
}

//Custom destructor to ensure memory is deallocated
Database::~Database() {
	//resetInstance();
}

//Copy constructor, overridden to not allow access
Database::Database(const Database& copy_db) {
	throw std::runtime_error("Copy construction not allowed by singleton pattern!");
}

//Copy assignment operator, overridden to not allow access
Database& Database::operator=(const Database& copy_db) {
	throw std::runtime_error("Copy assignment not allowed by singleton pattern!");
}

//Move constructor, overridden to not allow access
Database::Database(Database&& move_db) {
	throw std::runtime_error("Move construction not allowed by singleton pattern!");
}

//Move assignment operator, overridden to not allow access
Database& Database::operator=(Database&& move_db) {
	throw std::runtime_error("Move assignment not allowed by singleton pattern!");
}

//Connect the database
void Database::connect() {
	connected = true;
}

//Disconnect the database
void Database::disconnect() {
	connected = false;
}

//Return the status of whether the database is currently connected
bool Database::isConnected() {
	return connected;
}

//Return the status of whether the connection is beyond the timeout threshold
bool Database::isTimeout() {
	return (std::time(0) > last_activity + TIMEOUT);
}

//Refresh the timeout timer to avoid watchdog timeout
void Database::refreshConnection() {
	last_activity = std::time(0);
}

//Delete the instance pointer so next getInstance() call will create a new one
void Database::resetInstance() {
	//Delete the instance pointer if it exists so next getInstance() call will create a new one
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

void Database::set_username(std::string username) {
	this->username = username;
}

std::string Database::get_username() {
	return username;
}

void Database::set_password(std::string password) {
	this->password = password;
}

std::string Database::get_password() {
	return password;
}
