#include <bits/stdc++.h>
using namespace std;
class Bankaccount
{
private:
	int Accnumber;
	string name;
	double balance;
public:
	Bankaccount(string n,int Acc,double bal)
	{
		name=n;
		Accnumber=Acc;
		balance=bal;
	}
	string getname()
	{
		return name;
	}
	int getAccnumber()
	{
		return Accnumber;
	}
	double getbalance()
	{
		return balance;
	}
	void deposit(double deposit)
	{
		balance= balance+deposit;
	}
	void withdraw( double withdraw)
	{
		if(balance>withdraw) {
			balance= balance-withdraw;
			cout<<"\t\t--Withdraw successfully--";
		}
		else {
			cout<<"\t\t--Insufficient balance--";
		}
	}

};
class Bankmanagement
{
private:
	vector<Bankaccount> accounts;
public:
	void addaccount(string name,int Accnumber,double balance)
	{
		accounts.push_back(Bankaccount(name,Accnumber,balance));
	}
	void Showallacc()
	{
		cout<<"\t\tAll accounts:"<<endl;
		for(int i=0; i<accounts.size(); i++)
		{
			cout<<"\t\tName:"<<accounts[i].getname()<<endl;
			cout<<"\t\tAccount number"<<accounts[i].getAccnumber()<<endl;
			cout<<"\t\tAccount balance"<<accounts[i].getbalance()<<endl;
			cout<<"\t--------------------------------";
		}
	}
	void SearchACC(int accountnum)
	{
		cout<<"\t\tAccount Holder"<<endl;
		for(int i=0; i<accounts.size(); i++)
		{
			if(accounts[i].getAccnumber()==accountnum)
			{
				cout<<"\t\tName:"<<accounts[i].getname()<<endl;
				cout<<"\t\tAccount number"<<accounts[i].getAccnumber()<<endl;
				cout<<"\t\tAccount balance"<<accounts[i].getbalance()<<endl;
			}
			else {
				cout<<"\t\t--No account number available--";
			}
		}
	}
	Bankaccount* findaccount(int Acc)
	{
		for(int i=0; i<accounts.size(); i++)
		{
			if(accounts[i].getAccnumber()==Acc)
			{
				return &accounts[i];
			}

		}
	}

};
int main()
{
	Bankmanagement bank;
	int choice;
	char option;
	do {
		system("clear");
		cout<<"\t\t::BANK MANAGEMENT SYSTEM::"<<endl;
		cout<<"\t\t\tMAIN MENU"<<endl;
		cout<<"\t\t\t 1.Create account"<<endl;
		cout<<"\t\t\t 2.Show all account"<<endl;
		cout<<"\t\t\t 3.Search account"<<endl;
		cout<<"\t\t\t 4.Deposit money"<<endl;
		cout<<"\t\t\t 5.Withdrawal money"<<endl;
		cout<<"\t\t\t 6.Exit"<<endl;
		cout<<"\t\t---------------------------------"<<endl;
		cout<<"\t\tEnter your choice :";
		cin>>choice;

		switch(choice)
		{
		case 1: {
			string name;
			int Accnumber;
			double balance;
			cout<<"\tEnter Name:";
			cin>>name;
			cout<<"\tEnter account number:";
			cin>>Accnumber;
			cout<<"\tEnter initial deposit:";
			cin>>balance;
			bank.addaccount(name,Accnumber,balance);
			cout<<"\t\tAccount created successfully..........."<<endl;
			break;
		}

		case 2: {
			bank.Showallacc();
			break;
		}

		case 3: {
			int Accnumber;
			cout<<"\t\tEnter account number:";
			cin>>Accnumber;
			bank.SearchACC(Accnumber);
		}
		case 4: {
			double dep;
			int acc;
			cout<<"\t\tAccount number to deposit:";
			cin>>acc;
			Bankaccount* account=bank.findaccount(acc);
			if (account!=NULL)
			{	cout<<"\t\tEnter the amount to deposit:";
				cin>>dep;
				account->deposit(dep);
				cout<<"\t\tAmount deposited successfully---";
			}
			else {
				cout<<"\t\tAccount not found--"<<endl;

			}
			break;
		}
		case 5:
		{
			double Withdrawal;
			int acc;
			cout<<"\t\tAccount number to Withdraw:";
			cin>>acc;
			Bankaccount* account=bank.findaccount(acc);
			if (account!=NULL)
			{	cout<<"\t\tEnter the amount to Withdraw:";
				cin>>Withdrawal;
				account->withdraw(Withdrawal);
				cout<<"\t\tAmount Withdrawal successfully---";
			}
			else {
				cout<<"\t\tAccount not found--"<<endl;

			}
			break;
		}
		case 6:
		{

			cout << "\t\tThank you for using the Bank Management System!" << endl;
			cout << "\t\tHave a great day!" << endl;
			return 0;
			break;
		}

		}
		cout<<endl;
		cout<<"\t\tWhether to continue or exit[Yes(Y) or No(N)]?";
		cin>>option;
	} while(option=='Y' || option=='y');

}


