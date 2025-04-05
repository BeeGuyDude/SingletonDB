#include "db.h"

int main() {
	
	Database* db_p = Database::getInstance("TestDB", "username", "password");

	return 0;
}
