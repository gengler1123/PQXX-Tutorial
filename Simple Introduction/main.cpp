#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include <vector>


using namespace pqxx;
using namespace std;


int main()
{
	try{
		connection C("dbname=adg user=adg_user password=adg123 hostaddr=155.246.103.74 port=5432");
		if (C.is_open())
		{
			cout << "Database " << C.dbname() << " opened." << endl;
		}
		else
		{
			cout << "Cannot Open Database." << endl;
			return 1;
		}
		int NAME;
		cout << "Enter Integer ID: ";
		cin  >> NAME;
		cout << endl;
		double VALUE;
		cout << "Enter Double Value: ";
		cin  >> VALUE;
		
		string QUERY;
		
		QUERY = "INSERT INTO cpptest VALUES (" + to_string(NAME) + "," + to_string(VALUE) ");";
		
		work W(C);
		
		W.exec(QUERY);
		W.commit();
		C.disconnect();
	}
	catch(const exception &e)
	{
		cerr << e.what();
		return 1;
	}
	
	return 0;
}