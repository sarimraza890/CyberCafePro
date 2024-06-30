#include <iostream>
#include <string.h>

using namespace std;

int a = 0, npass = 0, checkpass = 0;

class member_entry;

class master_entry
{
public:
	master_entry()
	{
	}
	void display(member_entry mem[], int mn);
	~master_entry()
	{
	}
};
class member_entry : public master_entry
{
public:
	string name, email_id, plan_type;
	string password, phone_no;
	member_entry()
	{
		name = "Admin";
		email_id = "admin1@gmail.com";
		phone_no = " ";
		plan_type = " ";
		password = "admin1";
	}
	void add();
	void show();
	void update();
	void del();
	void check_password();
	void change_password();
	void set_password();
	void display(member_entry mem[], int mn);
	int search(char n[20]);
};
void member_entry::add()
{
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter email id: ";
	cin >> email_id;
	cout << "Enter phone no: ";
	cin >> phone_no;
	cout << "Current plan: ";
	cin >> plan_type;
	cout << "Create password :";
	cin >> password;
}
void member_entry::show()
{
	cout << "Name:" << name << endl;
	cout << "Email id: " << email_id << endl;
	cout << "Phone no: " << phone_no << endl;
	cout << "Current plan: " << plan_type << endl;
}
void master_entry::display(member_entry mem[], int mn)
{
	cout << "\nName\t\tEmail id\t\tPhone no\t\tCurrent plan\n";
	for (int i = 0; i < mn; i++)
	{
		if (mem[i].name != " ")
		{
			cout << mem[i].name << "\t\t" << mem[i].email_id << "\t    " << mem[i].phone_no << "\t\t" << mem[i].plan_type << endl;
		}
	}
}
void member_entry::update()
{
	check_password();
	if (checkpass == 1)
	{
		checkpass = 0;
		int c;
		cout << "\n1.Name\n2.Email id\n3.Phone no\n4.Current plan\n5.Change password\n";
		cout << "Enter your choice (1-5): ";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Enter name:";
			cin >> name;
			break;
		case 2:
			cout << "Enter email id:";
			cin >> email_id;
			break;
		case 3:
			cout << "Enter phone no:";
			cin >> phone_no;
			break;
		case 4:
			cout << "Current plan:";
			cin >> plan_type;
			break;
		case 5:
			change_password();
			break;
		}
	}
}
void member_entry::change_password()
{
	int o, b = 0;
	string e, p;
	while (1)
	{
		int c = 0;
		cout << "Options: \n1)Current password\n2)Forgot password\n3)Return\n ";
		cin >> o;
		switch (o)
		{
		case 1:
			while (1)
			{
				cout << "Enter current password: ";
				cin >> p;
				if (p == password)
				{
					set_password();
				}
				else
				{
					cout << "Incorrect password\n ";
					cout << "For return press 1: ";
					cin >> b;
					if (b == 1)
					{
						b = 0;
						break;
					}
					continue;
				}
				break;
			}
			break;
		case 2:
			while (1)
			{
				int vc = 0;
				cout << "Enter the email id: ";
				cin >> e;
				if (e == email_id)
				{
					while (1)
					{
						cout << "Enter the security code (1100): ";
						cin >> vc;
						if (vc == 1100)
						{
							set_password();
							break;
						}
						else
						{
							cout << "Incorrect code\n";
							cout << "For return press 1: ";
							cin >> b;
							if (b == 1)
							{
								b = 0;
								break;
							}
							continue;
						}
					}
				}
				else
				{
					cout << "Incorrect email id\n";
					cout << "For return press 1: ";
					cin >> b;
					if (b == 1)
					{
						b = 0;
						break;
					}
					continue;
				}
				break;
			}
			break;
		case 3:
			npass = 1;
			break;
		}
		if (npass == 1)
		{
			npass = 0;
			break;
		}
	}
}
void member_entry::set_password()
{
	while (1)
	{
		string pass, c;
		int d = 0;
		cout << "Enter new password: ";
		cin >> pass;
		cout << "Confirm new password: ";
		cin >> c;
		if (pass == c)
		{
			password = pass;
			cout << "Password changed\n";
			npass = 1;
			break;
		}
		else
			cout << "Passwords didnot match\n";
		cout << "For return press 1: ";
		cin >> d;
		if (d == 1)
		{
			d = 0;
			break;
		}
	}
}
int member_entry::search(char n[20])
{
	if (n == name)
		return 1;
	else
		return 0;
}
void member_entry::check_password()
{
	int z = 2;
	string p;
	while (1)
	{
		cout << "Enter the password: ";
		cin >> p;
		if (p == password)
		{
			checkpass = 1;
			break;
		}
		else
		{
			cout << "Passwords didnot match\n";
			cout << "For changing password press 1 or for return press 0: ";
			cin >> z;
			if (z == 0)
				break;
			else if (z == 1)
			{
				change_password();
				z = 2;
			}
			else
				continue;
		}
	}
}
void member_entry::del()
{
	check_password();
	if (checkpass == 1)
	{
		checkpass = 0;
		name = " ";
		email_id = " ";
		plan_type = " ";
		phone_no = " ";
		password = " ";
	}
	else
	{
		cout << "Cancelled" << endl;
	}
}

class computer_entry
{
public:
	string name, model, processor, purchase_date;
	string ram, price;
	computer_entry()
	{
		name = "HP";
		model = "8470";
		processor = "core i5";
		purchase_date = "02-08-23";
		price = "Rs 50000";
	}
	void add();
	void show();
	void del();
	void update();
	int search(char n[20]);
	void display(computer_entry com[], int cn);
};
void computer_entry::display(computer_entry com[], int cn)
{
	cout << "\nComputer name\t\tModel\t\tProcessor\t\tRam\t\tPrice\t\tPurchase date\n";
	for (int i = 0; i < cn; i++)
	{
		if (com[i].name != " ")
		{
			string t = com[i].price;
			cout << "  " << com[i].name << "  \t\t " << com[i].model << "\t\t  " << com[i].processor << "  \t\t  " << com[i].ram << "  \t\t  ";
			cout << t << "  \t\t" << com[i].purchase_date << endl;
		}
	}
}
void computer_entry::add()
{
	cout << "Enter computer name: ";
	cin >> name;
	cout << "Enter model: ";
	cin >> model;
	cout << "Enter processor type: ";
	cin >> processor;
	cout << "Ram: ";
	cin >> ram;
	cout << "Price of computer: ";
	cin >> price;
	cout << "Purchase date of computer: ";
	cin >> purchase_date;
}
void computer_entry::show()
{
	cout << "Computer name: " << name << endl;
	cout << "Model: " << model << endl;
	cout << "Enter processor type: " << processor << endl;
	cout << "Ram: " << ram << endl;
	cout << "Price of computer: " << price << endl;
	cout << "Purchase date of computer: " << purchase_date << endl;
}
void computer_entry::update()
{
	cout << "Enter computer name: ";
	cin >> name;
	cout << "Enter model: ";
	cin >> model;
	cout << "Enter processor type: ";
	cin >> processor;
	cout << "Ram: ";
	cin >> ram;
	cout << "Price of computer: ";
	cin >> price;
	cout << "Purchase date of computer: ";
	cin >> purchase_date;
}
int computer_entry::search(char n[20])
{
	if (n == name)
		return 1;
	else
		return 0;
}
void computer_entry::del()
{
	name = " ";
	model = " ";
	processor = " ";
	purchase_date = " ";
	price = " ";
	ram = " ";
}

class cyber_cafe
{
public:
	string name, time, phone_no, age;
	bool ifpremium, added = 0; // new_member_added
	void booking(member_entry *, int mn);
	void show_charges();
	void pay_charges();
	void renew(member_entry *, int mn);
};
void cyber_cafe::show_charges()
{
	cout << "\nCharges for an hour: Rs 100\n"
		 << endl;
	cout << "Plans:\n";
	cout << "1)Basic plan (1 month): Rs 10000\n";
	cout << "2)Standard plan (3 months): Rs 25000\n";
	cout << "3)Premium (1 year): Rs Rs 80000\n";
}
void cyber_cafe::booking(member_entry mem[], int mn)
{
	int i = 0, x = 0, ans;
	while (1)
	{
		cout << "press 1 if you are already a member or else press 0:";
		cin >> ifpremium;
		if (ifpremium)
		{
			int c = 0;
			while (c != 2)
			{
				int i, x = 0;
				string n, p;
				cout << "1.Login\n2.Return" << endl;
				cin >> c;
				switch (c)
				{
				case 1:
					cout << "Enter name: ";
					cin >> n;
					cout << "Enter password: ";
					cin >> p;
					for (i = 0; i < mn; i++)
					{
						if (n == mem[i].name && p == mem[i].password)
						{
							cout << "Loggedin" << endl;
							x = 1;
							break;
						}
					}
					if (x == 0)
					{
						cout << "Enter details:" << endl;
						continue;
					}
					break;
				case 2:
					break;
				}
				c = 0;
				break;
			}
		}
		else
		{
			show_charges();
			cout << "if you want to use computer press 1 (charges will apply)\n";
			cin >> ans;
			if (ans == 1)
			{
				cout << "use login credentials as username:Admin, password:admin1\n";
				continue;
			}
		}
		break;
	}
}
void cyber_cafe::renew(member_entry mem[], int mn)
{
	int sp, cp, pm, i = 0, x = 0;
	char m_n[20];
	show_charges();
	cout << "press 1 if you are previously a member";
	cin >> pm;
	cout << "1)Basic\n";
	cout << "2)Standard\n";
	cout << "3)Premium\n";
	cout << "Select a plan: ";
	cin >> sp;
	cout << "For confirmation of payment press 1: ";
	cin >> cp;
	if (cp == 1 && pm == 0)
	{
		cout << "To activate the plan, create an account by entering the details";
		for (i = 0; i < mn; i++)
		{
			if (mem[i].name == " ")
			{
				mem[i].add();
				x = 1;
				break;
			}
		}
		if (x == 0)
		{
			mem[mn].add();
			added = 1;
			mn++;
		}
		x = 0;
	}
	else if (cp == 1 && pm == 1)
	{
		cout << "To activate the plan, update the plan\n ";
		cout << "Enter name :";
		cin >> m_n;
		for (i = 0; i < mn; i++)
		{
			if (mem[i].search(m_n))
			{
				cout << "Member name found\n ";
				x = 1;
				mem[i].update();
				break;
			}
		}
		if (x == 0)
			cout << "Member name not found\n";
		x = 0;
	}
}

int main()
{
	master_entry me;
	member_entry mem[20];
	computer_entry com[20];
	cyber_cafe c;
	int p, o, a, i, j, k;
	int mn = 2, cn = 0, x = 0;
	char m_n[20], c_n[20]; // member name, computer name
	int m = 1, m1 = 1, m2 = 1, cc = 1, c1 = 1, c2 = 1;
	int password = 1191;
	mem[1].name = "Admin";
	mem[1].password = "admin1";
	cout << "\n---------------------------\n";
	cout << "  ____      ____     ____  " << endl;
	cout << " / ___|    / ___|   |  __ \\ " << endl;
	cout << "| |       | |       | |__) |" << endl;
	cout << "| |       | |       |  ___/ " << endl;
	cout << "| |____   | |____   | |     " << endl;
	cout << " \\____|    \\____|   |_|     " << endl;
	cout << "                             " << endl;
	cout << " Cyber\t   Cafe\t   Pro\n";
	cout << "\n---------------------------\n";

	cout << "\nEnter the password: ";
	cin >> p;
	while (1)
	{
		if (p == password)
		{
			break;
		}
		else
		{
			cout << "Incorrect password" << endl;
			cout << "Enter the password: ";
			cin >> p;
		}
	}

	while (1)
	{
		cout << "\n1) Master Entry\n2) Management\n3) Exit\n";
		cout << "Enter your choice (1-3): ";
		cin >> o;
		switch (o)
		{
		case 1:
		{
			while (m != 3)
			{
				cout << "\n1)Member entry\n2)Computer entry\n3)Return\n";
				cin >> m;
				switch (m)
				{
				case 1:
				{
					while (m1 != 6)
					{
						cout << "\n1)Add\n2)Show\n3)Update\n4)Delete\n5)Search\n6)Return\n";
						cout << "Enter your choice (1-6): ";
						cin >> m1;
						switch (m1)
						{
						case 1:
							for (i = 0; i < mn; i++)
							{
								if (mem[i].name == " ")
								{
									mem[i].add();
									x = 1;
									break;
								}
							}
							if (x == 0)
							{
								mem[mn].add();
								mn++;
							}
							x = 0;
							break;
						case 2:
							me.display(mem, mn);
							break;
						case 3:
							cout << "Enter the name of member:";
							cin >> m_n;
							for (i = 0; i < mn; i++)
							{
								if (mem[i].search(m_n))
								{
									cout << "Member name found\n ";
									x = 1;
									mem[i].update();
									break;
								}
							}
							if (x == 0)
								cout << "Member name not found\n";
							x = 0;
							break;
						case 4:
							cout << "Enter the name of member:";
							cin >> m_n;
							for (i = 2; i < mn; i++)
							{
								if (mem[i].search(m_n))
								{
									cout << "Member name found\n ";
									x = 1;
									mem[i].del();
									cout << "Member deleted\n";
									break;
								}
							}
							if (x == 0)
								cout << "Member name not found\n";
							x = 0;
							break;
						case 5:
							cout << "Enter the name of member:";
							cin >> m_n;
							for (i = 0; i < mn; i++)
							{
								if (mem[i].search(m_n))
								{
									cout << "Member name found\n";
									mem[i].show();
									x = 1;
									break;
								}
							}
							if (x == 0)
								cout << "Member name not found\n";
							x = 0;
							break;
						case 6:
							break;
						}
					}
					m1 = 0;
					break;
				}

				case 2:
				{
					while (m2 != 6)
					{
						cout << "\n1)Add\n2)Show\n3)Update\n4)Delete\n5)Search\n6)Return\n";
						cout << "Enter your choice (1-6): ";
						cin >> m2;
						switch (m2)
						{
						case 1:
							com[cn].add();
							cn++;
							break;
						case 2:
							com[0].display(com, cn);
							break;
						case 3:
							cout << "Enter the name of computer:";
							cin >> c_n;
							for (i = 0; i < cn; i++)
							{
								if (com[i].search(c_n))
								{
									cout << "Computer name found\n ";
									x = 1;
									com[i].update();
									break;
								}
							}
							if (x == 0)
								cout << "Computer name not found\n";
							x = 0;
							break;
						case 4:
							cout << "Enter the name of computer:";
							cin >> c_n;
							for (i = 0; i < cn; i++)
							{
								if (com[i].search(c_n))
								{
									cout << "Computer name found\n ";
									x = 1;
									com[i].del();
									cout << "Computer deleted\n";
									break;
								}
							}
							if (x == 0)
								cout << "Computer name not found\n";
							x = 0;
							break;
						case 5:
							cout << "Enter the name of computer:";
							cin >> c_n;
							for (i = 0; i < cn; i++)
							{
								if (com[i].search(c_n))
								{
									cout << "Computer name found\n";
									com[i].show();
									x = 1;
									break;
								}
							}
							if (x == 0)
								cout << "Computer name not found\n";
							x = 0;
							break;
						case 6:
							break;
						}
					}
					m2 = 0;
					break;
				}
				case 3:
					break;
				}
			}
			m = 0;
			break;
		}

		case 2:
		{
			while (cc != 4)
			{
				cout << "\n1)Booking\n2)Charges\n3)Renewal\n4)Return\n";
				cout << "Enter your choice (1-4): ";
				cin >> cc;
				switch (cc)
				{
				case 1:
				{
					while (c1 != 3)
					{
						cout << "\n1)Login\n2)Logout\n3)Return\n";
						cout << "Enter your choice (1-3): ";
						cin >> c1;
						switch (c1)
						{
						case 1:
							c.booking(mem, mn);
							break;
						case 2:
							cout << "Loggedout" << endl;
							break;
						case 3:
							break;
						}
					}
					c1 = 0;
					break;
				}
				case 2:
					c.show_charges();
					break;
				case 3:
					c.renew(mem, mn);
					if (c.added == 1)
					{
						c.added = 0;
						mn++;
					}
					break;
				case 4:
					break;
				}
			}
			cc = 0;
			break;
		}

		case 3:
			exit(0);
		}
	}
	return 0;
}
