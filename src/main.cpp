#include "db.h"

int main() {
	
	Database* db_p = Database::getInstance("TestDB", "username", "password");
	
	delete db_p;
	return 0;
}
