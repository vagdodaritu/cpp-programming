#include<iostream>
#include<string>
using namespace std;
class account{

private:
int accounum;
string name;
float balance;
public:
static int totalnum;

account(int ac=0,string n="",float bal=0){

accounum=ac;
name=n;
balance=bal;
totalnum++;

}
void input(){
cout<<"enter account num";
cin>>accounum;
cout<<"enter name";
cin>>name;
cout<<"enter balance";
cin>>balance;



}
void display(){
cout<<"accounum"<<":"<<accounum<<endl;
cout<<"name"<<":"<<name<<endl;
cout<<"balance"<<":"<<balance<<endl;



}
int getaccount(){
return accounum;}

float getbalance(){
return balance;}

void deposite(float amount){
balance+=amount;}
bool withdraw(float amount){
if(amount>balance){
return false;}
else{
balance-=amount;
return true;}}
void transfer(account &receiver, float amount) {
        if(withdraw(amount)) {
            receiver.deposite(amount);
            cout << "transfer successful!\n";
        } else {
            cout << "transfer failed!\n";
        }
    }
};

int account::totalnum=0;
int main(){
int n;
cout<<"enter num"<<endl;
cin>>n;
 account* acc = new account[n];
for(int i = 0; i < n; i++) {
        cout << "\n--- account " << i+1 << " ---";
        acc[i].input();
    }
    int from, to;
    float amount;

cout << "\nEnter sender account number: ";
    cin >> from;
    cout << "Enter receiver account number: ";
    cin >> to;
    cout << "Enter amount to transfer: ";
    cin >> amount;

    account *sender = NULL, *receiver = NULL;

    for(int i = 0; i < n; i++) {
        if(acc[i].getaccount() == from)
            sender = &acc[i];
        if(acc[i].getaccount() == to)
            receiver = &acc[i];
    }

    if(sender && receiver) {
        sender->transfer(*receiver, amount);
    } else {
        cout << "invalid account number!\n";
    }

    cout << "\n--- account details ---";
    for(int i = 0; i < n; i++) {
        acc[i].display();
    }

    cout << "\ntotal accounts: " << account::totalnum;

    delete[] acc;

    return 0;







}
