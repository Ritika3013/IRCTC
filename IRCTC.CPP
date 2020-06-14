//   IRCTC

/*************************************************************************
 *************************************************************************
 **************************  HEADER    FILES  ****************************
 *************************************************************************
 *************************************************************************/
								  //******
								  //******
#include<fstream.h>                                               //******
#include<process.h>                                               //******
#include<string.h>                                                //******
#include<stdlib.h>                                                //******
#include<conio.h>                                                 //******
#include<stdio.h>                                                 //******
#include<dos.h>                                                   //******
								  //******
//************************************************************************
//************************************************************************

fstream f;
ifstream fin;
ofstream fout;
struct date d;

class Train
{
   int T_no,ac_1,ac_2,slpr,ac_cc,fair_ac1,fair_ac2,fair_sl,fair_cc;
   char T_name[20],Source[20],Destination[20];
   public:
   Train()
   {
      T_no=0;
      ac_1=0;
      ac_2=0;
      slpr=0;
      ac_cc=0;
      fair_ac1=0;
      fair_ac2=0;
      fair_sl=0;
      fair_cc=0;
      strcpy(T_name,'\0');
      strcpy(Source,'\0');
      strcpy(Destination,'\0');
   }
   int ret_price_ac1()
   {
      return fair_ac1;
   }
   int ret_price_ac2()
   {
      return fair_ac2;
   }
   int ret_price_sl()
   {
      return fair_sl;
   }
   int ret_price_cc()
   {
      return fair_cc;
   }
   int ret_tno()
   {
      return T_no;
   }
   int ret_ac1()
   {
      return ac_1;
   }
   int ret_ac2()
   {
      return ac_2;
   }
   int ret_sl()
   {
      return slpr;
   }
   int ret_cc()
   {
      return ac_cc;
   }
   void Input();
   void Display();
}Tr,Tr1;

void Train::Input()
{
   clrscr();
   gotoxy(10,10);
   cout<<"Enter The TRAIN NO.                         -->   ";
   cin>>T_no;
   gotoxy(10,12);
   cout<<"Enter The TRAIN NAME                        -->   ";
   gets(T_name);
   gotoxy(10,14);
   cout<<"Enter The SOURCE Of TRAIN                   -->   ";
   gets(Source);
   gotoxy(10,16);
   cout<<"Enter The DESTINATION Of TRAIN              -->   ";
   gets(Destination);
   gotoxy(10,18);
   cout<<"Enter The No. Of Seats In AC FIRST CLASS    -->   ";
   cin>>ac_1;
   gotoxy(10,20);
   cout<<"Enter The No. Of Seats In AC SECOND CLASS   -->   ";
   cin>>ac_2;
   gotoxy(10,22);
   cout<<"Enter The No. Of Seats In SLEEPER CLASS     -->   ";
   cin>>slpr;
   gotoxy(10,24);
   cout<<"Enter The No. Of Seats In AC CHAIR CAR      -->   ";
   cin>>ac_cc;
   gotoxy(10,26);
   cout<<"Enter The Fair For AC FIRST CLASS           -->   ";
   cin>>fair_ac1;
   gotoxy(10,28);
   cout<<"Enter The Fair For AC SECOND CLASS          -->   ";
   cin>>fair_ac2;
   gotoxy(10,30);
   cout<<"Enter The Fair For SLEEPER CLASS            -->   ";
   cin>>fair_sl;
   gotoxy(10,32);
   cout<<"Enter The Fair For CHAIR CAR                -->   ";
   cin>>fair_cc;
}

void Train::Display()
{
   clrscr();
   gotoxy(10,12);
   cout<<"TRAIN NAME                        -->   ";
   cout<<T_name;
   gotoxy(10,10);
   cout<<"TRAIN NO.                         -->   ";
   cout<<T_no;
   gotoxy(10,14);
   cout<<"SOURCE Of TRAIN                   -->   ";
   cout<<Source;
   gotoxy(10,16);
   cout<<"DESTINATION Of TRAIN              -->   ";
   cout<<Destination;
   gotoxy(10,18);
   cout<<"No. Of Seats In AC FIRST CLASS    -->   ";
   cout<<ac_1;
   gotoxy(10,20);
   cout<<"No. Of Seats In AC SECOND CLASS   -->   ";
   cout<<ac_2;
   gotoxy(10,22);
   cout<<"No. Of Seats In SLEEPER CLASS     -->   ";
   cout<<slpr;
   gotoxy(10,24);
   cout<<"No. Of Seats In AC CHAIR CAR      -->   ";
   cout<<ac_cc;
   gotoxy(10,26);
   cout<<"Fair For AC FIRST CLASS           -->   ";
   cout<<fair_ac1;
   gotoxy(10,28);
   cout<<"Fair For AC SECOND CLASS          -->   ";
   cout<<fair_ac2;
   gotoxy(10,30);
   cout<<"Fair For SLEEPER CLASS            -->   ";
   cout<<fair_sl;
   gotoxy(10,32);
   cout<<"Fair For CHAIR CAR                -->   ";
   cout<<fair_cc;
   gotoxy(10,35);
   cout<<"Press Any Key To Continue ...";
   getch();
}


class Ticket
{
   int dd,mm,yy;
   int age,clas,pnr,tot_ac1,ac1,tot_ac2,ac2,tot_sl,sl,tot_cc,cc;
   int fair,ac1_fair,ac2_fair,sl_fair,cc_fair;
   char Status[10],Name[20];
   public:
   Ticket()
   {
      age=0;
      pnr=0;
      tot_ac1=0;
      ac1=0;
      tot_ac2=0;
      ac2=0;
      tot_sl=0;
      sl=0;
      tot_cc=0;
      cc=0;
      ac1_fair=0;
      ac2_fair=0;
      sl_fair=0;
      cc_fair=0;
      strcpy(Status,'\0');
      strcpy(Name,'\0');
   }
   int ret_pnr()
   {
      return pnr;
   }
   int ret_clas()
   {
      return clas;
   }
   void Reserve();
   void Cancel();
   void Display();
   void Disp_detail();
   void Gen_pnr();
}Tick,Tick1;

void Ticket::Disp_detail()
{
   clrscr();
   gotoxy(10,10);
   cout<<"NAME     -->   "<<Name;
   gotoxy(10,12);
   cout<<"AGE      -->   "<<age;
   gotoxy(10,14);
   cout<<"PNR No.  -->   "<<pnr;
   gotoxy(10,16);
   cout<<"STATUS   -->   "<<Status;
   gotoxy(10,18);
   cout<<"CLASS    -->   ";
   if(clas==1)
   {
      cout<<"AC FIRTS CLASS";
   }
   else if(clas==2)
   {
      cout<<"AC SECOND CLASS";
   }
   else if(clas==3)
   {
      cout<<"SLEPPER CLASS";
   }
   else if(clas==4)
   {
      cout<<"AC CHAIR CAR";
   }
   gotoxy(10,20);
   cout<<"FAIR     -->   "<<"Rs. "<<fair;
}

void Ticket::Gen_pnr()
{
   randomize();
   pnr=random(2000)+30000;
}

void Ticket::Reserve()
{
   int tno,found,check=0;
   S:
   clrscr();
   gotoxy(10,6);
   cout<<"********** RESERVATION MENU **********";
   gotoxy(10,9);
   cout<<"Enter The TRAIN NO.     -->   ";
   cin>>tno;
   fin.open("TRAIN.dat" , ios::binary);
   if(!fin)
   {
      clrscr();
      gotoxy(10,10);
      cout<<"ERROR In The Opening File";
   }
   else
   {
      while(fin.read((char *)&Tr,sizeof(Tr)))
      {
	 if(tno==Tr.ret_tno())
	 {
	    check=1;
	    ac1=Tr.ret_ac1();
	    ac2=Tr.ret_ac2();
	    sl=Tr.ret_sl();
	    cc=Tr.ret_cc();
	    ac1_fair=Tr.ret_price_ac1();
	    ac2_fair=Tr.ret_price_ac2();
	    sl_fair=Tr.ret_price_sl();
	    cc_fair=Tr.ret_price_cc();
	 }
      }
      fin.close();
      if(check==1)
      {
	 gotoxy(10,11);
	 cout<<"Enter Your NAME         -->   ";
	 gets(Name);
	 gotoxy(10,13);
	 cout<<"Enter Your Age          -->   ";
	 cin>>age;
	 gotoxy(10,15);
	 cout<<"Enter The Date          -->   ";
	 cin>>dd;
	 gotoxy(10,17);
	 cout<<"Enter The Month         -->   ";
	 cin>>mm;
	 gotoxy(10,19);
	 cout<<"Enter The Year          -->   ";
	 cin>>yy;
	 getdate(&d);
	 if(dd==1 || dd==3 || dd==5 || dd==7 || dd==8 || dd==10 || dd==12)
	 {
	    if(dd<1 || dd>31)
	    {
	       gotoxy(10,22);
	       cout<<"You Have Entered An Invalid Date !!!";
	       gotoxy(10,23);
	       cout<<"Fill The Form Again.";
	       getch();
	       goto S;
	    }
	 }
	 else if(dd==4 || dd==6 || dd==9 || dd==11)
	 {
	    if(dd<1 || dd>30)
	    {
	       gotoxy(10,22);
	       cout<<"You Have Entered An Invalid Date !!!";
	       gotoxy(10,23);
	       cout<<"Fill The Form Again.";
	       getch();
	       goto S;
	    }
	 }
	 else if(dd==2)
	 {
	    if(dd<1 || dd>28)
	    {
	       gotoxy(10,22);
	       cout<<"You Have Entered An Invalid Date !!!";
	       gotoxy(10,23);
	       cout<<"Fill The Form Again.";
	       getch();
	       goto S;
	    }
	 }
	 if(yy<d.da_year)
	 {
	    gotoxy(10,22);
	    cout<<"You Have Entered An Invalid Date !!!";
	    gotoxy(10,23);
	    cout<<"Fill The Form Again.";
	    getch();
	    goto S;
	 }
	 else if(yy==d.da_year)
	 {
	    if(mm<d.da_mon)
	    {
	       gotoxy(10,22);
	       cout<<"You Have Entered An Invalid Date !!!";
	       gotoxy(10,23);
	       cout<<"Fill The Form Again.";
	       getch();
	       goto S;
	    }
	    else if(mm<=12 && dd<=31)
	    {
	       if(mm==d.da_mon && dd<d.da_day)
	       {
		  gotoxy(10,22);
		  cout<<"You Have Entered An Invalid Date !!!";
		  gotoxy(10,23);
		  cout<<"Fill The Form Again.";
		  getch();
		  goto S;
	       }
	    }
	    else
	    {
	       gotoxy(10,22);
	       cout<<"You Have Entered An Invalid Date !!!";
	       gotoxy(10,23);
	       cout<<"Fill The Form Again.";
	       getch();
	       goto S;
	    }
	 }
	 gotoxy(10,19);
	 cout<<"Select CLASS in Which You Wish To TRAVEL";
	 gotoxy(10,21);
	 cout<<"1. AC FIRST CLASS";
	 gotoxy(10,22);
	 cout<<"2. AC SECOND CLASS";
	 gotoxy(10,23);
	 cout<<"3. SLEPPER CLASS";
	 gotoxy(10,24);
	 cout<<"4. AC CHAIR CAR";
	 gotoxy(10,26);
	 cout<<"Enter Class In Which You Wish To Travel   -->   ";
	 cin>>clas;
	 switch(clas)
	 {
	    case 1: tot_ac1++;
		    do
		    {
		       found=0;
		       Gen_pnr();
		       fin.open("TICKET.dat", ios::binary);
		       fin.seekg(0);
		       while(fin.read((char *)&Tick1,sizeof(Tick1)))
		       {
			  if(Tick1.ret_pnr()==pnr)
			  {
			     found=1;
			     break;
			  }
		       }
		       fin.close();
		    }while(found==1);
		    fair=ac1_fair;
		    fout.open("TICKET.dat", ios::binary | ios::app);
		    if((ac1-tot_ac1)>=0)
		    {
		       strcpy(Status,"Confirmed");
		       fout.write((char *)&Tick,sizeof(Tick));
		    }
		    else
		    {
		       strcpy(Status,"Waiting");
		       fout.write((char *)&Tick,sizeof(Tick));
		    }
		    fout.close();
		    break;

	    case 2: tot_ac2++;
		    do
		    {
		       found=0;
		       Gen_pnr();
		       fin.open("TICKET.dat", ios::binary);
		       fin.seekg(0);
		       while(fin.read((char *)&Tick1,sizeof(Tick1)))
		       {
			  if(Tick.ret_pnr()==pnr)
			  {
			     found=1;
			     break;
			  }
		       }
		       fin.close();
		    }while(found==1);
		    fair=ac2_fair;
		    fout.open("TICKET.dat", ios::binary | ios::app);
		    if((ac2-tot_ac2)>=0)
		    {
		       strcpy(Status,"Confirmed");
		       fout.write((char *)&Tick,sizeof(Tick));
		    }
		    else
		    {
		       strcpy(Status,"Waiting");
		       fout.write((char *)&Tick,sizeof(Tick));
		    }
		    fout.close();
		    break;

	    case 3: tot_sl++;
		    do
		    {
		       found=0;
		       Gen_pnr();
		       fin.open("TICKET.dat", ios::binary);
		       fin.seekg(0);
		       while(fin.read((char *)&Tick1,sizeof(Tick1)))
		       {
			  if(Tick.ret_pnr()==pnr)
			  {
			     found=1;
			     break;
			  }
		       }
		       fin.close();
		    }while(found==1);
		    fair=sl_fair;
		    fout.open("TICKET.dat", ios::binary | ios::app);
		    if((sl-tot_sl)>=0)
		    {
		       strcpy(Status,"Confirmed");
		       fout.write((char *)&Tick,sizeof(Tick));
		    }
		    else
		    {
		       strcpy(Status,"Waiting");
		       fout.write((char *)&Tick,sizeof(Tick));
		    }
		    fout.close();
		    break;

	    case 4: tot_cc++;
		    do
		    {
		       found=0;
		       Gen_pnr();
		       fin.open("TICKET.dat", ios::binary);
		       fin.seekg(0);
		       while(fin.read((char *)&Tick1,sizeof(Tick1)))
		       {
			  if(Tick.ret_pnr()==pnr)
			  {
			     found=1;
			     break;
			  }
		       }
		       fin.close();
		    }while(found==1);
		    fair=cc_fair;
		    fout.open("TICKET.dat", ios::binary | ios::app);
		    if((cc-tot_cc)>=0)
		    {
		       strcpy(Status,"Confirmed");
		       fout.write((char *)&Tick,sizeof(Tick));
		    }
		    else
		    {
		       strcpy(Status,"Waiting");
		       fout.write((char *)&Tick,sizeof(Tick));
		    }
		    fout.close();
		    break;
	 }
	 gotoxy(10,29);
	 cout<<"PNR NO            -->   ";
	 cout<<pnr;
	 gotoxy(10,31);
	 cout<<"STATUS            -->   ";
	 cout<<Status;
	 gotoxy(10,33);
	 cout<<"FAIR              -->   ";
	 cout<<"Rs. "<<fair;
	 getch();
	 gotoxy(10,36);
	 cout<<"Do You Wish To Book More Tickets(Y/N)   -->   ";
	 char n;
	 cin>>n;
	 if(n=='Y' || n=='y')
	 {
	    goto S;
	 }
      }
   }
   if(check==0)
   {
      clrscr();
      gotoxy(10,10);
      cout<<"Error In Train No. Entered ...!!!";
      getch();
   }
}

void Ticket::Cancel()
{
   int num=0,no,check=0;
   long pos;
   clrscr();
   fin.open("TICKET.dat", ios::binary);
   f.open("TEMP.dat", ios::binary | ios::in | ios::out);
   if(!fin)
   {
      clrscr();
      gotoxy(10,10);
      cout<<"ERROR In Opening The File";
      return;
   }
   gotoxy(10,10);
   cout<<"Enter Ther PNR NO.   -->   ";
   cin>>no;
   while(fin.read((char *)&Tick,sizeof(Tick)))
   {
      if(no!=Tick.ret_pnr())
      {
	 f.write((char *)&Tick,sizeof(Tick));
      }
      else
      {
	 check=1;
	 Tick.Disp_detail();
	 if((Tick.ret_clas()==1))
	 {
	    tot_ac1--;
	 }
	 else if((Tick.ret_clas()==2))
	 {
	    tot_ac2--;
	 }
	 else if((Tick.ret_clas()==3))
	 {
	    tot_sl--;
	 }
	 else if((Tick.ret_clas()==4))
	 {
	    tot_cc--;
	 }
      }
   }
   fin.close();
   f.seekg(0);
   while(f.read((char *)&Tick,sizeof(Tick)))
   {
      pos=f.tellg()-sizeof(Tick);
      if(num!=1 && (strcmp(Tick.Status,"Waiting")==0))
      {
	 strcpy(Tick.Status,"Confirmed");
	 f.seekg(pos);
	 f.write((char *)&Tick,sizeof(Tick));
	 num=1;
      }
   }
   f.close();
   remove("TICKET.dat");
   rename("TEMP.dat","TICKET.dat");
   if(check==0)
   {
      gotoxy(10,12);
      cout<<"No Such Reservation Is Made ...!!!!";
      getch();
   }
   else
   {
      gotoxy(10,22);
      cout<<"RESERVATION CANCELLED";
      getch();
   }
}

void Ticket::Display()
{
   int check;
   X:
   check=0;
   clrscr();
   fin.open("TICKET.dat", ios::binary);
   if(!fin)
   {
      gotoxy(10,10);
      cout<<"ERROR In Opening The File ...!!!!";
      getch();
      return;
   }
   gotoxy(10,10);
   int res_no;
   cout<<"Enter The PNR No.   -->   ";
   cin>>res_no;
   while(fin.read((char *)&Tick,sizeof(Tick)))
   {
      if(res_no==Tick.ret_pnr())
      {
	 clrscr();
	 check=1;
	 gotoxy(10,12);
	 cout<<"NAME      -->   ";
	 cout<<Name;
	 gotoxy(10,14);
	 cout<<"AGE       -->   ";
	 cout<<age;
	 gotoxy(10,16);
	 cout<<"PNR No.   -->   ";
	 cout<<pnr;
	 gotoxy(10,18);
	 cout<<"STATUS    -->   ";
	 cout<<Status;
	 gotoxy(10,20);
	 cout<<"CLASS     -->   ";
	 if(clas==1)
	 {
	    cout<<"AC FIRTS CLASS";
	 }
	 else if(clas==2)
	 {
	    cout<<"AC SECOND CLASS";
	 }
	 else if(clas==3)
	 {
	    cout<<"SLEPPER CLASS";
	 }
	 else if(clas==4)
	 {
	    cout<<"AC CHAIR CAR";
	 }
	 gotoxy(10,22);
	 cout<<"FAIR      -->   ";
	 cout<<"Rs. "<<fair;
	 gotoxy(10,25);
	 cout<<"Press Any Key To Continue ...";
	 getch();
      }
   }
   fin.close();
   if(check==0)
   {
      clrscr();
      char a;
      gotoxy(10,10);
      cout<<"INVALID RESERVSTION No. ...!!!!";
      gotoxy(10,12);
      cout<<"WANNA Try Again(Y/N)    -->   ";
      cin>>a;
      if(a=='Y' || a=='y')
      {
	 fin.close();
	 goto X;
      }
   }
}


void main()
{
   clrscr();
   int i,n,num,found,check=0;
   char ch,pw[10],pass[]="krishanu";
   Start:
   textcolor(BLACK);
   textbackground(WHITE);
   clrscr();
   gotoxy(19,8);
   cout<<"IRCTC TICKET RESERVATION";
   gotoxy(20,11);
   cout<<"1. VIEW TRAIN DETAILS";
   gotoxy(20,13);
   cout<<"2. ADD TRAIN RECORDS";
   gotoxy(20,15);
   cout<<"3. RESERVE A TICKET";
   gotoxy(20,17);
   cout<<"4. CANCEL A TICKET";
   gotoxy(20,19);
   cout<<"5. CHECK TICKET STATUS";
   gotoxy(20,21);
   cout<<"6. EXIT";
   gotoxy(20,24);
   cout<<"Enter Your Choice     -->   ";
   cin>>n;
   switch(n)
   {
      case 1 : found=0;
	       fin.open("TRAIN.dat", ios::binary);
	       clrscr();
	       if(!fin)
	       {
		  gotoxy(10,10);
		  cout<<"NO TRAINS FOUND ...!!!!";
		  getch();
		  fin.close();
		  goto Start;
	       }
	       gotoxy(10,10);
	       cout<<"Enter Train No.   -->   ";
	       cin>>num;
	       while(fin.read((char *)&Tr,sizeof(Tr)))
	       {
		  if(num==Tr.ret_tno())
		  {
		     Tr.Display();
		     found=1;
		     break;
		  }
	       }
	       if(found==0)
	       {
		  gotoxy(10,13);
		  cout<<"TRAIN DOES NOT EXISTS ...!!!!";
		  getch();
	       }
	       fin.close();
	       goto Start;

      case 2:  clrscr();
	       gotoxy(20,10);
	       cout<<"Enter The Password     -->   ";
	       for(i=0;i<10;i++)
	       {
		  pw[i]=getch();
		  if(pw[i]=='\r')
		  {
		     check=1;
		     break;
		  }
		  cout<<"*";
	       }
	       if(check==1)
	       {
		  pw[i]='\0';
	       }
	       for(i=0;i<30;i++)
	       {
		  if(i%10==0)
		  {
		     clrscr();
		     gotoxy(20,30);
		     cout<<"Checking Please Wait";
		  }
		  cout<<" .";
		  delay(50);
	       }
	       if(strcmp(pw,pass)==0)
	       {
		  fout.open("TRAIN.dat", ios::binary | ios::app);
		  if(!fout)
		  {
		     gotoxy(10,10);
		     cout<<"ERROR In Opening The File...!!!!!";
		     getch();
		  }
		  do
		  {
		     fin.open("TRAIN.dat", ios::binary);
		     check:
		     Tr1.Input();
		     fin.seekg(0);
		     while(fin.read((char *)&Tr,sizeof(Tr)))
		     {
			if(Tr1.ret_tno()==Tr.ret_tno())
			{
			   gotoxy(10,35);
			   cout<<"This TRAIN NO. Already Exists";
			   gotoxy(10,37);
			   cout<<"Please Enter The Record Again";
			   getch();
			   goto check;
			}
		     }
		     fin.close();
		     fout.write((char *)&Tr1,sizeof(Tr1));
		     gotoxy(10,35);
		     cout<<"Do You Want To Add Another Train To The Record(Y/N)   -->   ";
		     cin>>ch;
		  }while(ch=='Y' || ch=='y');
		  fout.close();
		  goto Start;
	       }
	       else
	       {
		  clrscr();
		  gotoxy(20,16);
		  cout<<"You Have Entered WRONG PASSWORD ...!!!!";
		  gotoxy(20,18);
		  cout<<"Try Again";
		  getch();
		  goto Start;
	       }

      case 3 : Tick.Reserve();
	       goto Start;

      case 4 : Tick.Cancel();
	       goto Start;

      case 5 : Tick.Display();
	       goto Start;

      case 6 : exit(0);

      default: gotoxy(10,27);
	       cout<<"You Have Entered An Invalid Option...!!!!!";
	       gotoxy(10,29);
	       cout<<"Plese Enter Again";
	       getch();
	       goto Start;
   }
   getch();
}