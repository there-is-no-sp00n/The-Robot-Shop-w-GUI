#ifndef ORDER_H
#define ORDER_H

#include "Robot.h"

class Order
{
    public:
        Order();

        void order_robot(Robot);
        void get_tot_price(double);

        void view_bill_of_sale();

        void get_sales_report();
    protected:
    private:
        struct order_info
        {
            string sales_person;
            string order_num;
            string date_of_sale;
            string cust_name;

            int num_of_robots;
            double total_price;

            vector <int> type_of_robot;
        };

        order_info orders;

        vector <struct order_info> order_list;

};

#endif
