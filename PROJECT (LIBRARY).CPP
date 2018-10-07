#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>


//***************************************************************
//    	       CLASS BOOKS
//***************************************************************


class books
{ char nameauthor[80];
  int totalbooks;
  int issuedbooks;
  long bookcode;
  int availablebooks;
  char namebook[100];


public:


  void enterbookdetails()
  {
    cout<<"\nEnter the name of the book:";
    gets(namebook);
    cout<<"Enter the name of the author:";
    gets(nameauthor);
    cout<<"Enter book code:";
    cin>>bookcode;
    cout<<"Enter total number of the books purchased:";
    cin>>totalbooks;
    availablebooks=totalbooks;
    issuedbooks=0;
  }


  void showbookdetails()
  {
    cout<<"\nBOOK NAME: ";
    puts(namebook);
    cout<<"AUTHOR: ";
    puts(nameauthor);
    cout<<"NUMBER OF BOOKS AVAILABLE: "<<availablebooks;
    cout<<"\nNUMBER OF BOOKS ISSUED: "<<issuedbooks;
    cout<<"\n\n";
  }


  int checkbookdetails(char n[])
  {
    if(!strcmpi(n,namebook))
    {
      return 1;
    }

    else
    {
      return 0;
    }
  }


  int returnavailablebooks()
  {
    return availablebooks;
  }


  void issuebook()
  {
    availablebooks--;
    issuedbooks++;
  }


  void returnbook()
  {
    issuedbooks--;
    availablebooks++;

  }


};


//***************************************************************
//    	       CLASS MEMBERS
//***************************************************************


class members
{
  int iday;
  int imonth;
  int iyear;
  int rday;
  int rmonth;
  int ryear;
  int tday;
  int tmonth;
  int tyear;
  int fine;
  char namemember[80];
  long membercode;
  char ch;


  public:
  char nameofbook[80];


  members()
  {
    iday=imonth=iyear=rday=rmonth=ryear=tday=tmonth=tyear=fine=membercode=membercode=0;
    strcpy(namemember,"NEW MEMBER");
    strcpy(nameofbook,"NO BOOK IS ISSUED");
  }


  void returnb()
  {
    cout<<"\nEnter today's date(dd/mm/yyyy): ";
    cin>>tday>>ch>>tmonth>>ch>>tyear;
    calculatefine();
    cout<<"FINE: "<<fine;
    rday=rmonth=ryear=fine=0;

  }


  void dateofreturn()
  {

    rday=iday;
    rmonth=imonth;
    ryear=iyear;

    switch(imonth)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10: rday=rday+14;
	     if(rday>31)
	       {
		rday=rday-31;
		rmonth++;
	       }
	     break;
    case 12: rday=rday+14;
	     if(rday>31)
	       {
		rday=rday-31;
		rmonth=1;
		ryear++;
	       }
	     break;


    case 2:rday=rday+14;
	   if(ryear%4==0)
	     {
	       if(rday>29)
		 {
		   rday=rday-29;
		   rmonth++;
		 }
	      }
	   else
	     {
	       if(rday>28)
		 {
		   rday=rday-28;
		   rmonth++;
		 }
	     }
	   break;
    default: rday=rday+14;
	     if(rday>30)
	       {
		rday=rday-30;
		rmonth++;
	       }
	     break;
   }
  }

  void calculatefine()
  {
    if(tday>rday && tmonth>=rmonth && tyear>=ryear)
    {
      fine=((tday-rday)*2)+((tmonth-rmonth)*60)+((tyear-ryear)*720);
    }
      else if(tday<rday && tmonth>rmonth && tyear>=ryear)
      {
	fine=(((30-rday)+tday)*2)+(((tmonth-1)-rmonth)*60)+((tyear-ryear)*720);
      }
	    else if(tday<rday && tmonth<rmonth && tyear>ryear)
	    {
	      fine=(((30-rday)+tday)*2)+(((12-rmonth)+(tmonth-1))*60)+((tyear-ryear)*720);
	    }
		else if(tday>rday && tmonth<rmonth && tyear>ryear)
		{
		  fine=((tday-rday)*2)+(((12-rmonth)+tmonth)*60)+((tyear-ryear)*720);
		}
		  else
		    {
		      fine=0;
		    }
  }


  void entermemberdetails()
  {
    cout<<"\nEnter the name of member: ";
    gets(namemember);
    cout<<"Enter the code of the member: ";
    cin>>membercode;
  }


  void showmemberdetails()
  {
    cout<<"\nMEMBER NAME: ";
    puts(namemember);
    cout<<"MEMBER CODE: "<<membercode;
    cout<<"\nISSUED BOOK: ";
    puts(nameofbook);
    if(rday==0)
    cout<<"RETURN DATE: NOT ASSIGNED";
    else
    cout<<"RETURN DATE: "<<rday<<"/"<<rmonth<<"/"<<ryear;
    cout<<"\nFINE: "<<fine;
    cout<<"\n \n";
  }


  int checkmemberdetails(char n[])
  {
    if(!strcmpi(n,namemember))
    {
      return 1;
    }

    else
    {
      return 0;
    }
  }


  void issue()
  {
    cout<<"\nEnter date of issue (dd/mm/yyyy): ";
    cin>>iday>>ch>>imonth>>ch>>iyear;
    cout<<"BOOK ISSUED\n";
    dateofreturn();
    cout<<"BOOK TO BE RETURNED ON: "<<rday<<"/"<<rmonth<<"/"<<ryear;
  }

};

//***************************************************************
//    	       MEMBER CLASS ENDS HERE
//***************************************************************


void show_data_books()
{
  books m1;
  ifstream f1("books.dat",ios::binary);
    while(f1.read((char*)&m1, sizeof(m1)))
	  m1.showbookdetails();
  f1.close();
}


void write_data_books()
{ books b1;
  ofstream f1("books.dat", ios::binary|ios::app);
  b1.enterbookdetails();
     f1.write((char*)&b1,sizeof(b1));
     f1.close();
}


void show_data_members()
{
  members m1;
  ifstream f2("members.dat",ios::binary);
    while(f2.read((char*)&m1, sizeof(m1)))
	  m1.showmemberdetails();
  f2.close();
}


void show_data_member()
{
  clrscr();
  char name[40];
  cout<<"\n\nENTER THE NAME OF THE MEMBER WHOSE DETALIS ARE TO BE SHOWN: ";
  gets(name);
  members m1;
  ifstream f2("members.dat",ios::binary);
    while(f2.read((char*)&m1, sizeof(m1)))
    {
	 if(m1.checkmemberdetails(name))
	    m1.showmemberdetails();
    }
  f2.close();
}


void show_data_book()
{
  clrscr();
  char name[40];
  cout<<"\n\nENTER THE NAME OF THE BOOK WHOSE DETALIS ARE TO BE SHOWN: ";
  gets(name);
  books b1;
  ifstream f2("members.dat",ios::binary);
    while(f2.read((char*)&b1, sizeof(b1)))
    {
	 if(b1.checkbookdetails(name))
	    b1.showbookdetails();
    }
  f2.close();
}



void write_data_members()
{ members m1;
  ofstream f2("members.dat", ios::binary|ios::app);
  m1.entermemberdetails();
     f2.write((char*)&m1,sizeof(m1));
     f2.close();
}


void modify_data_members()
{
  members m1;
  cout<<"\nEnter the name of the member whose information you want to modify:\n";
  char name[80];
  gets(name);
  fstream f1;
  f1.open("members.dat", ios::in|ios::out|ios::binary);
  int n=f1.tellg();
  while(f1.read((char*)&m1, sizeof(m1)))
  {
       if(m1.checkmemberdetails(name))
       {  m1.entermemberdetails();
	  f1.seekg(n,ios::beg);
	  f1.write((char*)&m1,sizeof(m1));
       }
       n=f1.tellg();
  }
  f1.close();
}


void delete_data_members()
{
  members m1;
  cout<<"\nEnter the name of the member whose information you want to delete:\n";
  char name[80];
  gets(name);
  ifstream f1;
  ofstream f2;
  f1.open("members.dat",ios::binary);
  f2.open("temp.dat", ios::binary);
  while(f1.read((char*)&m1, sizeof(m1)))
  {
       if(!m1.checkmemberdetails(name))
	  f2.write((char*)&m1, sizeof(m1));
  }
  f1.close();
  f2.close();
  remove("members.dat");
  rename("temp.dat", "members.dat");
}


void modify_data_books()
{
  books b1;
  cout<<"\nEnter the name of the book whose information you want to modify:\n";
  char name[80];
  gets(name);
  fstream f1;
  f1.open("books.dat", ios::in|ios::out|ios::binary);
  int n=f1.tellg();
  while(f1.read((char*)&b1, sizeof(b1)))
  {
       if(b1.checkbookdetails(name))
       {  b1.enterbookdetails();
	  f1.seekg(n,ios::beg);
	  f1.write((char*)&b1,sizeof(b1));
       }
       n=f1.tellg();
  }
  f1.close();
}


void delete_data_books()
{
  books b1;
  cout<<"\nEnter the name of the book whose information you want to delete:\n";
  char name[80];
  gets(name);
  ifstream f1;
  ofstream f2;
  f1.open("books.dat",ios::binary);
  f2.open("temp.dat", ios::binary);
  while(f1.read((char*)&b1, sizeof(b1)))
  {
       if(!b1.checkbookdetails(name))
	  f2.write((char*)&b1, sizeof(b1));
  }
  f1.close();
  f2.close();
  remove("books.dat");
  rename("temp.dat", "books.dat");
  }


//***************************************************************
//    	       FUNCTION TO ISSUE BOOK
//***************************************************************


void issue_book()
{ int a=0;
  fstream f1,f2;
  f1.open("members.dat", ios::in|ios::out|ios::binary);
  f2.open("books.dat", ios::in|ios::out|ios::binary);
  int m=f1.tellg();
  int n=f2.tellg();
  members m1;
  books b1;
  char bname[80],mname[80];
  cout<<"\nEnter the name of the member\n";
  gets(mname);
  while(f1.read((char*)&m1, sizeof(m1)))
       {
	 if(m1.checkmemberdetails(mname))
	   {
	     if(!strcmpi(m1.nameofbook,"NO BOOK IS ISSUED"))
	       {
		 a=1;
		 cout<<"Enter the name of the book to be issued\n";
		 gets(bname);
		   while(f2.read((char*)&b1, sizeof(b1)))
		      {
			if(b1.checkbookdetails(bname))
			  {
			   if(b1.returnavailablebooks()>0)
			     {
			       cout<<"BOOK IS AVAILABLE\n";
			       m1.issue();
			       b1.issuebook();
			       strcpy(m1.nameofbook,bname);
			       f1.seekg(m,ios::beg);
			       f1.write((char*)&m1,sizeof(m1));
			       f2.seekg(n,ios::beg);
			       f2.write((char*)&b1, sizeof(b1));
			     }
			   else
			     cout<<"BOOK UNAVAILABLE";
			   }
			  n=f2.tellg();
			}
		   }
	       }
	       m=f1.tellg();
	   }
  if(!a)
  cout<<"BOOK CANNOT BE ISSUED..\nPLEASE RETURN PREVIOUSLY ISSUED BOOK";
  }


//***************************************************************
//    	       FUNCTION TO RETURN BOOK
//***************************************************************


  void return_book()
  {
  fstream f1,f2;
  f1.open("members.dat", ios::in|ios::out|ios::binary);
  f2.open("books.dat", ios::in|ios::out|ios::binary);
  int m=f1.tellg();
  int n=f2.tellg();
  members m1;
  books b1;
  char bname[80],mname[80];
  cout<<"\nEnter the name of the member\n";
  gets(mname);
  while(f1.read((char*)&m1, sizeof(m1)))
       {
	 if(m1.checkmemberdetails(mname))
	   {
	     strcpy(bname,m1.nameofbook);
	     while(f2.read((char*)&b1, sizeof(b1)))
		      {
			if(b1.checkbookdetails(bname))
			  {
			       m1.returnb();
			       b1.returnbook();
			       strcpy(m1.nameofbook,"NO BOOK IS ISSUED");
			       f1.seekg(m,ios::beg);
			       f1.write((char*)&m1,sizeof(m1));
			       f2.seekg(n,ios::beg);
			       f2.write((char*)&b1, sizeof(b1));
			   }

			  n=f2.tellg();
		      }
	   }

	 m=f1.tellg();
       }


}


//***************************************************************
//    	       INTRODUCTION FUNCTION
//***************************************************************


void intro()
{
	clrscr();
	gotoxy(35,7);
	cout<<"LIBRARY";
	gotoxy(34,9);
	cout<<"MANAGEMENT";
	gotoxy(36,11);
	cout<<"SYSTEM";
	cout<<"\n\n\n\n\nMADE BY : DEVANSH CHAWLA AND MUSKAN JAIN";
	cout<<"\n\nSCHOOL : THE SRIJAN SCHOOL";
	getch();
}


//***************************************************************
//    	       ADMINISTRATOR MENU FUNCTION
//***************************************************************


void admin_menu()
{
	clrscr();
	int ch2;
	cout<<"\n\n\n\tADMINISTRATOR MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
	cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.CREATE BOOK ";
	cout<<"\n\n\t7.DISPLAY ALL BOOKS ";
	cout<<"\n\n\t8.DISPLAY SPECIFIC BOOK ";
	cout<<"\n\n\t9.MODIFY BOOK ";
	cout<<"\n\n\t10.DELETE BOOK ";
	cout<<"\n\n\t11.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-11) ";
	cin>>ch2;
	switch(ch2)
	{
		case 1: clrscr();
			write_data_members();
			break;
		case 2: clrscr();
			show_data_members();
			getch();
			break;
		case 3: clrscr();
			show_data_member();
			getch();
			break;
		case 4: clrscr();
			modify_data_members();
			break;
		case 5: clrscr();
			delete_data_members();
			break;
		case 6: clrscr();
			write_data_books();
			break;
		case 7: clrscr();
			show_data_books();
			getch();
			break;
		case 8: clrscr();
			show_data_book();
			getch();
		case 9: clrscr();
			modify_data_books();
			break;
		case 10:clrscr();
			delete_data_books();
			break;
		case 11: return;
		default:cout<<"\n\n\tPLEASE ENTER A VALID CHOICE";
			getch();
	}
	admin_menu();
}


//***************************************************************
//    	       THE MAIN FUNCTION OF THE PROGRAM
//***************************************************************


void main()
{
	char ch;
	intro();
	do
	{
		clrscr();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. BOOK ISSUE";
		cout<<"\n\n\t02. BOOK DEPOSIT";
		cout<<"\n\n\t03. ADMINISTRATOR MENU";
		cout<<"\n\n\t04. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-4) ";
		ch=getche();
		switch(ch)
		{
			case '1':clrscr();
				 issue_book();
				 getch();
				 break;
			case '2':clrscr();
				 return_book();
				 getch();
				 break;
			case '3':clrscr();
				 admin_menu();
				 break;
			case '4':exit(0);
			default :cout<<"\n\n\tPLEASE ENTER A VALID CHOICE!!!";
				 getch();
		}
	}while(ch!='4');
}

