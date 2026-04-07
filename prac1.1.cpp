#include<iostream>
using namespace std;
class bank_account
{
    char acc_holder_name[100];
    double acc_number;
    long double acc_balance;
public:
    void create_account();
    char search_acc(double);
    void depositing_money();
    void withdrawing_money();
    void checking_account_balance();
};
void bank_account::create_account()
{
    cout<<"enter your account number : ";
    cin>>acc_number;
    cout<<"enter your account holder name : ";
    cin>>acc_holder_name;
    cout<<"enter current balance : ";
    cin>>acc_balance;
}
char bank_account::search_acc(double x)
{
    if(acc_number==x)
        return 'v';
    else
        return 'i';
}
void bank_account::depositing_money()
{
    int money;
    cout<<"enter amount you want to deposit : ";
    cin>>money;
    acc_balance+=money;
    cout<<"money deposit successfully."<<endl;
}
void bank_account::withdrawing_money()
{
    int money;
    cout<<"enter amount you want to withdraw : ";
    cin>>money;
    acc_balance-=money;
    cout<<"money withdrawed successfully."<<endl;
}
void bank_account::checking_account_balance()
{
    cout<<endl<<"your balance is : "<<acc_balance<<endl;
}
int main()
{
    bank_account acc[10];
    double acc_number;
    int ch,t=0,i;
    n:
    cout<<endl<<"---bank---"<<endl<<"1. create account"<<endl<<"2. deposit money"<<endl<<"3. withdraw money"<<endl<<"4. check balance"<<endl<<"5. exit"<<endl;
    cout<<"enter your choice : ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        acc[t].create_account();
        t++;
        cout<<"account created successfully"<<endl;
        goto n;

    case 2:
        cout<<"enter your account number : ";
        cin>>acc_number;
        for(i=0;i<t;i++)
        {
            if(acc[i].search_acc(acc_number)=='v')
            {
                acc[i].depositing_money();
                break;
            }
        }
        if(i==t)
        {
            cout<<"account not found"<<endl;
        }
        goto n;

    case 3:
        cout<<"enter your account number : ";
        cin>>acc_number;
        for(i=0;i<t;i++)
        {
            if(acc[i].search_acc(acc_number)=='v')
            {
                acc[i].withdrawing_money();
                break;
            }
        }
        if(i==t)
        {
            cout<<"account not found"<<endl;
        }
        goto n;

    case 4:
        cout<<"enter your account number : ";
        cin>>acc_number;
        for(i=0;i<t;i++)
        {
            if(acc[i].search_acc(acc_number)=='v')
            {
                acc[i].checking_account_balance();
                break;
            }
        }
        if(i==t)
        {
            cout<<"account not found"<<endl;
        }
        goto n;

    case 5:
        return 0;

    default:
        cout<<"enter a valid choice"<<endl;
        goto n;
    }

    return 0;
}

