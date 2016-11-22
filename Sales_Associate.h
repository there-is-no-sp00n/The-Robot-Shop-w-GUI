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
			name = nom;
			id = identity;
		}

	private:
		string name;
		string id;
};


#endif