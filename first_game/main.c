#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include <windows.h>

#define MAX_WIDTH 10
#define MAX_HEIGHT 10
main(){
	srand(time(NULL));
	int Max=10, min=1, choice, choice1, choiceForConfig=2;
    //pourcentage de vie
	int LI=100;
	//Coordonnées du personnage
	int X=0; //ligne
	int Y=0; //colonne
    //coordonnées de la bombe
	int Bx=rand()%(Max-min)+1;//ligne
	int By=rand()%(Max-min)+1;//colonne
    //coordonnées du tresor
	int x=rand()%(Max-min)+1;
	int y=rand()%(Max-min)+1;

	float distance0=sqrt(pow(X-x,2)+pow(Y-y,2)), distance1;
	//mouvement up ou down...
	char mvt;
	int mvt2;
	int TIME=0;
	//coordonnées de potion
	int Xh=rand()%(Max-min)+1, Yh=rand()%(Max-min)+1;

	system("mode 145,30");
    enteteJeux();
do{
	 menu();
	 scanf("%d", &choice);
	 printf("\tYour Choice:%d\n", choice);
  switch (choice){
     case 1:
      do{
	system("cls");
		printf("LifeIndex=%d%%\n %d %d |%d %d\n", LI, X,Y, x,y);
		if(X==0 &&Y==0 && TIME==0){
			printf("FIND THE TREASURE!!\n");
		}else if(X==Xh && Y==Yh){
			if(LI<=90){
		printf("You have been healed!\n");
		LI+=10;
		Xh=rand()%(Max-min)+1, Yh=rand()%(Max-min)+1;
			}else{printf("You found a healing potion, but your Life Index is high enough\n");
			Xh=rand()%(Max-min)+1, Yh=rand()%(Max-min)+1;
			}
		}else if(X==Bx &&Y==By){
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("Ouch! A BOMB!! Be More careful next time!\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			LI=LI-20;
			Bx=rand()%(Max-min)+1, By=rand()%(Max-min)+1;
			TIME+=1;
		}else{
			if(distance0 < distance1){
				printf("You're getting closer!\n");
				TIME+=1;
			}else{
				printf("Watch out you're getting far!\n");
				TIME+=1;
				}
			}

		afficherNbrVie(LI);
		printf("\n");
		afficheTab(X, Y);
		distance1=distance0;
		mvt=getch();
		if(mvt=='q' || mvt=='Q'){if(Y>0){Y--;LI--;}}
		else if(mvt=='d' || mvt=='D'){if(Y<MAX_HEIGHT){Y++;LI--;}}
		else if(mvt=='z' || mvt=='Z'){if(X>0){X--;LI--;}}
		else if(mvt=='s' || mvt=='S'){if(X<MAX_WIDTH){X++;LI--;}}
		distance0=sqrt(pow(X-x,2)+pow(Y-y,2));
}while((X!=x || Y!=y)&& (LI>0));
	system("cls");
	if(LI<=0){
	gameOver();
	}else{
		congratulations();
		}

 	do{
		printf("\nRestart?\n\n");
		printf("1-Yes\n");
		printf("2-No\n");
		scanf("%d", &choice1);
		printf("Your Choice:%d\n\n", choice1);
		int x=rand()%(Max-min)+1;
		int y=rand()%(Max-min)+1;
      switch (choice1)
      {
     case 1:
	    LI=100;X=0;Y=0; TIME=0;
  	do{
	system("cls");
		printf("LifeIndex=%d%%\n %d %d |%d %d \n", LI, X,Y, x,y);
		if(X==0 &&Y==0 && TIME==0){
			printf("FIND THE TREASURE!!\n");
		}else if(X==Xh && Y==Yh){
			if(LI<=90){
		printf("You have been healed!\n");
		LI+=10;
		Xh=rand()%(Max-min)+1, Yh=rand()%(Max-min)+1;
			}else{printf("You found a healing potion, but your Life Index is high enough\n");
			Xh=rand()%(Max-min)+1, Yh=rand()%(Max-min)+1;
			TIME+=1;
			}
		}else if(X==Bx &&Y==By){
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("Ouch! A BOMB!! Be More careful next time!\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			LI=LI-20;
			Bx=rand()%(Max-min)+1, By=rand()%(Max-min)+1;
			TIME+=1;
		}else{
			if(distance0 < distance1){
				printf("You're getting closer!\n");
				TIME+=1;
			}else{
				printf("Watch out you're getting far!\n");
				TIME+=1;
				}
			}
	 	afficherNbrVie(LI);
		printf("\n");
        afficheTab(X, Y);
		distance1=distance0;
		mvt=getch();

		if(mvt=='q' || mvt=='Q'){if(Y>0){Y--;LI--;}}
		else if(mvt=='d' || mvt=='D'){if(Y<MAX_HEIGHT){Y++;LI--;}}
		else if(mvt=='z' || mvt=='Z'){if(X>0){X--;LI--;}}
		else if(mvt=='s' || mvt=='S'){if(X<MAX_WIDTH){X++;LI--;}}

		distance0=sqrt(pow(X-x,2)+pow(Y-y,2));
}while((X!=x || Y!=y)&& (LI!=0));
	system("cls");
	if(LI==0){gameOver();}

	else{congratulations();}
   break;
  case 2:
  	system("cls");
   printf("Good Luck next time!!\n");
   break;
 }
		}while(choice1!=2);
		return 1;
;
          break;
     case 2:
     	printf("\nYou need to find the hidden treasure somewhere in the platform, move using:\n\t'z' button to go up\n\t's' button to go down\n\t'q' button to go to the left\n\t'd button togo to the right\n but careful, there are mines everywhere in the plateform and they may cost you a precious 20%%!\n\t\t\t\t\t GOOD LUCK!\n");
          break;
     case 3:
     	system("cls");
	 printf("Goodbye\n");
          break;
     default:
     	system("cls");
	printf("Wrong Choice. Enter again\n");
          break;
 }
} while (choice != 3);

}
void enteteJeux(){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
printf(R"EOF(
 /$$$$$$$$                                                      /$$$$$$$              /$$                           /$$
|__  $$__/                                                     | $$__  $$            | $$                          | $$
   | $$  /$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$       | $$  \ $$  /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$
   | $$ /$$__  $$ /$$__  $$ /$$_____/ /$$__  $$ /$$__  $$      | $$  | $$ /$$__  $$|_  $$_/   /$$__  $$ /$$_____/|_  $$_/   /$$__  $$ /$$__  $$
   | $$| $$  \__/| $$$$$$$$|  $$$$$$ | $$  \ $$| $$  \__/      | $$  | $$| $$$$$$$$  | $$    | $$$$$$$$| $$        | $$    | $$  \ $$| $$  \__/
   | $$| $$      | $$_____/ \____  $$| $$  | $$| $$            | $$  | $$| $$_____/  | $$ /$$| $$_____/| $$        | $$ /$$| $$  | $$| $$
   | $$| $$      |  $$$$$$$ /$$$$$$$/|  $$$$$$/| $$            | $$$$$$$/|  $$$$$$$  |  $$$$/|  $$$$$$$|  $$$$$$$  |  $$$$/|  $$$$$$/| $$
   |__/|__/       \_______/|_______/  \______/ |__/            |_______/  \_______/   \___/   \_______/ \_______/   \___/   \______/ |__/

                                                                                                 By : HATIM Hafsa & Manal HAGGOUD

)EOF");
printf("\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
}

void initiation_taille_de_console(){
               HANDLE hOut;
               SMALL_RECT DisplayArea = {0, 0, 160, 50};
               int x = 0, y = 0;
               COORD NewSBSize = {500, 500};

               hOut = GetStdHandle(STD_OUTPUT_HANDLE);

               SetConsoleScreenBufferSize(hOut,NewSBSize);
               SetConsoleWindowInfo(hOut,TRUE,&DisplayArea);
}

void menu(){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf(R"EOF(
                                                    __  __ _____ _   _ _   _
                                                   |  \/  | ____| \ | | | | |
                                                   | |\/| |  _| |  \| | | | |
                                                   | |  | | |___| |\  | |_| |
                                                   |_|  |_|_____|_| \_|\___/

)EOF");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
    printf("\n\n");
    printf("                                                    1. Start\n");
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	 printf("                                                    2. Instructions\n");
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	 printf("                                                    3. Exit\n");
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
}

void afficheSeparateur(int n) {
  int i;

  for (i = 0; i < n; i++)
    printf("+---");
  puts("+");
}

void afficheTab(int X, int Y) {
  int i, j;
  printf("\n");
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
  for (i = 0; i < 11; i++) {
    afficheSeparateur(11);
    for (j = 0; j < 11; j++) {
      if(X==i && Y==j){
        printf("|");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        printf("%3c",1);
       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
      }
      else{
        printf("|   ");
      }
    }
    puts("|");
  }
  afficheSeparateur(11);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
}
void afficherNbrVie(int nbrVie){
    int i;
    for(i=0; i<=nbrVie/20; i++){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf("%c", 3);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
    }
}

void gameOver(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf(R"EOF(
  _______  _______  __   __  _______    _______  __   __  _______  ______
 |       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |
 |    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||
 |   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_
 |   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |
 |   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |
 |_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|
    )EOF");
    printf("\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
}

void congratulations(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf(R"EOF(
   ____   U  ___ u  _   _     ____     ____        _       _____    _   _    _         _       _____             U  ___ u  _   _    ____
U /"___|   \/"_ \/ | \ |"| U /"___|uU |  _"\ u U  /"\  u  |_ " _|U |"|u| |  |"|    U  /"\  u  |_ " _|     ___     \/"_ \/ | \ |"|  / __"| u
\| | u     | | | |<|  \| |>\| |  _ / \| |_) |/  \/ _ \/     | |   \| |\| |U | | u   \/ _ \/     | |      |_"_|    | | | |<|  \| |><\___ \/
 | |/__.-,_| |_| |U| |\  |u | |_| |   |  _ <    / ___ \    /| |\   | |_| | \| |/__  / ___ \    /| |\      | | .-,_| |_| |U| |\  |u u___) |
  \____|\_)-\___/  |_| \_|   \____|   |_| \_\  /_/   \_\  u |_|U  <<\___/   |_____|/_/   \_\  u |_|U    U/| |\u\_)-\___/  |_| \_|  |____/>>
 _// \\      \\    ||   \\,-._)(|_    //   \\_  \\    >>  _// \\_(__) )(    //  \\  \\    >>  _// \\_.-,_|___|_,-.  \\    ||   \\,-.)(  (__)
(__)(__)    (__)   (_")  (_/(__)__)  (__)  (__)(__)  (__)(__) (__)   (__)  (_")("_)(__)  (__)(__) (__)\_)-' '-(_/  (__)   (_")  (_/(__)

      __  __            ___                  __  __  __         __                                ____
      \ \/ /__  __ __  / _/__  __ _____  ___/ / / /_/ /  ___   / /________ ___ ____ __ _________ / / /
       \  / _ \/ // / / _/ _ \/ // / _ \/ _  / / __/ _ \/ -_) / __/ __/ -_) _ `(_-</ // / __/ -_)_/_/
       /_/\___/\_,_/ /_/ \___/\_,_/_//_/\_,_/  \__/_//_/\__/  \__/_/  \__/\_,_/___/\_,_/_/  \__(_|_)

    )EOF");
    printf("\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
}
