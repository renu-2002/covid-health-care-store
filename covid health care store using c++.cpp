#include <iostream>
#include <string.h>
using namespace std;

int items_stock[] = {1000, 1000, 1000, 1000, 1000};
int price[] = {50, 150, 100, 2000, 200};
int update_stock_number = 1546;
int vaccine_stock_coviShield = 500;
int vaccine_stock_coVaccin = 500;

class Queue
{
    int *arr;
    int size;
    int front, back;

public:
    Queue()
    {
        size = 2;
        front = -1;
        back = -1;
        arr = new int[2];
    }
    void enqueue(int x)
    {
        if (back == size - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        back++;
        arr[back] = x;

        if (front == -1)
            front++;
    }

    void dequeue()
    {
        if (front == -1 || front > back)
        {
            cout << "No element in Queue" << endl;
            return;
        }
        front++;
    }

    int Front()
    {
        if (front == -1 || front > back)
        {
            cout << "No element in Queue" << endl;
            return 0;
        }
        return arr[front];
    }

    bool empty()
    {
        if (front == -1 || front > back)
            return 1;
        else
            return 0;
    }
};
Queue dozes[10000];

class customer
{
    string customer_name;       // Name
    int ID;                     // Bill ID
    long long int phone_number; // Phone Number
    int items[5];               // stores the quantity of each of the items at respective indices alloted for items
    int total_amount;           // Total Amount

    // Set Customer's Name
    void set_name()
    {
        string first_name, last_name;
        cout << "Dear Customer ! Kindly Enter Your First Name : ";
        cin >> first_name;
        cout << "Enter Your Last Name : ";
        cin >> last_name;
        customer_name = first_name + " " + last_name;
    }

    // Set Customer's Phone Number
    void set_phone_number()
    {
        cout << "Please Enter Your Phone Number : ";
        cin >> phone_number;
    }

    // Calculate Total Amount
    void set_total_amount()
    {
        total_amount = 0;
        for (int i = 0; i < 5; i++)
        {
            total_amount += (items[i] * price[i]);
        }
    }

    // Select quantity of each of the items you want to buy
    void items_selection()
    {
        int n, m;
        cout << "0-mask(50 Rs)\n1-sanitizers(150 Rs)\n2-medicines(100 Rs.)\n3-covid suite(2000 Rs)\n4-hand gloves(200 Rs)\n";
        cout << "Enter index number of the item you want to buy!!\nEnter -1 to end this\n";
        cin >> n;
        while (n != -1)
        {
            if (n > 4)
            {
                cout << "Please enter valid index number----> valid index number range is from 0 to 4" << endl;
                cin >> n;
            }
            cout << "Now, enter the quantity you want for this item" << endl;
            cin >> m;
            items[n] = m;
            cout << "Enter index number of the item you want to buy!!\nEnter -1 to end this\n";
            cin >> n;
        }
    }

    // Check Item Stock
    void stock_check()
    {
        char a;
        int s;
        for (int i = 0; i < 5; i++)
        {
            if (items[i] <= items_stock[i])
            {
                items_stock[i] = items_stock[i] - items[i];
                if (items[i] != 0)
                    cout << "Successfully taken from the stock!!" << endl;
            }
            if (items[i] > items_stock[i])
            {
                cout << "Enough stock not available" << endl;

                cout << "Do you still want some items from the available stock? Press 'y' or 'Y' to continue and 'n' or 'N' to end this" << endl;
                cin >> a;
                if (a == 'y' || a == 'Y')
                {
                    cout << "what is the new quantity of this item you want from the available stock now?" << endl;
                    cin >> s;

                    items_stock[i] = items_stock[i] - s;
                }

                if (a == 'n' || a == 'N')
                {
                    s = 0;
                    items_stock[i] = items_stock[i] - s;
                }
            }
        }
    }

    // Print Bill
    void print_bill()
    {
        cout << "\n\n\n";
        cout << "Bill ID : " << ID << endl;
        cout << "Customer Name : " << customer_name << endl;
        cout << "Customer Phone Number : " << phone_number << endl;

        cout << "**ITEMS**\n";
        cout << "Item idx. || Item Name   ||  Amount ||  Price\n";
        cout << "   0      || mask        ||    " << items[0] << "    ||  " << items[0] * price[0] << "\n";
        cout << "   1      || sanitizers  ||    " << items[1] << "    ||  " << items[1] * price[1] << "\n";
        cout << "   2      || medicines   ||    " << items[2] << "    ||  " << items[2] * price[2] << "\n";
        cout << "   3      || covid suite ||    " << items[3] << "    ||  " << items[3] * price[3] << "\n";
        cout << "   4      || hand gloves ||    " << items[4] << "    ||  " << items[4] * price[4] << "\n";
        cout << "Total Amount : " << total_amount << endl;
        cout << "\n\n\n";
    }

public:
    void set_ID(int idx)
    {
        ID = (idx + 11) % 10000;
    }
    void get_data(int idx)
    {
        set_name();
        set_phone_number();
        items_selection();
        stock_check();
        set_total_amount();
        print_bill();
    }
    
};

class vaccine
{
    string name;
    long int phone_number;
    int ID;
    int total_amount;
    int vaccine_type; // 1-(covishield) and 2-(covaccin)

    // Set Customer's Name
    void set_name()
    {
        string first_name, last_name;
        cout << "\nDear Customer ! Kindly Enter Your First Name : ";
        cin >> first_name;
        cout << "Enter Your Second Name : ";
        cin >> last_name;
        name = first_name + " " + last_name;
    }

    // Set Customer's Phone Number
    void set_phone_number()
    {
        cout << "Please Enter Your Phone Number : ";
        cin >> phone_number;
    }

    // Print Bill
    void print_vaccine_receipt()
    {
        string vaccine_name = "";
        if (vaccine_type == 1)
        {
            vaccine_name = "covishield";
        }
        else if (vaccine_type == 2)
        {
            vaccine_name = "covaccin";
        }
        cout << "\n\n\n";
        cout << "Vaccine ID   : " << ID << endl;
        cout << "Name         : " << name << endl;
        cout << "Phone Number : " << phone_number << endl;
        cout << "Vaccine type : " << vaccine_name << endl;
        cout << "Total Amount : " << total_amount << endl;
        cout << "\n\n\n";
        int idx = (ID-17)%10000;
        dozes[idx].dequeue();
    }

    void set_vaccine_type()
    {
        cout << "Enter 1 for covishield(Rs.500) or Enter 2 for covaccin(Rs.500) : ";
        cin >> vaccine_type;
        if (vaccine_type == 1)
        {
            vaccine_stock_coviShield--;
        }
        else if (vaccine_type == 2)
        {
            vaccine_stock_coVaccin--;
        }
    }

    // Stock Check
    bool stock_check()
    {
        if (vaccine_stock_coviShield <= 0 or vaccine_stock_coVaccin <= 0)
        {
            return false;
        }
        return true;
    }

    void set_total_amount()
    {
        if (vaccine_type == 1)
        {
            total_amount = (2 * 500);
        }
        else if (vaccine_type == 2)
        {
            total_amount = (2 * 500);
        }
    }

public:
    void set_ID(int idx)
    {
        ID = (idx + 17) % 10000;
    }
    long int get_phone_number()
    {
        return phone_number;
    }
    void get_data(int idx)
    {
        if (dozes[idx].empty())
        {
            cout << "You have completed all dozes. Stay safe,Stay healthy !!\n";
            return;
        }
        set_name();
        set_phone_number();
        set_vaccine_type();
        if (stock_check())
        {
            set_total_amount();
            print_vaccine_receipt();
            return;
        }
        else
        {
            cout << "No stock\n";
            return;
        }
    }
};

void update_stock()
{
    int tmp;
    cout << "Enter update stock number : ";
    cin >> tmp;

    if (tmp == 1546)
    {
        cout << "Enter amount of covaccin vaccines : ";
        cin >> tmp;
        vaccine_stock_coVaccin += tmp;

        cout << "Enter amount of covishield vaccines : ";
        cin >> tmp;
        vaccine_stock_coviShield += tmp;

        for (int i = 0; i < 5; i++)
        {
            int x = 0;
            cout << "Enter numbers for item of index " << i << ": ";
            cin >> x;
            items_stock[i] += x;
        }
        cout << "** Stock updated **\n\n\n";
    }
    else
    {
        cout << "Wrong Number !!!" << endl;
        return;
    }
}

void second_doze(vaccine X,int vaccine_ID,long int &phone_number)
{
    int idx = (vaccine_ID-17)%10000;
    if(phone_number == X.get_phone_number())
    {
        if(dozes[idx].empty())
        {
            cout << "All dozes are taken.\n\n";
        }
        else if(dozes[idx].Front() != 2)
        {
            cout << "Wrong configuration.Please Enter valid ID.\n\n";
        }
        else
        {
            dozes[idx].dequeue();
            cout << "Dear, You have now taken second doze and till You have completed all dozes. Stay safe,Stay healthy !!\n\n\n";
        }
    }
    else
    {
        cout << "Wrong configuration.Please Enter valid ID. or Phone number.\n\n";
    }
}

struct Node
{
    customer data;
    Node* next;

    Node(customer X)
    {
        data = X;
        next = NULL;
    }
};

class record
{
    Node* last_pointer;
public:
    record()
    {
        last_pointer = NULL;
    }
    void add_entry(customer X)
    {
        Node* n = new Node(X);
        last_pointer = n;
    }
};

int main()
{
    record data;
    vaccine Vaccine[10000];
    int idx_of_customer = 0;
    int idx_of_vaccine = 0;

    for(int i=0; i<10000;i++)
    {
        dozes[i].enqueue(1);
        dozes[i].enqueue(2);
    }

    cout << "\n\nWelcome to Covid Health Store !!\n";
    cout << "** Wear mask, Sanitize yourself and be Safe  **\n\n\n";

    while (1)
    {
        int tmp;
        cout << "1 - Stock Update\n2 - Medicine store\n3 - Vaccine registration program\n4 - close store\n";
        cin >> tmp;

        if (tmp == 4)
        {
            break;
        }
        switch (tmp)
        {
        case 1:
        {
            update_stock();
            break;
        }

        case 2:
        {
            if (idx_of_customer < 10000)
            {
                customer X;
                X.set_ID(idx_of_customer);
                X.get_data(idx_of_customer);
                data.add_entry(X);
                idx_of_customer++;
            }
            break;
        }

        case 3:
        {
            char check;
            cout << "Have you got 1st doze ? ('y' or 'n') : ";
            cin >> check;

            if (check == 'y')
            {
                int vaccine_ID;
                cout << "Enter your vaccine ID : ";
                cin >> vaccine_ID;
                long int phone_number;
                cout << "Enter your phone number : ";
                cin >> phone_number;
                int idx = (vaccine_ID-17)%10000;
                second_doze(Vaccine[idx],vaccine_ID,phone_number);
            }
            else
            {
                if (idx_of_vaccine < 10000)
                {
                    Vaccine[idx_of_vaccine].set_ID(idx_of_vaccine);
                    Vaccine[idx_of_vaccine].get_data(idx_of_vaccine);

                    idx_of_vaccine++;
                }
            }
            break;
        }

        default:
            cout << "Please Enter valid number....\n";
            break;
        }
    }

    return 0;
}