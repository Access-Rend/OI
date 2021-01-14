#include<bits/stdc++.h>
const int MAXN=1e5+10,inf=0x3f3f3f3f>>1;

class Book
{
	private:
		std:: string name;
		int id,row,line;
	public:
		Book(int id,std:: string name,int row,int line) : id(id),name(name),row(row),line(line)	{};
		void inf()
		{
			std:: cout << std:: endl << "Book id: "
			<< id << std:: endl << 
			"Name: " << name << std:: endl << 
			"Posistion: " << row << " row," 
			<< line << " line" << std:: endl;
		}
		
};

class SYS
{
	private:
		int operator_times;
		std:: string admin_pswd;
		bool entered;
		std:: map<int,Book*> books;
		
	public:
		SYS(std:: string s) : admin_pswd(s)	{};
		void Welcome()
		{
			std:: cout << "Welcome to Rend's Library Management System!" <<
			std:: endl << "Please input the key to enter this system." << std:: endl;
			std:: string s;
			std:: cin >> s;
			while(s != admin_pswd)
			{
				std:: cout << "Wrong password, please try again.(or enter the 'e' to exit)" << std:: endl;
				std:: cin >> s;
				if(!s.compare("e") || !s.compare("E"))
					return ;
			}
			entered = true;
		}
		void query();
		void manage();
		void add();
		void work()
		{
			entered = false;
			Welcome();
			if(!entered)	return ;
			
			static int o;
			while(1)
			{
				system("cls");
				std:: cout << "***Library management system***" << std:: endl
				<< "||press 1 to view books" << std:: endl
				<< "||press 2 to manage books" << std:: endl
				<< "||press 3 to add new books" << std:: endl
				<< "||press 4 to exit" << std:: endl;
				std:: cin >> o;
				switch(o)
				{
					case 1: query();	break;
					case 2: manage();	break;
					case 3: add();	break;
					case 4: return ;
				}
			}
		}
}sys("123");
void SYS:: query()
{
	system("cls");
	std:: cout << "***Library management system***" << std:: endl << std:: endl << std:: endl
	<< "*************************" << std:: endl
	<< "****querying books...****" << std:: endl
	<< "*************************" << std:: endl;
	
	static int id,row,line,o;
	while(1)
	{
		std:: cout << "please chose a method to query: " << std:: endl
		<< "1: through ID" << std:: endl
		<< "2: through NAME" << std:: endl;
		std:: cin >> o;
		if(o==1)
		{
			std:: cout << "please input the ID:" << std:: endl;
			std:: cin >> id;
			while(books[id].empty())
			{
				std:: cout << "EOOR: ID not found." << std:: endl;
				std:: cin >> id;
			}
			std:: cout << books[id]->name << books[id]->row << books[id]->line << std:: endl;
		}
		else
		{
			std:: cout << std:: endl << "please input the book's NAME" << std:: endl;
			std:: cin >> name;
			std:: cout << std:: endl << "please input the book's POSITION(row and line) and separate them with SPACE." << std:: endl;
			std:: cin >> row >> line;
			books[id] = new Book(id,name,row,line);
			std:: cout << "operation done. press any key to return."<< std:: endl;//not perfect
			std:: cin >> name; 
			break;
		}
	}
}
void SYS:: manage()
{
	
}

void SYS:: add()
{
	system("cls");
	std:: cout << "***Library management system***" << std:: endl << std:: endl << std:: endl
	<< "***********************" << std:: endl
	<< "****adding books...****" << std:: endl
	<< "***********************" << std:: endl;
	
	static int id,row,line;
	std:: string name;
	while(1)
	{
		std:: cout << "please input the book's ID you want to add: " << std:: endl;
		std:: cin >> id;
		if(books.count(id))
			std:: cout << std:: endl << "ERRO: you can not create this ID because it has been used by another book." << std:: endl;
		else
		{
			std:: cout << std:: endl << "please input the book's NAME" << std:: endl;
			std:: cin >> name;
			std:: cout << std:: endl << "please input the book's POSITION(row and line) and separate them with SPACE." << std:: endl;
			std:: cin >> row >> line;
			books[id] = new Book(id,name,row,line);
			std:: cout << "operation done. press any key to return."<< std:: endl;//not perfect
			std:: cin >> name; 
			break;
		}
	}
}
void solve()
{
	int o=0;
	while(true)
	{
		system("cls");
		std:: cout << "press 1 to enter the system or 2 to exit" << std:: endl;
		std:: cin >> o;
		system("cls");
		if(o==1)
		{
			sys.work();
		}
		if(o==2)
			break;
	}
	
	
}
int main()
{
	solve();
//	freopen("out.txt","w",stdout);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

