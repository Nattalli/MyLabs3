#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    char array;
    ifstream fin("text.txt");

    int s = 0;//summaring worlds which are longer than 4
    int k = 0;//счетчик кол-ва букв
char arra[10000];
int r = 0;
    //считаем кол-во слов, у которых букв меньше чем 4
    while(fin.get(array))
    { //cout<<array<<"int:"<<(int)array<<'\n';
        if((int)array != 32  && (int)array != 10)
        {arra[r] = array;
        r++;
        k++;}
        if((int)array == 32)
        {   arra[r]=' ';
        r++;
            if(k<4)s++;
            k=0;
        }
        if((int)array == 10)
        {
            arra[r]='.';
            arra[r+1] = ' ';
            r=r+2;
        }
    }
    fin.close();
    cout<<arra;

 //создаем новый массив, без слов, длинна которых меньше 4
 int p = 0;
 int t = 0;
 int w = 0;
 char new_Arr[r];
 for ( int i = 0; i <= r ; ++i)
 {
     if (arra[i] != ' ') p++;
     else
        { if( p >= 4 )
            { int f = i - p - 1;
            for (int y = t ; y <= t + p; ++y)
                {
                    new_Arr [y] = arra[f] ;
                    f++;
                    w++;
                };
              t=t+p+1;
            }
          p = 0;
        };
 }
    new_Arr[w]='\0';

//выводим новые значения в файл
ofstream new_f;
new_f.open("new_text.txt");
for(int i = 0 ;i<=w; ++i)
new_f<<new_Arr[i];
new_f<<endl<<"The number of deleted worlds = "<<s;
new_f.close();

    return 0;
}
