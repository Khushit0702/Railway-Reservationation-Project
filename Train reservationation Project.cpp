// Train reservationation Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include < stdlib.h >
using namespace std;

int cost1;

class route//Class to find the shortest route and calculate the cost 
{
    int c = 0;
     int graph[4][4];
     int i = 0,j=0;

     int inputr()
     {
         cout << "\nEnter the cost matrix: " << endl;
         for (i = 0;i < 4; i++)
         {
             cout << "Row: " << i + 1 << endl;
             for (j = 0;j < 4;j++)
             {
                 cin >> graph[i][j];
             }
             cout << "\n";
         }

         return 0;
     }

    void swap(int* x, int* y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

    void copyarr(int* a, int n)
    {
        int i, sum = 0;
        for (i = 0; i <= n; i++)
        {
            sum += graph[a[i % 4]][a[(i + 1) % 4]];
        }
        if (cost > sum)
        {
            cost1=cost = sum;
        }
    }

    void permute(int* a, int i, int n)
    {
        int j=0, k=0;
        if (i == n)
        {
            copyarr(a, n);
        }
        else
        {
            for (j = i; j <= n; j++)
            {
                swap((a + i), (a + j));
                permute(a, i + 1, n);
                swap((a + i), (a + j));
            }
        }
    }

public:
    int cost = 999;
    float amt;
    int read()
    {
        
        inputr();
        int i=0, j=0;
        int a[] = { 0, 1, 2, 3 };
        permute(a, 0, 3);
        cout << "\nMinimum route cost from Mumbai to Pune: " << cost << endl;
      
        cout << "\nCost per unit distance per passenger: Rs 20" << endl;
        cout << "Total Amount per passenger: " << amount() << endl;
        
        return 0;
    }

    float amount()
    {
        amt = cost1 * 20;
        return amt; 
    }
   
    friend class train;//Using friend class to give access to train class
};

class train
{
public:
    string tname, des,sou;
    int pnr,n;
    int* seat = new int[n];//Dynamic allocation of memory

    int detail()
    {
        cout << "Enter Train name: " << endl;
        getline(cin >> ws, tname);
        cout << "\nEnter number of seat available:  " << endl;
        cin >> n;
        cout << "\nEnter PNR: " << endl;
        cin >> pnr;
        cout << "\nCities: \n1.Mumbai\n2.Surat\n3.Nashik\n4.Pune" << endl;
        cout << "\nEnter the Source: " << endl;
        getline(cin >> ws, sou);
        cout << "\nEnter the destination: " << endl;
        getline(cin >> ws, des);

        return 0;
    }

    int way()
    {
        route r;
        r.read();

        return 0;
    }
};

class passenger
{

 string id, add;
 int no,i;

public:
    int np;
    string name[10];
    char* g = new char[np];//Dynamic allocation of memory
    int* age = new int[np];//Dynamic allocation of memory
    int input()
    {
        cout << "Enter number of passengers: " << endl;
        cin >> np;
        for ( i = 0; i < np; i++)
        {
           cout << "\nEnter passenger's name:  " << endl;
           getline(cin>>ws, name[i]);
            cout << "\nEnter passenger's Gender: (M/F/O(other)) " << endl;
            cin >> g[i];
            cout << "\nEnter passenger's Age: " << endl;
            cin >> age[i];
        }

        cout << "\nEnter passenger's e-mail id: " << endl;
        getline(cin >> ws, id);
        cout << "\nEnter passenger's Address: " << endl;
        getline(cin >> ws, add);
        cout << "\nEnter passenger's phone number: " << endl;
        cin >> no;
        
        return 0;
    }

};

class ticket : public passenger,public train, public route //Multiple Inheritance 
{
    int i;    

public:
    int book()
    {
        for (i = 0;i < np;i++)
        {
            cout << "\nPassenger name: " << name[i]<<endl;
            cout << "Passenger's age: " << age[i] << endl;
            cout << "Passenger's Gender: " << g[i] << endl;
            seat[i] = i + 1;
            cout << "Seat No:" << seat[i] << endl;
        }

        cout << "\nTrain name: " << tname<< endl;
        cout << "PNR no: " << pnr << endl;
        cout << "Source: " << sou<<endl;
        cout << "Destination: " << des << endl;
  
        cout << "Total amount : Rs." << (amount()*np) << endl;
        cout << "\n";
        return 0;
    }

    int cancel()
    {
        int cseat;
        cout << "Train name: " << tname << endl;
        cout << "PNR no: " << pnr << endl;
        cout << "Source: " << sou << endl;
        cout << "Destination: " << des << endl;
        cout << "No of seats to be cancelled:" << endl;
        cin>> cseat;

       for (i = 0; i < cseat; i++)
        {
           cout << "\nPassenger name: "<<name[i]<<endl;
           cout << "Passenger age:" << age[i] << endl;
           cout << "Seat No: " << seat[i] << endl;
        }
       cout << "Amount returned: Rs" << (amount() * cseat) << endl;
       cout << "\n";
       return 0;
    }
};

int main()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout << ".......WELCOME TO RAILWAY RESERVATION SYSTEM.........." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    ticket t;

    cout << "\n*******TRAIN DETAILS********\n" << endl;
   t.detail();
   t.way();

   cout << "Press 1 to continue: " << endl;
   int n;
   cin >> n;
   if (n == 1)
       system("CLS");
   else
       goto exit;

  cout << "\n*******PASSENGER DETAILS********\n" << endl;
   t.input();

   cout << "Press 1 to continue: " << endl;
   cin >> n;
   if (n == 1)
       system("CLS");
   else
       goto exit;

   cout << "\n*******BOOKING DETAILS********\n" << endl;
   t.book();

   cout << "Press 1 to continue: " << endl;
   cin >> n;
   if (n == 1)
       system("CLS");
   else
       goto exit;

 char ch;
 cout << "Do you want to cancel tickets. \nPress Y for yes and N for no. " << endl;
 cin >> ch;

 if (ch == 'Y')
 {
     cout << "\n*******CANCELLATION DETAILS********\n" << endl;
     t.cancel();
 }
 else
     goto exit;

exit:
 cout << "Exited the System." << endl;

    
    return 0;
} 

