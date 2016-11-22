#ifndef SALES_ASSOCIATE_H
#define SALES_ASSOCIATE_H

#include <iostream>

using namespace std;

class Sales_Associate
{
	public:
		Sales_Associate();

		Sales_Associate(string nom, string identity)
		{
			name_7 = nom;
			id_9 = identity;
		}

		string get_sa_name()
		{
			return name_7;
		}

		string get_sa_id()
		{
			return id_9;
		}



	private:
		string name_7;
		string id_9;
};


#endif