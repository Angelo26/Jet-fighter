			  //Made by : Angel Maden
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>

FILE *fc,*ft,*fp;
char cfile[10]="story.txt";
char tfile[10]="time.txt";
char pfile[10]="target.txt";

int score;
char name[20];

void front();
void menu();
void start();
void story();
void timech();
void target();
void cscoring();
void tscoring();
void pscoring();
void highscore();
void help();
void about();

void main()
{
	front();
	menu();
	getch();
}
void front()
{
	int gdriver = DETECT,gmode;
	int x,y,i;
	initgraph(&gdriver,&gmode,"..\\BGI");
	x=getmaxx()/2;
	y=getmaxy()/2;

	delay(1000);
	setcolor(LIGHTBLUE);
	settextstyle(8,0,4);
	outtextxy(x-170,y-50,"MADE in Turbo c++");

	delay(2500);
	cleardevice();
	setcolor(LIGHTCYAN);
	settextstyle(10,0,2);
	outtextxy(x-190,y-80,"The Next World Coding");
	settextstyle(10,0,3);
	outtextxy(x-90,y,"presents");

	delay(3000);
	cleardevice();
	setcolor(LIGHTRED);
	settextstyle(5,0,5);
	outtextxy(x-190,y-50,"A game by ANgEL");

	delay(3000);
	cleardevice();
	setcolor(LIGHTGRAY);
	settextstyle(4,0,5);
	outtextxy(x-100,y-130,"A l i E N");
	setcolor(LIGHTCYAN);
	settextstyle(8,0,5);
	outtextxy(x-105,y-30,"INVASION");


		//HERO
	setcolor(LIGHTBLUE);
	line(x-182,y+130,x-165,y+138);
	line(x-182,y+146,x-165,y+138);
	line(x-188,y+133,x-165,y+138);
	line(x-188,y+143,x-165,y+138);
	line(x-190,y+131,x-170,y+132);
	line(x-190,y+145,x-170,y+144);
	line(x-200,y+126,x-180,y+134);
	line(x-200,y+150,x-180,y+142);
	line(x-200,y+126,x-196,y+133);
	line(x-200,y+150,x-196,y+141);
	line(x-200,y+126,x-185,y+138);
	line(x-200,y+150,x-185,y+138);

		//ALIEN
	setcolor(LIGHTRED);
	line(x+190,y+130,x+175,y+138);
	line(x+190,y+146,x+175,y+138);
	arc(x+178,y+146,0,125,12);
	arc(x+178,y+130,230,360,12);
	arc(x+186,y+142,0,90,14);
	arc(x+186,y+134,270,360,14);
	ellipse(x+188,y+138,0,360,6,2);

	setcolor(YELLOW);
	ellipse(x-200,y+138,0,360,5,2);      //       H
	ellipse(x+204,y+138,0,360,5,2);      //       A
	setcolor(RED);
	ellipse(x-198,y+138,0,360,6,4);      //       H
	ellipse(x+202,y+138,0,360,6,4);      //       A
	for(i=0;i<=162;i++)        //loading
	{
		delay(20);
		settextstyle(0,0,0);
		setcolor(LIGHTBLUE);
		outtextxy(x-163+i,y+135,"-");
		setcolor(LIGHTRED);
		outtextxy(x+165-i,y+135,"-");

		setcolor(LIGHTBLUE);
		settextstyle(0,0,2);
		outtextxy(x-60,y+170,"Load");
		setcolor(LIGHTRED);
		outtextxy(x,y+170,"ing");
		setcolor(i-3);
		outtextxy(x+45,y+170,"...");
	}
	delay(300);
	cleardevice();
	closegraph();
}
void menu()
{
	char opt,ch;
	clrscr();
	textcolor(LIGHTCYAN);
	gotoxy(10,20);
	cprintf("]^[");
	gotoxy(9,21);
	cprintf("/|=|\\");

	textcolor(LIGHTCYAN);
	gotoxy(64,20);
	cprintf("]^[");
	gotoxy(63,21);
	cprintf("/|=|\\");


	textcolor(LIGHTRED);
	gotoxy(64,5);
	cprintf("}!{");
	gotoxy(65,6);
	cprintf("V");

	gotoxy(10,5);
	cprintf("}!{");
	gotoxy(11,6);
	cprintf("V");

	textcolor(WHITE);
	gotoxy(29,1);
	cprintf("<]| ALIEN INVASION |[>");
	textcolor(LIGHTBLUE);
	gotoxy(35,8);
	cprintf("Start[s]");
	gotoxy(34,11);
	cprintf("Highscore[h]");
	gotoxy(33,14);
	cprintf("Instruction[i]");
	gotoxy(35,17);
	cprintf("About[a]");
	textcolor(LIGHTRED);
	gotoxy(35,20);
	cprintf("Exit[esc]");
	_setcursortype(_NOCURSOR);        //won't display cursor
	opt=getch();
	switch(tolower(opt))
	{
		case 's':
		{
			textcolor(LIGHTGRAY);
			gotoxy(35,8);
			cprintf("Start[s]");
			delay(300);
			start();
		}
		break;
		case 'h':
		{
			textcolor(LIGHTGRAY);
			gotoxy(34,11);
			cprintf("Highscore[h]");
			delay(300);
			highscore();
		}
		break;
		case 'i':
		{
			textcolor(LIGHTGRAY);
			gotoxy(33,14);
			cprintf("Instruction[i]");
			delay(300);
			help();
		}
		break;
		case 'a':
		{
			textcolor(LIGHTGRAY);
			gotoxy(35,17);
			cprintf("About[a]");
			delay(300);
			about();
		}
		break;
		case 27:
		{
			textcolor(LIGHTGRAY);
			gotoxy(35,20);
			cprintf("Exit[esc]");
			delay(300);
			aexit:
			clrscr();
			textcolor(LIGHTRED);
			gotoxy(27,12);
			cprintf("Do you really wanna exit?");
			gotoxy(37,14);
			cprintf("(y/n)");
			ch=getch();
			if(ch=='y'||ch=='Y')
			{
				textcolor(LIGHTGRAY);
				gotoxy(38,14);
				cprintf("y");
				delay(300);
				exit(0);
			}
			else if(ch=='n'||ch=='N')
			{
				textcolor(LIGHTGRAY);
				gotoxy(40,14);
				cprintf("n");
				delay(300);
				menu();
			}
			else
				goto aexit;
		}
		break;
		default:
			menu();
	}
}

void start()
{
	int de,res;

	clrscr();
	textcolor(LIGHTBLUE);
	gotoxy(37,2);
	cprintf("START");
	textcolor(LIGHTCYAN);
	gotoxy(34,9);
	cprintf("Campaign[c]");
	gotoxy(32,12);
	cprintf("Time challenge[t]");
	gotoxy(32,15);
	cprintf("Practice Target[p]");
	textcolor(LIGHTRED);
	gotoxy(36,18);
	cprintf("BACK[b]");
	st:
	de=getch();
	if(tolower(de)=='c')
	{
		textcolor(LIGHTGRAY);
		gotoxy(34,9);
		cprintf("Campaign[c]");
		delay(300);
		story();
	}
	else if(tolower(de)=='t')
	{
		textcolor(LIGHTGRAY);
		gotoxy(32,12);
		cprintf("Time Challenge[t]");
		delay(300);
		timech();
	}
	else if(tolower(de)=='p')
	{
		textcolor(LIGHTGRAY);
		gotoxy(32,15);
		cprintf("Practice Target[p]");
		delay(300);
		target();
	}
	else if(tolower(de)=='b')
	{
		textcolor(LIGHTGRAY);
		gotoxy(36,18);
		cprintf("BACK[b]");
		delay(300);
		menu();
	}
	else
			goto st;
}
void help()
{
	clrscr();
	textcolor(YELLOW);
	gotoxy(37,2);
	cprintf("HELP");
	textcolor(YELLOW);
	gotoxy(35,6);
	cprintf("PLAYER");
	gotoxy(32,8);
	cprintf("Up = Up arrow key");
	gotoxy(32,11);
	cprintf("Left = Left arrow key");
	gotoxy(32,14);
	cprintf("Right = Right arrow key");
	gotoxy(32,17);
	cprintf("Down = Down arrow key");
	gotoxy(32,20);
	cprintf("Fire = space");
	_setcursortype(0);
	getch();
	menu();
}

void about()
{
	clrscr();
	textcolor(LIGHTMAGENTA);
	gotoxy(37,2);
	cprintf("ABOUT");
	textcolor(LIGHTMAGENTA);
	gotoxy(25,10);
	cprintf("This game is made by Angel Maden.");
	gotoxy(25,15);
	cprintf("Alien Invasion Version: 1.00.00");
	gotoxy(30,20);
	cprintf("Thank you for visiting");
	_setcursortype(0);
	getch();
	menu();
}

void story()
{
	int x,y,a,b,d,p,q,i;
	int nhit,level,lsc,spd;
	char ch,ans,de,fname[20];
	char ques1[20]="What's your name?",ques2[35]="Where do you live?";

	time_t t;
	srand((unsigned)time(&t));

	clrscr();
	textcolor(WHITE);
	gotoxy(34,1);
	cprintf("ALIEN INVASION");

	_setcursortype(_NOCURSOR);       //won't display cursor
	textcolor(LIGHTBLUE);
	gotoxy(30,8);
	for(i=0;i<=16;i++)
	{
		cprintf("%c",ques1[i]);
		delay(100);
	}
	textcolor(LIGHTRED);
	gotoxy(30,10);
	gets(name);

	gotoxy(30,15);
	for(i=0;i<=19;i++)
	{
		cprintf("%c",ques2[i]);
		delay(100);
	}
	gotoxy(30,17);
	scanf("%s",fname);

	clrscr();
	textcolor(LIGHTRED);
	gotoxy(14,3);
	cprintf("Something from the outer space striked in your city.");
	delay(3000);
	gotoxy(12,5);
	cprintf("Those were spaceships controlled by the Monster Aliens.");
	delay(3000);
	gotoxy(12,7);
	cprintf("They came out from their spaceship and destroyed your city.");
	delay(3000);
	gotoxy(14,10);
	cprintf("After sometime, they return back to their spaceship.");
	delay(3000);
	gotoxy(12,12);
	cprintf("They threatened that they'll come again and flyback.");
	delay(3000);
	gotoxy(12,14);
	cprintf("Okay, %s there is a spaceship you made earlier.",strupr(name));
	delay(3000);
	gotoxy(12,16);
	cprintf("And %s and your people life is in your hand now.",strupr(fname));
	delay(3000);
	gotoxy(12,18);
	cprintf("Don't let them to enter your city again %s.",strupr(name));
	delay(3000);
	gotoxy(18,21);
	cprintf("GOOD LUCK!! for saving your city. (*_*)");
	delay(3000);
	sp:
	textcolor(WHITE+BLINK);
	gotoxy(28,24);
	cprintf("PRESS SPACE TO CONTINUE...");
	if(getch()!=' ')
	goto sp;

	playagn:

	x=40;
	y=23;

	nhit=3;
	score=0;
	level=1;
	lsc=10;
	spd=180;
	p=rand()%6;
	while(1)
	{
		sc:
		p=rand()%6;
		for(q=2;q<=21;q++)
		{
			clrscr();
			textcolor(LIGHTCYAN);
			gotoxy(x,y);
			cprintf("]^[");
			gotoxy(x-1,y+1);
			cprintf("/|=|\\");
			textcolor(LIGHTMAGENTA);
			gotoxy(40,1);
			cprintf("Life : %d",nhit);
			textcolor(YELLOW);
			gotoxy(55,1);
			cprintf("Level : %d",level);
			textcolor(LIGHTBLUE);
			gotoxy(68,1);
			cprintf("Score : %d",score);
			textcolor(LIGHTGREEN);
			gotoxy(10,1);
			cprintf("Press p to pause");
			_setcursortype(0);
			textcolor(LIGHTRED);
			gotoxy((p*10)+10,q);
			cprintf("}!{");
			gotoxy((p*10)+11,q+1);
			cprintf("V");
			delay(spd);

			if(kbhit())
			{
				ch=getch();
				if((ch==72||ch=='8')&&y>23)        	//move upward
				{
					a=0;
					b=-1;
					x=x+a;
					y=y+b;
				}

				if((ch==75||ch=='4')&&x>10)             //move left
				{
					a=-10;
					b=0;
					x=x+a;
					y=y+b;
				}

				if((ch==77||ch=='6')&&x<70)             //move right
				{
					a=10;
					b=0;
					x=x+a;
					y=y+b;
				}

				if((ch==80||ch=='2')&&y<24)               //move downward
				{
					a=0;
					b=1;
					x=x+a;
					y=y+b;
				}

				if(ch==' '||ch=='5')
				{

					for(i=y;i>q+1;i--)
					{
						sound(600);
						delay(10);
						nosound();
						textcolor(LIGHTGRAY);
						gotoxy(x+1,i);
						cprintf("*");
						textcolor(LIGHTCYAN);
						gotoxy(x,y);
						cprintf("]:[");
						gotoxy(x-1,y+1);
						cprintf("/|=|\\");
					}
					if((p*10)+10==x)
					{
						sound(800);
						delay(10);
						nosound();
						score+=5;
						if((score/5)>=lsc)
						{
							lsc+=10;
							spd-=10;
							level++;
							if(level==6)
							{
								nhit+=3;
								gotoxy(34,11);
								cprintf("Fully Healed");
								delay(1200);
							}
							if(level>10)
							{
								clrscr();
								textcolor(LIGHTGREEN);
								gotoxy(20,10);
								cprintf("Congratulation! %s, ",strupr(name));
								gotoxy(20,12);
								cprintf("You saved your people and your best friend too.",strupr(name),score);
								gotoxy(20,15);
								cprintf("And %s, you scored %d.",strupr(name),score);
								textcolor(WHITE+BLINK);
								gotoxy(25,22);
								cprintf("Press space to continue...");
								win:
								if(getch()!=' ')
									goto win;
								menu();
							}
						}
						goto sc;
					}
				}

				if(ch=='p')             //press p to pause
				{
					clrscr();
					textcolor(LIGHTCYAN);
					gotoxy(34,8);
					cprintf("Press r to resume");
					gotoxy(31,12);
					cprintf("Press ESC to go Main menu");
					pause:
					de=getch();
					if(tolower(de)=='r')
						goto sc;
					else if(de==27)
						menu();
					else
						goto pause;
				}
			}
		}
		sound(100);
		delay(100);
		nosound();
		nhit--;
		if(nhit==0)
		{
			for(i=0;i<=2;i++)
			{
				clrscr();
				textcolor(LIGHTCYAN);
				gotoxy(x-1,y);
				cprintf("]^[");
				gotoxy(x-2,y+1);
				cprintf("/|=|\\");
				sound((i*100)+50);
				delay(300);
				nosound();
				clrscr();
				gotoxy(x,y-1);
				cprintf("^");
				gotoxy(x+i+1,y-i+1);
				cprintf("[");
				gotoxy(x+i+1,y+i-1);
				cprintf("|");
				gotoxy(x-i-1,y-i+1);
				cprintf("]");
				gotoxy(x-i-1,y+i-1);
				cprintf("|");
				gotoxy(x+i+1,y);
				cprintf("\\");
				gotoxy(x-i-1,y);
				cprintf("/");
				gotoxy(x,y+1);
				cprintf("=");
				gotoxy(35,12);
				textcolor(LIGHTRED);
				cprintf("GAME OVER");
			}
			delay(1000);
			goto last;
		}

	}
	last:
	cscoring();
	clrscr();
	textcolor(LIGHTGREEN);
	gotoxy(28,10);
	cprintf("%s, your scored %d.",strupr(name),score);
	textcolor(WHITE+BLINK);
	gotoxy(28,20);
	cprintf("Press space to continue...");
	br:
	if(getch()!=' ')
		goto br;
	clrscr();
	textcolor(LIGHTCYAN);
	gotoxy(26,10);
	cprintf("Wanna try to save your city again?");
	textcolor(WHITE+BLINK);
	gotoxy(36,12);
	cprintf("(y/n)");
	agn:
	ans=getch();
	if(ans=='y'||ans=='Y')
		goto playagn;
	else if(ans=='n'||ans=='N')
		menu();
	else
		goto agn;
}

void timech()
{
	int x,y,a,b,p,q,r,i;
	int nhit=3,level=1,lsc=10,spd=180;
	char ch,ans,de;
	time_t t;
	srand((unsigned)time(&t));

	x=40;
	y=23;
	clrscr();
	score=0;
	p=rand()%6;
	q=rand()%13;
	while(1)
	{
		sc:
		p=rand()%6;
		q=rand()%13;
		for(r=6;r<=75;r++)
		{
			textcolor(WHITE);
			gotoxy(3,3);
			cprintf("[[[");
			gotoxy(r,3);
			cprintf("->");
			gotoxy(76,3);
			cprintf("]]]");
			delay(spd);
			clrscr();
			textcolor(LIGHTCYAN);
			gotoxy(x,y);
			cprintf("]^[");
			gotoxy(x-1,y+1);
			cprintf("/|=|\\");
			textcolor(LIGHTRED);
			gotoxy(40,1);
			cprintf("Life : %d",nhit);
			textcolor(LIGHTMAGENTA);
			gotoxy(55,1);
			cprintf("Level : %d",level);
			textcolor(LIGHTBLUE);
			gotoxy(70,1);
			cprintf("Score : %d",score);
			textcolor(LIGHTGREEN);
			gotoxy(10,1);
			cprintf("Press p to pause");
			_setcursortype(0);
			textcolor(YELLOW);
			gotoxy((p*10)+10,q+5);
			cprintf("(O)");

			if(kbhit())
			{
				ch=getch();
				if((ch==72||ch=='8')&&y>23)        	//move upward
				{
					a=0;
					b=-1;
					x=x+a;
					y=y+b;
				}

				if((ch==75||ch=='4')&&x>10)             //move left
				{
					a=-10;
					b=0;
					x=x+a;
					y=y+b;
				}

				if((ch==77||ch=='6')&&x<70)             //move right
				{
					a=10;
					b=0;
					x=x+a;
					y=y+b;
				}

				if((ch==80||ch=='2')&&y<24)               //move downward
				{
					a=0;
					b=1;
					x=x+a;
					y=y+b;
				}

				if(ch==' '||ch=='5')
				{

					for(i=y;i>q+4;i--)
					{
						sound(600);
						delay(10);
						nosound();
						textcolor(LIGHTGRAY);
						gotoxy(x+1,i);
						cprintf("*");
						textcolor(LIGHTCYAN);
						gotoxy(x,y);
						cprintf("]:[");
						gotoxy(x-1,y+1);
						cprintf("/|=|\\");
					}
					if((p*10)+10==x)
					{
						sound(800);
						delay(10);
						nosound();
						score+=5;
						if((score/5)>=lsc)
						{
							lsc+=10;
							spd-=10;
							level++;
						}
						goto sc;
					}
				}

				if(ch=='p')             //press p to pause
				{
					clrscr();
					textcolor(LIGHTGREEN);
					gotoxy(35,9);
					cprintf("Press r to resume");
					gotoxy(31,13);
					cprintf("Press ESC to go Main menu");
					pause:
					de=getch();
					if(tolower(de)=='r')
						goto sc;
					else if(de==27)
						menu();
					else
						goto pause;
				}
		}	}
		sound(100);
		delay(100);
		nosound();
		nhit--;
		if(nhit==0)
		{
			for(i=0;i<=2;i++)
			{
				clrscr();
				textcolor(LIGHTCYAN);
				gotoxy(x-1,y);
				cprintf("]^[");
				gotoxy(x-2,y+1);
				cprintf("/|=|\\");
				sound((i*100)+50);
				delay(300);
				nosound();
				clrscr();
				gotoxy(x,y-1);
				cprintf("^");
				gotoxy(x+i+1,y-i+1);
				cprintf("[");
				gotoxy(x+i+1,y+i-1);
				cprintf("|");
				gotoxy(x-i-1,y-i+1);
				cprintf("]");
				gotoxy(x-i-1,y+i-1);
				cprintf("|");
				gotoxy(x+i+1,y);
				cprintf("\\");
				gotoxy(x-i-1,y);
				cprintf("/");
				gotoxy(x,y+1);
				cprintf("=");
				gotoxy(35,12);
				textcolor(LIGHTRED);
				cprintf("GAME OVER");
			}
			getch();
			goto last;
		}

	}
	last:
	clrscr();
	textcolor(LIGHTGREEN);
	gotoxy(34,8);
	cprintf("Your score is %d",score);
	tscoring();
	clrscr();
	textcolor(LIGHTCYAN);
	gotoxy(34,13);
	cprintf("Wanna play again?");
	textcolor(WHITE+BLINK);
	gotoxy(39,15);
	cprintf("(y/n)");
	agn:
	ans=getch();
	if(ans=='y'||ans=='Y')
		timech();
	else if(ans=='n'||ans=='N')
		menu();
	else
		goto agn;
}

void target()
{
	int x,y,a,b,p,q,i,j;
	int nhit=5,score=0,w=0,lsc=5,level=1;
	char ch,de;
	time_t t;
	srand((unsigned)time(&t));
	x=40;
	y=23;
	p=rand()%70;
	q=rand()%7;
	while(1)
	{
		sc:
		delay(10);
		clrscr();
		textcolor(YELLOW);
		gotoxy(p+5,q+5);
		cprintf("o");
		textcolor(LIGHTCYAN);
		gotoxy(x,y);
		cprintf("]^[");
		gotoxy(x-1,y+1);
		cprintf("/|=|\\");
		textcolor(LIGHTRED);
		gotoxy(40,1);
		cprintf("Life : %d",nhit);
		textcolor(LIGHTMAGENTA);
		gotoxy(55,1);
		cprintf("Level : %d",level);
		textcolor(LIGHTBLUE);
		gotoxy(70,1);
		cprintf("Score : %d",score);
		textcolor(LIGHTGREEN);
		gotoxy(10,1);
		cprintf("Press p to pause");
		_setcursortype(0);
		if(kbhit())               //check if a key is pressed
		{
			ch=getch();
			if((ch==72||ch=='8')&&y>23)        	//move upward
			{
				a=0;
				b=-1;
				x=x+a;
				y=y+b;
			}

			if((ch==75||ch=='4')&&x>4)             //move left
			{
				a=-1;
				b=0;
				x=x+a;
				y=y+b;
			}

			if((ch==77||ch=='6')&&x<77)             //move right
			{
				a=1;
				b=0;
				x=x+a;
				y=y+b;
			}

			if((ch==80||ch=='2')&&y<24)            //move downward
			{
				a=0;
				b=1;
				x=x+a;
				y=y+b;
			}

			if(ch==' '||ch=='5')
			{
				for(i=y;i>q+4;i--)
				{
					if(w==1)
					{
						sound(400);
						delay(10);
						nosound();
						textcolor(LIGHTRED);
						gotoxy(x,i);
						cprintf("***");
					}
					else
					{
						sound(600);
						delay(10);
						nosound();
						textcolor(LIGHTRED);
						gotoxy(x+1,i);
						cprintf("*");
					}
					textcolor(LIGHTCYAN);
					gotoxy(x,y);
					cprintf("]:[");
					gotoxy(x-1,y+1);
					cprintf("/|=|\\");
				}
				if(w==1&&(p+5==x+1||p+5==x||p+5==x+2))
					goto ft;
				if(p+5==x+1)
				{
					ft:
					sound(800);
					delay(10);
					nosound();
					p=rand()%70;
					q=rand()%7;
					score+=5;
					if((score/5)>lsc)
					{
						lsc+=5;
						level++;
						if(level%4==0)
						{
							nhit+=2;
							gotoxy(32,11);
							cprintf("Partially Healed");
							delay(1200);
						}
						if(level%10==0)
						{
							nhit+=5;
							gotoxy(34,12);
							cprintf("Fully Healed");
							delay(1200);
						}
						if(level%2==0)
						{
							w=1;
							gotoxy(32,13);
							cprintf("Weapon Upgraded");
							delay(1200);
						}
					}
					goto sc;
				}
				else
				{
					nl:
					w=0;
					nhit--;
					if(nhit==0)
					{
						for(i=0;i<=2;i++)
						{
							clrscr();
							textcolor(LIGHTCYAN);
							gotoxy(x-1,y);
							cprintf("]^[");
							gotoxy(x-2,y+1);
							cprintf("/|=|\\");
							sound((i*100)+50);
							delay(300);
							nosound();
							clrscr();
							gotoxy(x,y-1);
							cprintf("^");
							gotoxy(x+i+1,y-i+1);
							cprintf("[");
							gotoxy(x+i+1,y+i-1);
							cprintf("|");
							gotoxy(x-i-1,y-i+1);
							cprintf("]");
							gotoxy(x-i-1,y+i-1);
							cprintf("|");
							gotoxy(x+i+1,y);
							cprintf("\\");
							gotoxy(x-i-1,y);
							cprintf("/");
							gotoxy(x,y+1);
							cprintf("=");
							gotoxy(35,12);
							textcolor(LIGHTRED);
							cprintf("GAME OVER");
						}
						delay(1000);
						goto last;
					}
				}
			}
			if(ch=='p')             //press p to pause
			{
				clrscr();
				textcolor(LIGHTGREEN);
				gotoxy(35,9);
				cprintf("Press r to resume");
				gotoxy(31,13);
				cprintf("Press ESC to go Main menu");
				pause:
				de=getch();
				if(tolower(de)=='r')
					goto sc;
				else if(de==27)
					menu();
				else
					goto pause;
			}

		}
	}
	last:
	clrscr();
	textcolor(LIGHTGREEN);
	gotoxy(34,10);
	cprintf("Your score is %d",score);
	pscoring();
	clrscr();
	textcolor(LIGHTCYAN);
	gotoxy(34,13);
	cprintf("Wanna play again?");
	textcolor(WHITE+BLINK);
	gotoxy(39,15);
	cprintf("(y/n)");
	agn:
	ch=getch();
	if(ch=='y'||ch=='Y')
		target();
	else if(ch=='n'||ch=='N')
		menu();
	else
		goto agn;
}

void cscoring()
{
	int hscore;
	char hname[20];
	fc=fopen(cfile,"w+");
	if(fp==NULL)
	{
		strcpy(hname,"Angel");
		hscore=0;
		fprintf(fc,"%s\t%d",hname,hscore);
		fclose(fc);
	}
	else
	{
		fscanf(fc,"%d",&hscore);
		if(score>hscore)
		{
			strcpy(hname,name);
			hscore=score;
			fprintf(fc,"%s\t%d",hname,hscore);
		}
	}
	fclose(fc);
}
void tscoring()
{
	int hscore;
	char hname[20];

	gotoxy(33,15);
	cprintf("Your name : ");
	scanf("%s",name);
	fflush(stdin);

	ft=fopen(tfile,"w+");
	if(ft==NULL)
	{
		strcpy(hname,"Angel");
		hscore=0;
		fprintf(ft,"%d\t%s",hname,hscore);
		fclose(ft);
	}

	fscanf(ft,"%d",&hscore);
	if(score>hscore)
	{
		fprintf(ft,"%d\t%s",score,name);
	}
	fclose(ft);
}

void pscoring()
{
	int hscore;
	char hname[20];

	gotoxy(33,15);
	cprintf("Your name : ");
	scanf("%s",name);
	fflush(stdin);

	fp=fopen(pfile,"w+");
	{
		strcpy(hname,"Angel");
		hscore=0;
		fprintf(fp,"%d\t%s",hname,hscore);
		fclose(fp);
	}

	fscanf(fp,"%d",&hscore);
	if(score>hscore)
		fprintf(fp,"%d\t%s",score,name);
	fclose(fp);
}

void highscore()
{
	int hscore;
	char hname[20],h,res;
	clrscr();
	_setcursortype(0);
	textcolor(WHITE);
	gotoxy(34,1);
	cprintf("HIGHSCORE");
	textcolor(LIGHTCYAN);
	gotoxy(29,8);
	cprintf("Campaign Highscore[c]");
	gotoxy(26,11);
	cprintf("Time Challenge Highscore[t]");
	gotoxy(26,14);
	cprintf("Target Practice Highscore[p]");
	gotoxy(30,17);
	cprintf("Reset Highscore[r]");
	textcolor(LIGHTRED);
	gotoxy(35,20);
	cprintf("BACK[b]");
	h=getch();
	if(tolower(h)=='c')
	{
		clrscr();
		textcolor(LIGHTBLUE);
		fc=fopen(cfile,"r+");
		if(fp==NULL)
		{
			strcpy(hname,"Angel");
			hscore=0;
			fprintf(fc,"%s\t%d",hname,hscore);
			fclose(fc);
		}
		fscanf(fc,"%s\t%d",hname,&hscore);
		gotoxy(36,10);
		cprintf("%s\t%d",hname,hscore);
		fclose(fc);
		getch();
		highscore();
	}
	else if(tolower(h)=='t')
	{
		clrscr();
		textcolor(LIGHTBLUE);
		ft=fopen(tfile,"r");
		fscanf(ft,"%d     %s",hname,&hscore);
		gotoxy(36,10);
		cprintf("%d     %s",hname,hscore);
		fclose(ft);
		getch();
		highscore();
	}
	else if(tolower(h)=='p')
	{
		clrscr();
		textcolor(LIGHTBLUE);
		fp=fopen(pfile,"r");
		fscanf(fp,"%d     %s",hname,&hscore);
		gotoxy(36,10);
		cprintf("%d     %s",hname,hscore);
		fclose(fp);
		getch();
		highscore();
	}
	else if(tolower(h)=='r')
	{
		clrscr();
		textcolor(WHITE);
		gotoxy(26,12);
		cprintf("Do you really wanna reset?");
		gotoxy(36,14);
		cprintf("(y/n)");
		res:
		res=getch();
		if(tolower(res)=='y')
		{
			remove(cfile);
			remove(tfile);
			remove(pfile);
			delay(1000);
			menu();
		}
		else if(tolower(res)=='n')
			highscore();
		else
			goto res;
	}
	else if(tolower(h)=='b')
		menu();
	else
		highscore();
}
