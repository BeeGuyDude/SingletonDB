#include "db.h" 

//Default constructor
Database::Database(std::string db, std::string username, std::string password) {
	this->db = db;
	this->username = username;
	this->password = password;
}

//Singleton instance handling
Database* Database::getInstance(std::string db, std::string username, std::string password) {
	if (instance == nullptr) {
		return new DataBase(db, username, password);
	} else {
		if (db != this->db || username != this->username || this->password != password) {
			throw std::runtime_error("invalid database name, username, or password");
		} else {
			return instance;
		}	
	}
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

//Delete the instance pointer so next getInstance() call will create a new one
void Database::resetInstance() {
	//Delete the instance pointer if it exists so next getInstance() call will create a new one
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

void* Database::operator new(size_t size) {
	void* p_db = std::malloc(size);
	std::cout << " overloaded new ";
	
	//Confirm that the pointer was set properly
	if (!p_db) {
		throw std::bad_alloc();
	}
	//Return once allocated
	return p_db;	
}

void DataBase::operator delete(void* ptr) {
	std::free(ptr);
	std::cout << "overloaded delete ";
}

void Database::set_username(std::string username) {
	this->username = username;
}

std::string Database::get_username() {
	return username;
}

void set_password(std::string password) {
	this->password = password;
}

std::string Database::get_password() {
	return password;
}
