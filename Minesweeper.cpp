//============================================================================
// Name        : Minesweeper.cpp
// Author      : SDS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main ()
{
    int n,m;
    int count=0;
   while(true)
   {
       cin >> m >> n;
       if (n ==0 && m ==0) break;
       count++;
       if (count > 1) cout << '\n';
       int str[102][102] = {0};
      for (int i=1; i<m+1; i++)
          for (int j=1; j<n+1; j++)
          {
              char temp;
              cin >> temp;
              if (temp == '*')
                  {

                      str[i][j] = -1;
                      if (str[i-1][j] != -1) str[i-1][j]++;
                      if (str[i-1][j-1] != -1) str[i-1][j-1]++;
                       if (str[i-1][j+1] != -1) str[i-1][j+1]++;
                      if (str[i][j-1] != -1) str[i][j-1]++;
                      if (str[i+1][j] != -1) str[i+1][j]++;
                      if (str[i+1][j+1] != -1) str[i+1][j+1]++;
                      if (str[i+1][j-1] != -1) str[i+1][j-1]++;
                      if (str[i][j+1] != -1) str[i][j+1]++;
                  }
          }

           cout << "Field #" << count << ":\n";
            for (int i=1; i<m+1; i++)
           {

                for (int j=1; j<n+1; j++)
                    {
                        if (str[i][j] == -1) cout << '*';
                        else cout << str[i][j];
                }
                cout << "\n";
           }

   }

    return 0;
}
