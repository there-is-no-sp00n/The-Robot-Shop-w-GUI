#include "Order.h"

Order::Order()
{

}

void Order::order_robot(Robot robo)
{
    cout << "$$$ ORDER MENU $$$" << endl;
    cout << endl;

    cout << "Who is the Sales Associate? ";
    cin.ignore();
    getline(cin, orders.sales_person);
    cout << endl;

    cout << "What is the order number? ";
    cin >> orders.order_num;
    cout << endl;

    cout << "What is the date of sale(MM/DD/YYYY)? ";
    cin >> orders.date_of_sale;
    cout << endl;

    cout << "What is the name of the customer? ";
    cin.ignore();
    getline(cin, orders.cust_name);
    cout << endl;


    robo.print_all_models();

    cout << "What type of robot do you wish to order? ";
    int user_robot;
    cin >> user_robot;
    cout << endl;
    orders.type_of_robot.push_back(user_robot);

    cout << "Press 1 to add more robots" << endl;
    cout << "Press 0 to add no more robots" << endl;
    cout << "What is your choice? ";
    int more_robot;
    cin >> more_robot;
    cout << endl;
    int counter = 1;

    while (more_robot == 1)
    {
        robo.print_all_models();

        cout << "What is the next type of robot you wish to order? ";
        cin >> user_robot;
        cout << endl;
        orders.type_of_robot.push_back(user_robot);
        counter++;

        cout << "Press 1 to add more robots" << endl;
        cout << "Press 0 to add no more robots" << endl;
        cout << "What is your choice? ";
        cin >> more_robot;
        cout << endl;

        //if (more_robot == 0)
        //{
        //    break;
        //}
    }

    orders.num_of_robots = counter;
    for (int i = 0; i < counter; i++)
    {
        orders.total_price += get_tot_price(robo.get_retail(robo, orders.type_of_robot[i]));
        get_tot_weight(robo.get_weight(robo, orders.type_of_robot[i]));
    }


    order_list.push_back(orders);
    orders.total_price = 0;
    orders.total_weight = 0;



}

double Order::get_tot_price(double retail_price)
{
    return retail_price;
}

void Order::get_tot_weight(double weight)
{
    orders.total_weight += weight;
}

void Order::view_order_by_sa()
{
    cout << "$$$ ORDER BY SALES ASSOCIATE MENU $$$" << endl;
    cout << endl;
    cout << "Name of Sales Associate: ";
    string sales_asso;
    cin.ignore();
    getline(cin,sales_asso);
    cout << endl;

	int j = order_list.size();
	for (int i = 0; i < j; i++)
	{
		if (sales_asso.compare(order_list[i].sales_person) == 0)
		{
			cout << endl;
            cout << "Sales Associate: " << order_list[i].sales_person << endl;

            cout << "Date of Sale: " << order_list[i].date_of_sale << endl;
            cout << "Customer Name: " << order_list[i].cust_name << endl;
            cout << "Order Number: " << order_list[i].order_num << endl;
            cout << "# of Robots ordered: " << order_list[i].num_of_robots << endl;

            double tax = 0.0825*order_list[i].total_price;
            double shipping = 5*order_list[i].total_weight;
            cout << "Subtotal: " << order_list[i].total_price << endl;
            cout << "Tax: " << tax << endl;
            cout << "Shipping @ $5 per KG: " << shipping << endl;
            cout << "Total: " << order_list[i].total_price + tax + shipping << endl;

            cout << endl;
		}

	}

	

    

}

void Order::view_all_orders()
{
    cout << "$$$ ALL ORDERS $$$" << endl;
    cout << endl;
    int j = order_list.size();
    for (int i = 0; i < j; i++)
    {
        cout << endl;
        cout << "Sales Associate: " << order_list[i].sales_person << endl;

        cout << "Date of Sale: " << order_list[i].date_of_sale << endl;
        cout << "Customer Name: " << order_list[i].cust_name << endl;
        cout << "Order Number: " << order_list[i].order_num << endl;
        cout << "# of Robots ordered: " << order_list[i].num_of_robots << endl;

        double tax = 0.0825*order_list[i].total_price;
        double shipping = 5*order_list[i].total_weight;
        cout << "Subtotal: " << order_list[i].total_price << endl;
        cout << "Tax: " << tax << endl;
        cout << "Shipping @ $5 per KG: " << shipping << endl;
        cout << "Total: " << order_list[i].total_price + tax + shipping << endl;

        cout << endl;

    }
}


void Order::view_bill_of_sale(Robot robo)
{
    cout << "$$$ CUSTOMER BILL OF SALE MENU $$$" << endl;
    cout << endl;
    cout << "What is the customer's name? ";
    cin.ignore();
    string cust_name;
    getline(cin, cust_name);

    int j = order_list.size();
    for(int i = 0; i < j; i++)
    {
		if (cust_name.compare(order_list[i].cust_name) == 0)
        {
            cout << endl;

            cout << "Sales Associate: " << order_list[i].sales_person << endl;
            cout << "Date of Sale: " << order_list[i].date_of_sale << endl;
            cout << "Order Number: " << order_list[i].order_num << endl;
            cout << "# of Robots ordered: " << order_list[i].num_of_robots << endl;

            double tax = 0.0825*order_list[i].total_price;
            double shipping = 5*order_list[i].total_weight;
            cout << "Subtotal: " << order_list[i].total_price << endl;
            cout << "Tax: " << tax << endl;
            cout << "Shipping @ $5 per KG: " << shipping << endl;
            cout << "Total: " << order_list[i].total_price + tax + shipping << endl;

            cout << endl;
        }
    }

}

void Order::get_sales_report()
{
    cout << "$$$ SALES REPORT MENU $$$" << endl;
    cout << endl;
    cout << "Name of Sales Associate: ";
    string sales_asso;
    cin.ignore();
    getline(cin,sales_asso);
    cout << endl;
    

    int sales_by_asso = 0;
    double rev_by_asso = 0;
    int units_by_asso = 0;

    int j = order_list.size();
    for(int i = 0; i < j; i++)
    {
		if (sales_asso.compare(order_list[i].sales_person) == 0)
       {
           sales_by_asso++;
           rev_by_asso += order_list[i].total_price;
           units_by_asso += order_list[i].num_of_robots;
       }


    }

    cout << "Number of Sales: " << sales_by_asso << endl;
    cout << "Units Sold: " << units_by_asso << endl;
    cout << "Total Sales: $" << rev_by_asso << endl;


}


