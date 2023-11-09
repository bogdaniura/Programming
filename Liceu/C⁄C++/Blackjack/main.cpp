#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> deck;

void generate_deck() //generam pachetele de carti
{
   for (int i = 1; i <= 5; i++) //pentru 5 pachete de carti
   {
      for (int j = 1; j <= 4; j++) //pentru fiecare simbol
      {
         for (int k = 1; k <= 13; k++) //pentru fiecare numar
         {
            deck.push_back(k); //adaugam un element in vectorul deck
         }
      }
   }
}

void shuffle_deck() //amestecam pachetele(elementele vectorului deck)
{
   random_shuffle(deck.begin(), deck.end());
}

void print_deck() //afisam pachetele(afisam continutul vectorului deck)
{
   for (int i = 0; i <= deck.size(); i++)
   {
      cout << deck[i] << ' ';
   }
}

void place_bet(int &bet)
{
   cout << "Place a bet: "; //plasam un pariu
   cin >> bet;
}

int points(int player){
   int p = 0;
   for(int i = 1;i <= 5;i++){
      p += v[player][i];
   }
   return p;
}
int v[3][6];
int main()
{
   bool pierdut = false, castigat = false;
   int money = 150, profit = 0;
   char actioncq, actionds;
   // srand(time(NULL));
   generate_deck();
   shuffle_deck();
   do
   {
      do
      {
         int bet = 0;
         place_bet(bet);
         while (bet > money) //nu continuam pana cand pariul nu este mai mic sau egal decat suma de bani disponibila
         {
            cout << "Your bet is bigger than the amount of money you have, please place a smaller bet";
            place_bet(bet);
         }
         v[1][1] = deck.back(); //impartim cate doua carti la dealer si la player
         deck.pop_back();
         v[2][1] = deck.back();
         deck.pop_back();
         v[1][2] = deck.back();
         deck.pop_back();
         v[2][2] = deck.back();
         deck.pop_back();
         cout << "Dealer's cards: " << v[1][1] << " | X\n"
              << "Your cards: " << v[2][1] << " | " << v[2][2] << "\n";
         cout << "(d)raw a card or (s)tay: ";
         cin >> actionds;
         while (actionds == 'd' && points(2) <= 21) //cat timp jucatorul continua si are mai putin de 15 punte
         {
            //de continuat
         }
         while (points(1) < 15) //cat timp dealerul are mai putin de 15 punte
         {
            //de continuat
         }

      } while (not pierdut && not castigat);            //cat timp runda nu s-a incheiat
      cout << "Your balance: " << money << '$\n'        //afisam suma de bani de care jucatorul dispune
           << "You can (c)ontinue or you can (q)uit: "; //ii dam optiunea de a continua sau de a se retrage
      cin >> actioncq;
      system("clear");
   } while (actioncq == 'c' && money > 0);
   if (actioncq == 'q')
   {
      profit = money - 150;
      cout << "Game Over!\n"
           << "Your profit is: " << profit << '$'; //afisam profitul
      money = 0;                                   //incheiem jocul
   }
   else
   {
      cout << "You don't have any more money!";
   }

   // system("clear");
   return 0;
}