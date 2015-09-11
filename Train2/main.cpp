#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <cmath>

using namespace std;
#include "car.h"

int numCities;
int n = numCities;


int main()
{
   srand((unsigned)time(NULL));
   int random_integer = rand();
   int Cities[n];

   cout << "Input Number of Cities" <<endl; //inputs amount of cities
   cin >> numCities;
   cout << endl;

   for (int i = 0; i<numCities; i++) //creates distance of cars
   {
       //if statements to correctly calculate distances
       random_integer = (rand()%10)+1;
       if (i == 0)
       {
           Cities[i] = 0;



       }
       else if (i == 1)
       {
           Cities[i] = random_integer;
       }
       else
       {
       Cities[i] = random_integer;
       Cities[i] = Cities[i-1]+ Cities[i];
       }
        //cout << "City " << i << "distance equals " << Cities[i];
        //cout << endl;
   }
     //output distances between cities
    for (int i = 1; i<numCities; i++)
   {
       if (i == 0)
       {
           cout << "Start At City " << i << endl;
       }

       else
       {
           cout << "City "<< i-1 << " to City " << i
                << " ,time to travel "<< Cities[i] - Cities[i-1]<<endl;
       }

   }
//creates a list called train
 int nt,nc;
 car * cptr;
 car * tptr;

 list<car>train;
 list<car>train2;
 list<car>::iterator sitr;
 list<car>::iterator titr;

 cout << endl;
 random_integer = (rand()%10)+1;
 nc = random_integer;


 //num of cars
//creates the cars within the train list
 for(int j = 1; j<=nc; j++)
{
  random_integer = (rand()%numCities-1)+1;
  cptr= new car(Cities[random_integer], j);
  train.push_back(*cptr);
}


//train takes off.
cout << "Train" << endl;
sitr= train.begin();
while(sitr!=train.end())
{
    sitr->display(); sitr++;
    }


 random_integer = (rand()%10)+1;
 nt = random_integer;
 random_integer = (rand()%Cities[numCities-1]+1);
 int half = random_integer;

 for(int k = 1; k<=nt; k++)
 {
  random_integer = (rand()%numCities-1)+1;
  tptr= new car (Cities[random_integer],k);
  train2.push_back(*tptr);
 }

cout << endl;
cout << "Train 2" << endl;
titr= train2.begin();
while(titr!=train2.end())
{
    titr->display(); titr++;
}

    cout << endl;
    cout << "Train 1 Travel Log" << endl;

    for (int T=0; T<=Cities[numCities-1]; T++)//calculates units.
    {
        cout << endl;
        cout << "T= " << T << endl;
       for (int m = 0; m<numCities; m++)
        {

            if (T == Cities[m])//determines if you're at a city
            {
                cout << "Train arrives at City "<< m << endl;
            }
            int carl = nc;
            sitr= train.begin();
            while(sitr!=train.end())
            {
                //determines if the car exits
                if (sitr->getdes() == 0)
                {
                cout << "Car "<< sitr->getid() << " stays."<< endl;
                sitr = train.erase (sitr);
                sitr++;
                carl--;
                }
                else if (sitr->getdes() == T)
                {
                cout << "Car "<< sitr->getid() << " exits"<< endl;
                sitr = train.erase (sitr);
                sitr++;
                carl--;

                }
                else
                {
                 sitr++;
                }

            }


            }
            //determines if the cars continue or if there are any.
            sitr=train.begin();
            if (sitr != train.end())
            {
            cout << "Cars ";
             while(sitr!=train.end())
            {
                cout << sitr->getid() << " ";
                sitr++;
            }
            cout << "continues";
            }
            else
            {
                cout <<"no cars left"<<endl;
            }
            if(T == half)
            {
                cout << endl;
                cout << "Trains 1 and 2 pass each other." <<endl;
            }
            if (T != Cities[numCities-1])
            {
                cout << endl;
                cout << "Preceeding to Next Unit";
                cout << endl;
            }
            else
            {
                cout << endl;
                cout << "Train 1 Stops" << endl;
            }
            }
            cout << endl;

    cout << "Train 2 Travel Log " << endl;



   for (int S=Cities[numCities-1]; S>=0; S--)//calculates units.
    {
        cout << endl;
        cout << "S= " << S << endl;
       for (int n = 0; n<numCities; n++)
        {

            if (S == Cities[n])//determines if you're at a city
            {
                cout << "Train 2 arrives at City "<< n << endl;
            }
            int carl = nc;
            titr= train2.begin();
            while(titr!=train2.end())
            {
                //determines if the car exits
                if (titr->getdes() == Cities[numCities-1])
                {
                cout << "Car "<< titr->getid() << " stays."<< endl;
                titr = train2.erase (titr);
                titr++;
                carl--;
                }
                else if (titr->getdes() == S)
                {
                cout << "Car "<< titr->getid() << " exits"<< endl;
                titr = train2.erase (titr);
                titr++;
                carl--;

                }
                else
                {
                 titr++;
                }

            }


            }
            //determines if the cars continue or if there are any.
            titr=train2.begin();
            if (titr != train2.end())
            {
            cout << "Cars ";
             while(titr!=train2.end())
            {
                cout << titr->getid() << " ";
                titr++;
            }
            cout << "continues";
            }
            else
            {
                cout <<"no cars left"<<endl;
            }
            if (S == half)
            {
             cout << endl;
             cout << "Trains 1 and 2 pass each other" << endl;
            }
            if (S != 0)
            {
                cout << endl;
                cout << "Preceeding to Next Unit";
                cout << endl;
            }
            else
            {
                cout << endl;
                cout << "Train 2 Stops" << endl;
            }

            }


    system("pause");
    return 0;

}
