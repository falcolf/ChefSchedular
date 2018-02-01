#include<iostream>
#include <algorithm>
using namespace std;
class customers{
	public:
	string name;
	int food;
	int start;
	int finish;
	int profit;
	
	void getData(){
		cout<<"\nEnter Customer's name : ";
		cin>>name;
		food=getChoice();
		start=getStart();
		finish=start+getFinish();
		profit=getProfit();
	}
	void showData(){
		cout<<"\nName           : "<<name;
		cout<<"\nCusisine       : "<<getFoodType();
		cout<<"\nVisiting Time  : "<<getVisitTime();
		cout<<"\nFinishing Time : ";getFinishTime();
		cout<<"\nProfit         : "<<profit;
		cout<<"\n";
	}
	string getFoodType(){
		switch(food){
			case 0:
				break;
			case 1:return "FRENCH";
				break;
			case 2:return "ITALIAN";
				break;
			case 3:return "CHINESE";
				break;
			case 4:return "THAI";
				break;
			case 5:return "MUGHLAI";
				break;
		}
	}
	string getVisitTime(){
		switch(start){
			case 0:return "7:00";
			case 30:return "7:30";
			case 60:return "8:00";
			case 90:return "8:30";
			case 120:return "9:00";
			case 150:return "9:30";
			case 180:return "10:00";
			case 210:return "10:30";
		}
	}
	void getFinishTime(){
		int a=finish/60;
		int b=finish%60;
		if(b==0)
		cout<<a+7<<":00";
		else
		cout<<a+7<<":"<<b;
	}
	int getProfit(){
		switch(food){
			case 1:return 8000;
				break;
			case 2:return 6000;
				break;
			case 3:return 3000;
				break;
			case 4: return 5000;
				break;
			case 5: return 9000;
				break;
		}
		
	}
	int getFinish(){
		switch(food){
			case 1:return 75;
				break;
			case 2:return 60;
				break;
			case 3:return 30;
				break;
			case 4: return 45;
				break;
			case 5: return 90;
				break;
		}
	}
	int getStart(){
		A:
		cout<<"\nEnter visiting time : ";
		cout<<"\nPress 0 for 7:00";
		cout<<"\nPress 1 for 7:30";
		cout<<"\nPress 2 for 8:00";
		cout<<"\nPress 3 for 8:30";
		cout<<"\nPress 4 for 9:00";
		cout<<"\nPress 5 for 9:30";
		cout<<"\nPress 6 for 10:00";
		cout<<"\nPress 7 for 10:30\n";
		int n;
		cin>>n;
		switch(n){
			case 0:return 0;
				break;
			case 1:return 30;
				break;
			case 2:return 60;
				break;
			case 3:return 90;
				break;
			case 4:return 120;
				break;
			case 5:return 150;
				break;
			case 6:return 180;
				break;
			case 7:return 210;
				break;
			default:cout<<"Invalid Option\nEnter again\n";
					goto A;
		}
	}
	int getChoice(){
		A:
	cout<<"\nSNO\tCUISINES\tPAY(Rs)\tDURATION(min)\n";
	cout<<"1.\tFRENCH   \t8000\t75\n";
	cout<<"2.\tITALIAN  \t6000\t60\n";
	cout<<"3.\tCHINESE  \t3000\t30\n";
	cout<<"4.\tTHAI     \t5000\t45\n";
	cout<<"5.\tMUGHLAI  \t9000\t90\n";
	cout<<"\n\nEnter the choice of cuisine for the customer : ";
	int n;
	cin>>n;
	if(n>5 || n<1){
		cout<<"Invalid Option\nEnter again\n";
			goto A;
	}
		
	return n;
}
};
class aar{
	public:
		int ar[10];
		aar(){
			for(int i=0;i<10;i++)
				ar[i]=99;
		}
};
int lastnccustomer(customers cust[], int i)
{
    for (int j=i-1; j>=0; j--)
    {
        if (cust[j].finish <= cust[i].start)
            return j;
    }
    return -1;
}
bool comp(customers c1, customers c2)
{
    return (c1.finish < c2.finish);
}
int findAppCustomers(customers cust[] , int n)
{
    sort(cust, cust+n, comp);
 	int tab[n];
 	aar ar[n];
 	tab[0] = cust[0].profit;
 	ar[0].ar[0]=0;
    for (int i=1; i<n; i++)
    {
    	int ip = cust[i].profit;
        int l = lastnccustomer(cust, i);
        
		if (l != -1)
            ip+= tab[l];
 		
		tab[i] = max(ip,tab[i-1]);
		if(ip>tab[i-1]){
			if(l>=0)
			for(int k=i-1;k>=0;k--){
				ar[i].ar[k]=ar[l].ar[k];
				ar[i].ar[i]=i;
			}
				
			else
				for(int k=i-1;k>=0;k--){
					ar[i].ar[k]=99;
					ar[i].ar[i]=i;
				}
					
		}
		else{
			for(int k=i-1;k>=0;k--)
				ar[i].ar[k]=ar[i-1].ar[k];
			ar[i].ar[i]=99;
		}
		
	}
	cout<<"Customers to visit are : \n";
	for(int i=0;i<n;i++){
	if(ar[n-1].ar[i]!=99)
	cust[ar[n-1].ar[i]].showData();
	cout<<"\n";
	}
	int finalprofit = tab[n-1];
	cout<<"\nFinal Profit for the night will be : "<<finalprofit;
	
}
void about(){
	system("pause");
	system("cls");
	
	cout<<"CHEF GUSTAVO IS ONE OF THE BEST CHEFS WHO TAKES ADVANCE OFFERS FROM CLIENTS FOR THE DINNER.\n";
	cout<<"CHOICE AMONG FIVE CUISINES ARE AVAILABLE FOR CUSTOMERS.\n";
	cout<<"BUT HE DOESN'T WORK ON FIRST COME FIRST BASIS :( \nINSTEAD, HE ACCEPTS THE OFFERS WHERE HE HAS THE BEST PROFIT.\n";
	cout<<"THEREFORE THIS SOFTWARE HELPS HIM DECIDE QUICKLY WHAT OFFERS WOULD GIVE HIM \nMAXIMUM PROFIT FOR THE EVENING\n";
	
	
}
int main(){
	
	cout<<"\n\n\n\n\n\t HOME CHEFF GUSTAVO'S JOB SCHEDULING SYSTEM";
	cout<<"\n\n\n\tMAXIMIZED CONSOLE WINDOW IS ADVICED FOR A GOOD EXPERIENCE";
	cout<<"\n\n\n\n\n   DEVELOPED BY\n ->PARTH AGARWAL(RA1511003010326)\n ->DHRUVE MOUDGIL(RA1511003010346)\n ->ANKIT HAZARKIA(RA1511003010356)\n ->ASHIK KHALLEL(RA1511003010388)\n ->SHUBHAM BAJPAYEE(RA1511003010398)";
	cout<<"\n\n\n\n\n\n";
	
	A:
	system("pause");
	system("cls");
	cout<<"1-PROCEED\n2-ABOUT\n\n";
	int opt;
	cin>>opt;
	switch(opt){
		case 1:goto B;
			break;
		case 2:about();
			break;
		default:cout<<"ERROR , SELECT VALID OPTION\n";goto A;
		}	
	B:
	system("pause");
	system("cls");
	
	cout<<"WELCOME CHEFF GUSTAVO , LETS PLAN THE EVENING FOR YOU...!";
	cout<<"\n\n";
	cout<<"HOW MANY OFFERS DO YOU HOLD FOR TODAY EVENING?\n";
	int n;
	cin>>n;
	system("pause");
	system("cls");
	customers custom[n];
	for(int i=0;i<n;i++){
		cout<<"Enter Data for customer "<<i+1;
		custom[i].getData();
		cout<<"\n\n";
		system("pause");
		system("cls");
	}
	cout<<"Data are : \n";
	for(int i=0;i<n;i++){
		cout<<"Customer "<<i+1;
		custom[i].showData();
	}
	cout<<"\n";
	system("pause");
	cout<<"\n";
	findAppCustomers(custom , n);
	return 0;
}
