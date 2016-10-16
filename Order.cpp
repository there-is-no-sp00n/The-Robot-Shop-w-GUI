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
