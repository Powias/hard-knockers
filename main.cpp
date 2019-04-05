/*
This is the so-called Game Of Life. 
Idea is as follows.
You live out each day. Each day has x events you can complete. Work, sleep, exercise, etc.
Everything imposes realistic constraints. Cars break down with specific faults.
You get sick. Certain sicknesses don't get detected by doctors, etc.
Right now, I have begun work on a banking system that I want to get just right before I proceed.
Plans to impose a woman class with private methods in the future.
*/


#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>

class time
{
private:
	int year;
	int day;
	int eventcount;		// every action counts as an "event": i.e. go to work or what not

public:
	// getters
	int getyear() {return year;}
	int getday() {return day;}
	int geteventcount() {return eventcount;}
	// setters
	void setyear(int year) {this->year = year;}
	void setday(int day) {this->day = day;}
	void seteventcount(int eventcount) {this->eventcount = eventcount;}
};

// simple probability functions: returns a "roll" between 0 and 1.
double uniform(double lower = 0.0, double higher = 1.0)
{
	// impose a random seed every single time
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> distribution(lower, higher);
	double roll = distribution(generator);
	return roll;
}

// this one's gaussian but i'm too lazy to look at the documentation yet
double normal(double mean = 0.5, double stddev = 0.1)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
}

// mode of transportation: will extend into cheeky brands that represent ford and toyota and what not
class car
{
private:
	int mileage;
	int age;
	int value;			// blue book value (may be traded for more/less)
	int appeal;			// like GTA's boost: goes down with accidents
	int accidents;		// show me the CARFAX! breaking down in the middle of the road counts.

public:
	car(int mileage, int age, int value, int appeal)
	{
		this->mileage = mileage;
		this->age = age;
		this->value = value;
		this->appeal = appeal;
	}
	~car();

	// getters
	int getmileage() {return mileage;}
	int getage() {return age;}
	int getvalue() {return value;}
	int getappeal() {return appeal;}
	// setters
	void setmileage(int mileage) {this->mileage = mileage;}
	void setage(int age) {this->age = age;}
	void setvalue(int value) {this->value = value;}
	void setappeal(int appeal) {this->appeal = appeal;}
}

// master class (i guess)
// idea is as follows: class bank -> class bankaccount -> class specificaccount
// where you can create a bank object, say WellsFargo and create accounts within it that retain properties of WellsFargo
// reason why I did a general bankaccount class is because a lot of financial accounts
// have the same qualities (i.e. apy, accountnumber, whatever)
class bank
{
private:
	std::string name = {0};
	int routingnum = {0};
	bool overdraftprotect = {0};

public:
	//bank();
	//~bank();

	// getters
	std::string getname() {return name; }
	int getroutingnum() {return routingnum; }
	bool getoverdraftprotect() {return routingnum; }
	// setters
	void setname(std::string name) {this->name = name; }
	void setroutingnum(int routingnum) {this->routingnum = routingnum; }
	void setoverdraft(bool overdraftprotect) {this->overdraftprotect = overdraftprotect; }
	
};


class bankaccount: public bank
{
//friend class bank;

private:
	int accountnum = {0};
	std::string nickname = {0};
	int funds = 0;
	double apy = 0;

public:

	// getters
	int getaccountnum() {return accountnum;}
	std::string getnickname() {return nickname;}
	double getapy() {return apy;}
	// setters
	void setaccountnum(int accountnum) {this->accountnum = accountnum;}
	void setnickname(std::string nickname) {this->nickname = nickname;}
	void setapy(double apy) {this->apy = apy;}

	// methods
	void deposit(unsigned int cash){funds += cash;}
	// this is a spend method for anything involving possibility of overdrafting
	void spend(unsigned int cash, bool overdraftprotect)
	{
		if (!overdraftprotect) {funds -= cash;}
		else {withdraw(cash);}
	}
	// this is a spend method for pulling money out: cash withdrawals block you from negative balance.
	void withdraw(unsigned int cash)
	{
		if (cash >= funds) {funds -= cash;}
		else {std::cout << "You don't have enough money for that.";}
	}
};

class savings : public bankaccount
{

};

class checking : public bankaccount
{

};


int creditscore;

// credit will be a little tricky since
class plastic : public bankaccount //credit card
{
private:
	double apr = 0;
	int creditlimit = {0};

public:
	// getters
	double getapr() {return apr;}
	int getcreditlimit() {return creditlimit;}
	// setters
	void setapr(double apr) {this->apr = apr;}
	void setcreditlimit(int creditlimit) {this->creditlimit = creditlimit;}

};

enum class loantype
{
	CAR,
	MORTGAGE,
	PERSONAL,
	BUSINESS,
	SUBSIDIZED,			// school loans
	UNSUBSIDIZED,
	PRIVATE
};

class loan : public bankaccount
{

};

// don't worry about this
// i wrote this while drinking
void bankinstance(void)
{
	// set bankname randomly
	std::string bankname;
	double roll = uniform();
	if (roll < 0.3)
	{
		bankname = "CITYBANK";
	}
	else if (roll < 0.6)
	{
		bankname = "ALLIESBANK";
	}
	else if (roll < 0.9)
	{
		bankname = "HERITAGEBANK";
	}
	else
	{
		bankname = "CREDIT UNION";
	}

	bankaccount initial;
	bank *BANK = &initial;
	BANK -> setname(bankname);
}



int main(int argc, char** argv)
{
	bank BANK;
	BANK.setname("ALLIESBANK")
	
	/*
	bankaccount a;
	bank *BANK = &a;
	BANK -> setname("wow");
	std::cout << a.getname() << std::endl;
	std::cout << uniform();
	*/

	return 0;
}
