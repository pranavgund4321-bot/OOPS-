#include <iostream>
#include<string>
using namespace std;
class  bank_Account
{
    int balance;
    public:
    bank_Account(int a ){
        balance=a;
        // this is parametriced constructor 
    }
void ShowBalance(){
    cout << "Balance: "<< balance <<endl;
}
};
int main(){
     cout << "--- Bank Account Details ---" << endl;
    bank_Account obj1(500000);
    obj1.ShowBalance();
return 0;
}
