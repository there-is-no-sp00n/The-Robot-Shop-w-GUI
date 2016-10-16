#include "Order.h"

Order::Order()
{

}

void Order::order_robot(Robot robo)
{
    cout << "Who is the Sales Associate? ";
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

    while (more_robot == 1)
    {
        robo.print_all_models();

        cout << "What is the next type of robot you wish to order? ";
        cin >> user_robot;
        cout << endl;
        orders.type_of_robot.push_back(user_robot);

        cout << "Press 1 to add more robots" << endl;
        cout << "Press 0 to add no more robots" << endl;
        cout << "What is your choice? ";
        cin >> more_robot;
        cout << endl;

        if (more_robot == 0)
        {
            break;
        }
    }

    orders.num_of_robots = orders.type_of_robot.size();
    for (int i = 0; i < orders.num_of_robots; i++)
    {
        get_tot_price(robo.get_retail(robo, orders.type_of_robot[i]));
    }


    order_list.push_back(orders);


}

void Order::get_tot_price(double retail_price)
{
    orders.total_price += retail_price;
}

void Order::view_bill_of_sale()
{
    cout << endl;

    cout << "Date of Sale: " << orders.date_of_sale << endl;
    cout << "Customer Number: " << orders.cust_name << endl;
    cout << "Order Number: " << orders.order_num << endl;
    cout << "# of Robots ordered: " << orders.num_of_robots << endl;
    for (int i = 0; i < orders.num_of_robots; i++)
    {
        cout << "**Robot Model # " << i << ": " << orders.type_of_robot[i] << endl;
    }
    cout << "Total Price: " << orders.total_price << endl;

    cout << endl;
}

void Order::get_sales_report()
{
    cout << "Name of Sales Associate: ";
    string sales_asso;
    getline(cin,sales_asso);
    cout << endl;

    int j = order_list.size();
    for(int i = 0; i < j; i++)
    {
       int sales_by_asso;
       double rev_by_asso;
       int units_by_asso;
       if(sales_asso == order_list[i].sales_person)
       {
           sales_by_asso++;
           rev_by_asso += order_list[i].total_price;
           units_by_asso += order_list[i].num_of_robots;
       }

    }


}
