#include<iostream>
#include <cstdlib>
#include<fstream>
using namespace std;
class cms
{
 int    frame[50], frame1[50][2], pn[50], n, cnt, p, fs;
public:
 cms();
 void init();
 void getdata();
 void fifo();
 void lru();
};
cms::cms()
{
 int i;
 for (i = 0; i < fs; i++)
 {
  frame[i] = -1;
 }
 for (i = 0; i < fs; i++)
 {
  frame1[i][0] = -1;
  frame1[i][1] = 0;
 }
 p = 0;
 cnt = 0;
}
void cms::init()
{
 int i;
 for (i = 0; i < fs; i++)
 {
  frame[i] = -1;
 }
 for (i = 0; i < fs; i++)
 {
  frame1[i][0] = -1;
  frame1[i][1] = 0;
 }
 p = 0;
 cnt = 0;
}
void cms::getdata()
{
 cout << "\nEnter the number of possible addresses : ";
 cin >> n;
 cout << "\nEnter frame size : ";
 cin >> fs;
 cout << "\nEnter the address units : ";
 for (int i = 0; i < n; i++)
 {
  cin >> pn[i];
 }
}

void cms::fifo()
{
 init();
 int pi = 0, ind = 0, fault = 0, i, j, k, fn;
 p = 0;
 cnt = 0;
cout << "\nFIFO Replacement Policy\n";
cout << "Addresses" << "\t\t\t\t" << "Hits" << endl;
cout << "------------------------------------------" << endl;
 for (i = 0; i < n; i++)
 {
  j = 0;
  if (ind > fs - 1)
   ind = 0;
  fault = 1;
  while (j < fs)
  {
   if (frame[j] == pn[pi])
   {
    fault = 0;
    goto l1;
   }
   fn = ind;
   j++;
  }
  j = 0;
  while (j < fs)
  {
   if (frame[j] == -1)
   {
    fault = 1;
    fn = j;
    goto l1;
   }
   j++;
  }
  ind++;
l1:
  if (fault == 1)
  {
   frame[fn] = pn[pi];
   cnt++;
  }
  cout << "\nAddress " <<pn[pi] << "-->";
  pi++;
  for (k = 0; k < fs; k++)
  {
   cout << "\t" << frame[k];
  }
  if (fault == 1)
   cout << "\t";
  else
   cout << "\t*";
 }
 cout << "\n\nTotal number of address units : " << n;
 cout << "\nTotal number of hits : " << n-cnt;
 float hit_ratio = (float)(n-cnt)/(float) n;
 cout << "\nHit ratio : " << hit_ratio << endl;

   ofstream theFile("output.txt");
    theFile << "\nAddress " << pn[pi] << "-->";
    pi++;
   for (k = 0; k < fs; k++){
    theFile << "\t" << frame1[k];
   }
  if (fault == 1)
   cout << "\t";
  else
   cout << "\t*";
   theFile << "\n\nTotal number of address units : " << n;
    theFile << "\nTotal number of hits : " << n-cnt;
    theFile << "\nHit ratio : " << hit_ratio << endl;
 theFile.close();
}

void cms::lru()
{
 init();
 int ind = 0, fault = 0, pi = 0, i, j, fn, k;
 p = 0;
 cnt = 0;

 int min;
 for (i = 0; i < fs; i++)
 {
  frame1[i][0] = -1;
  frame1[i][1] = 0;
 }
 pi = 0;

cout << "\nLRU Replacement Policy\n";
cout << "Addresses" << "\t\t\t\t" << "Hits" << endl;
cout << "------------------------------------------" << endl;
 for (i = 0; i < n; i++)
 {
  j = 0;
  if (ind > fs - 1)
   ind = 0;
  fault = 1;
  min = 999;
  while (j < fs)
  {
   if (frame1[j][0] == pn[pi])
   {
    fault = 0;
    p++;
    frame1[j][1] = p;
    goto l2;
   }
   if (frame1[j][1] < min)
   {
    min = frame1[j][1];
    fn = j;
   }
   j++;
  }
  j = 0;
  while (j < fs)
  {
   if (frame1[j][0] == -1)
   {
    fault = 1;
    fn = j;
    goto l2;
   }
   j++;
  }
  ind++;
l2:
  if (fault == 1)
  {
   p++;
   frame1[fn][0] = pn[pi];
   frame1[fn][1] = p;
   cnt++;
  }

  cout << "\nAddress " << pn[pi] << "-->";
  pi++;
  for (k = 0; k < fs; k++)
  {
   cout << "\t" << frame1[k][0];
  }
  if (fault == 1)
   cout << "\t";
  else
   cout << "\t*";
 }
 cout << "\n\nTotal number of address units : " << n;
 cout << "\nTotal number of hits : " << n-cnt;
 float hit_ratio = (float)(n-cnt)/(float) n;
 cout << "\nHit ratio : " << hit_ratio << endl;

 ofstream theFile("output.txt");
    theFile << "\nAddress " << pn[pi] << "-->";
    pi++;
   for (k = 0; k < fs; k++){
    theFile << "\t" << frame1[k][0];
   }
  if (fault == 1)
   cout << "\t";
  else
   cout << "\t*";
   theFile << "\n\nTotal number of address units : " << n;
    theFile << "\nTotal number of hits : " << n-cnt;
    theFile << "\nHit ratio : " << hit_ratio << endl;
 theFile.close();
 }



int main()
{
 cms p;
 int  j, fault = 0, i, pi, k, fn, ind = 0, ans, ch;

 cout << "\n|*************** CACHE MEMORY SIMULATOR ***************|";
 cout << "\n|\t\t  created by Cedric Ng                 |\n";
 cout << "********************************************************\n";

 cout << "\n--------------------- MAIN MENU ------------------------";
 cout << endl;
 p.getdata();

 do
 {
  cout << "\n|*******CHOOSE THE REPLACEMENT POLICY********|";
  cout << "\n|                                            |";
  cout << "\n|    1. FIFO Algorithm                       |";
  cout << "\n|    2. LRU Algorithm                        |";
  cout << "\n|    3. Exit                                 |";
  cout << "\n|                                            |";
  cout << "\n|********************************************|";
  cout << "\n\n Enter your choice: ";
  cin >> ch;
  switch (ch)
  {
  case 1:
   p.fifo();
   break;
  case 2:
   p.lru();
   break;
  case 3:
   return 0;
  default:
   cout << "\nInvalid choice!!!";
  }
  cout << "\nDo you want to continue?(Type 1 = yes/0 = no) : ";
  cin >> ans;
 }

 while (ans == 1);
 return 1;
}
