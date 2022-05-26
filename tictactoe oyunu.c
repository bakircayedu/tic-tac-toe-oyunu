#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char zemin[3][3];
const char OYUNCU1 = 'X';
const char OYUNCU2= 'O';

void Sifirla();
void Basla();
int bosYerler();
void oyuncuhamle1();
void oyuncuhamle2();
void pchamle();
char kazanankontrol();
void galip(char);




int main()
{
    char kazanan = ' ';
    Sifirla();

    while(kazanan == ' ' && bosYerler() !=0){
     Basla();

     oyuncuhamle1();
     kazanan = kazanankontrol();
     if(kazanan != ' ' || bosYerler() == 0)
     {
         break;
     }
     Basla();
     oyuncuhamle2();
     kazanan = kazanankontrol();
     if(kazanan != ' ' || bosYerler() == 0)
     {
         break;
     }
    }

    Basla();
    galip(kazanan);
    return 0;
}

void Sifirla()
{
   for(int i =0; i<3;i++){
        for(int j =0; j<3;j++){
            zemin[i][j]=' ';
        }
   }
}
void Basla()
{
    printf(" %c | %c | %c ",zemin[0][0],zemin[0][1],zemin[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",zemin[1][0],zemin[1][1],zemin[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",zemin[2][0],zemin[2][1],zemin[2][2]);
    printf("\n");

}
int bosYerler()
{
   int boskutu = 9;

   for(int i=0; i<3; i++)
   {
     for(int j=0; j<3; j++)
   {
       if(zemin[i][j] !=' ')
       {
           boskutu--;
       }
   }
   }
   return boskutu;
}

void oyuncuhamle1()
{
   int x;
   int y;

   do{
   printf("1. Oyuncu : Hangi Satir #(1-3): ");
   scanf("%d", &x);
   x--;
   printf("1. Oyuncu : Hangi Sutun #(1-3): ");
   scanf("%d", &y);
   y--;

   if(zemin[x][y] != ' ')
   {
       printf("Gecersiz Hamle\n");
   }
   else{
       zemin[x][y] = OYUNCU1;
       break;
   }
   } while (zemin[x][y] != ' ');

}

void oyuncuhamle2()
{
   int x;
   int y;

   do{
   printf("2. Oyuncu : Hangi Satir #(1-3): ");
   scanf("%d", &x);
   x--;
   printf("2. Oyuncu : Hangi Sutun #(1-3): ");
   scanf("%d", &y);
   y--;

   if(zemin[x][y] != ' ')
   {
       printf("Gecersiz Hamle\n");
   }
   else{
       zemin[x][y] = OYUNCU2;
       break;
   }
   } while (zemin[x][y] != ' ');
}
char kazanankontrol()
{
    for(int i=0; i<3;i++)
    {
        if(zemin[i][0] == zemin[i][1] && zemin[i][0] == zemin[i][2] )
        {
            return zemin[i][0];
        }
    }
    for(int i=0; i<3;i++)
    {
        if(zemin[0][i] == zemin[1][i] && zemin[0][i] == zemin[2][i] )
        {
            return zemin[0][i];
        }
    }

        if(zemin[0][0] == zemin[1][1] && zemin[0][0] == zemin[2][2] )
        {
            return zemin[0][0];
        }
        if(zemin[0][2] == zemin[1][1] && zemin[0][2] == zemin[2][0] )
        {
            return zemin[0][2];
        }
    return ' ';
}
void galip (char kazanan)
{
    if(kazanan == OYUNCU1)
    {
        printf("1.Oyuncu KAZANDI");
    }
    else if(kazanan == OYUNCU2)
    {
        printf("2.Oyuncu KAZANDI");
    }
    else
    {
        printf("BERABERLIK");
    }
}

