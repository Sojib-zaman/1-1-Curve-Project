/*
MD. ROQUNUZZAMAN SOJIB
1905067
CSE-B

*/


/*
todo
1.add file
2.check time
3.SAVE KORE MORAR POR ABAR START E PROBLEM
4.GAME E BACK

*/






















#include <windows.h>
#include <mmsystem.h>




# include "iGraphics.h"
# include "gl.h"
#include<stdio.h>
#include <stdlib.h>
using namespace std ;
#include <math.h>
int height =700 , width=1500;
int xpos=width/2, ypos= 100 , dx=5 , dy=5  ;
double velocity =6  ;
double angle = 45 ;
int first=1 ;
int deadline =  100 ;
int radius = 5 ;
int red=255 , green=100 , blue=100 ;
int startgame=0 ;
int xboard = xpos-50 , yboard=ypos-20 , xxboard=100 , yyboard=15 , boardspeed=25 ;
int totalbricks=140,row=14,col=10, bxlen = 100 , bylen=20 ;
int helpdesk=1 , gameportal=0 ;
int rankmode=0 ;
enum bons
{
    fireball , wideboard, fastball ,extralife , shield
} bonus;
int credits=0 ;
struct bricks
{
    int x ;
    int y ;
    int showbrick =1 ;
    struct brickcolors
    {
        int red ;
       int  blue ;
        int green  ;
    }brcol;
    int power ;
    int dpn ;
    int dpx ;
    int dpy ;
    int dpp  ;
    int touched  ;
    int boxpower ;


}box[141] ;
int alpha=0 ;
int ifsaved=0 ;
int wanna= 0 ;
int rstart=0 ;
int strikebox=0 , strikeboard=1 ;
int midw = width/2  , midh=height/2 ;
int turnoptions=0 ; //************//
int life=3 , death = 0  ;
int t=0,second , startsec, paused = 0 , psec=0 , actime = 0  ;
int initialtime=180 ;
int spacecount=0 ;
int showreturn =  0 ;
int gameended=0 ;
int score=0 ;
int success=0 ,calldead=0;
int playmusic1 = 0,  playsfx=0; //options e add
int highscore=0 ;
//power
int modefire=0 ;
int dpx=0 , dpy=0 , dpp=0 , dpn=0 ;
void valueofbricks() ;
int blockrandcol=7 ;

char namepower[13][15]={"ballfire.bmp","largeball.bmp" ,"faster.bmp","heart.bmp","shield.bmp","death.bmp","arrow.bmp","slow2.bmp","timeearn.bmp","ghost.bmp","ping.bmp","money.bmp"} ;

int sline= 0  ;
int callpower[12]={1} ;

int about =0 ;
char gamebgm[5][20]={"bg1.bmp" , "bg2.bmp" , "bg3.bmp","bg4.bmp","bg5.bmp"}  ;
void quitsave() ;
int savedgame = 0 ;
int lost=0 ;
void helpline()
{

        int line1=35 , count=1 ;
        iSetColor(255,0,255)  ;

        iShowBMP(0,0,"bgpic.bmp") ;
       FILE *fp2=fopen("isgamesave","r") ;
    fscanf(fp2 , "%d " , &savedgame) ;
     fclose(fp2) ;
//     printf("%d\n",savedgame) ;
        if(savedgame&&!paused&&lost==0)
            iShowBMP(midw-100 , midh+70, "previous.bmp") ;

       iShowBMP(midw-100 , midh-55 , "start2.bmp")  ;
        if(showreturn)
        {
            iShowBMP(midw-100 , midh-160 , "resume.bmp") ;
        }
iShowBMP(midw-100 , midh-220 , "options.bmp") ;
iShowBMP(midw-100  , midh-300 , "exit.bmp") ;

iShowBMP(100,100,"winner.bmp") ;

if(turnoptions)
{


iShowBMP(width/2-250 , height/2 - 190, "setting1.bmp") ;
    if(playsfx)
    iSetColor(0,255,0) ;
    else
    iSetColor(255,0,0) ;
    iFilledCircle(midw+50 , midh+125 ,10) ;




    if(playmusic1)
    iSetColor(0,255,0) ;
    else
    iSetColor(255,0,0) ;
    iFilledCircle(width/2+50 , height/2+60 , 10) ;

iShowBMP(midw-100 , midh-150 ,"close1.bmp") ;




















}


//CREDITS



iShowBMP(1100,150,"credits.bmp") ;
if(credits==1)
   {
       iShowBMP(midw-300, midh-255,"cred2.bmp") ;
    iShowBMP(1000,50,"close.bmp") ;

   }


//about game
iShowBMP(1100 ,100 , "about.bmp") ;
if(about==1)
{
    iShowBMP(0,0,"abback.bmp") ;
     iShowBMP(1000,50,"close.bmp") ;

}




if(wanna)
{
    iShowBMP(midw-600 , midh-200 ,"confirm.bmp") ;

}








}




int finalresult   ;

void youendedpart()
{
    helpdesk=0 ;
    gameportal=0 ;
    startgame=0   ;




    finalresult=score+(initialtime-actime)*1+life*1000;




       iShowBMP(0,0,"sesh.bmp") ;


           char sresult[100] ;
           sprintf(sresult,"%d",finalresult) ;
         iShowBMP(0,height/2-100,"final.bmp") ;
            iSetColor(0,255,255) ;

iShowBMP(75,height-150,"back.bmp") ;
iText(250,height/2 -100 , sresult,GLUT_BITMAP_TIMES_ROMAN_24) ;


}

void powertouch() ;
void powercontrol(int d) ;


void contractchecker() ;
int bgcounter= 0 ;
int inputmode = 0  , nameboxx=100 ;
int bi = 0 ;
void nameinput ()
{
   iShowBMP( 0 , midh-10 ,  "name.bmp") ;
   if(!bi)
		iSetColor(50, 10, 150);
    else
        iSetColor(0,255,0) ;
	iFilledRectangle(60 , midh-10 ,  nameboxx , 30);

}



char str[100], str2[100];


struct game
{
    int data;
    char name[100];
} ;





int previous=0 ;


int ok=0,m=0 ;



void iDraw()
{

	iClear();







	int d ;
	char stimeem[10] , stimees[10];
	if(gameportal==1 && helpdesk ==0 )
{
  iSetColor(255,255,255) ;

	int e = bgcounter%6 ;
	if(bgcounter%6!=0)
    {
        iShowBMP(0,0,gamebgm[e-1]) ;
    }
    if(startgame==0)
iText(600 , height - 50 , "Press F2 and F3 to change " , (void*)8)  ;
	//iFilledRectangle(700, height-50  , 25,25) ;
	//iSetColor(255,0,0) ;
	//iText(700 , height - 50 , "F2" , (void*)8)  ;

}
















if(gameportal==1 && helpdesk ==0 &&startgame==1  )
{




//printf("%d  ",xpos)  ;

  int count  = (second-startsec) / 10  ;

  actime=second-startsec ;
if(previous)
{
    m++ ;
    //printf("%d ",m) ;
    if(m==1)
    ok=1 ;
    else
        ok=0 ;
}

if(ok)
{
    FILE *fp = fopen("timer.txt","r") ;
fscanf(fp,"%d %d %d",&second,&actime,&startsec) ;
fclose(fp) ;
//    printf("%d %d %d\n",actime,second,startsec) ;
   ok=0 ;
}






        sprintf(stimees,"%d",(initialtime-actime)%60) ;
        velocity+=( (second-startsec) / 60 ) *0.5 / 100 ;
    sprintf(stimeem,"%d",(initialtime-actime)/60) ;
        iSetColor(255,255,255) ;
        iShowBMP(0,height-50,"watch.bmp") ;

        if((initialtime-actime)<10 && playsfx)
          PlaySound("timer.wav" , NULL , SND_ASYNC ) ;




       // iText(100 , height-50 , "Time")  ;
       iText(75,height-30 ,stimeem,(void*)8) ;
       iText(85,height-30,":",(void*)8) ;
	iText(100,height-30,stimees,(void*)8)	;
	 //iText(150 , height-50 , "seconds",(void*)8)  ;
	char point[100] ;

	// iText(350 , height-50 , "your score")  ;
	iShowBMP(350 , height -50 , "score.bmp") ;
	 sprintf(point,"%d",score) ;
	 iSetColor(0,255,255) ;
	 iText(500 ,height-30 , point,(void*)8) ;
for(int i=0 ; i<totalbricks ; i++)
{

if(box[i].dpn==1 && gameportal)
{


      iShowBMP2( box[i].dpx, box[i].dpy,namepower[box[i].power] , 0xFFFFFF) ;
      box[i].dpy-- ;
      if(box[i].dpx>=xboard && box[i].dpx<=xboard+xxboard && box[i].dpy>=yboard && box[i].dpy<=yboard+yyboard && box[i].dpn)
      powertouch() ;

 }




}


}



if(gameportal)
{
    for(int i=1 ; i<=life; i++)
        iShowBMP2(850+50*i,height-50,"heart.bmp" , 0xFFFFFF );
    if(sline==1)
    {
        iSetColor(255,0,0) ;
        iLine(0,yboard-1,width,yboard-1)  ;
         iLine(0,yboard-2,width,yboard-2)  ;
         iLine(0,yboard-2,width,yboard-2)  ;
    }



iShowBMP(1400 , height - 50  , "actpause.bmp") ;










}



if(helpdesk==1 && gameportal==0)
    {
        helpline() ;
        if(rankmode==1)
{
    iShowBMP(0,0,"pureblack.bmp") ;
    char sc[100] ;
    iShowBMP(midw-250 , midh+50 , "high.bmp")  ;

    struct game  player[11] = {0} ;
FILE* fp=fopen("high score.txt","r");
    int i=0 , d=50 ;
    while(i!=10)
            {

                fscanf(fp,"%d %[^\n]",&player[i].data , player[i].name);

                if(i<3)
                    iSetColor(255,0,0) ;
                else
                iSetColor(255,255,255)  ;
                 sprintf(sc,"%d",player[i].data) ;
                iShowBMP(400  , 400 , "plname.bmp") ;
                iShowBMP(880,400,"gamehighscore.bmp") ;
                iText(500 , 400-d, player[i].name , GLUT_BITMAP_TIMES_ROMAN_24 ) ;
                iText(900 ,400-d, sc , GLUT_BITMAP_TIMES_ROMAN_24 ) ;
 iShowBMP(1000,50,"close.bmp") ;

                d+=30 ;
                i++;
                if(feof(fp))break;

            }
            fclose(fp);


}
    }

	if(helpdesk==0 && gameportal==1)
    {
        if(!modefire)
        iSetColor(215,231,24) ;
        else
            iSetColor(255,0,0) ;
	iFilledCircle(xpos,ypos,radius,1000) ;
	iSetColor(80,200,30) ;
	iFilledRectangle(xboard , yboard , xxboard  , yyboard) ;

	for(int i=0 ; i<=totalbricks ; i++)
    {

         iSetColor(  (box[i].brcol.red*blockrandcol)%255 ,  (box[i].brcol.green*blockrandcol)%255 ,  (box[i].brcol.blue*blockrandcol )%255 ) ;
        if(box[i].showbrick==1)
        iFilledRectangle(box[i].x , box[i].y , bxlen , bylen) ;
        if(i%10==0 && box[i].showbrick&&i!=140)
        {
             iSetColor(255,0,0) ;
         iLine(box[i].x,box[i].y,box[i].x+bxlen,box[i].y+bylen) ;
         iLine(box[i].x+15,box[i].y,box[i].x+bxlen,box[i].y+bylen-5) ;
        iLine(box[i].x+30,box[i].y,box[i].x+bxlen,box[i].y+bylen-10) ;
        iLine(box[i].x+45,box[i].y,box[i].x+bxlen,box[i].y+bylen-15) ;
        iLine(box[i].x+60,box[i].y,box[i].x+bxlen,box[i].y+bylen-20) ;
 iLine(box[i].x,box[i].y,box[i].x+bxlen,box[i].y+bylen) ;
         iLine(box[i].x+15,box[i].y,box[i].x+bxlen,box[i].y+bylen-5) ;
        iLine(box[i].x+30,box[i].y,box[i].x+bxlen,box[i].y+bylen-10) ;
        iLine(box[i].x+45,box[i].y,box[i].x+bxlen,box[i].y+bylen-15) ;
        iLine(box[i].x+60,box[i].y,box[i].x+bxlen,box[i].y+bylen-20) ;

        }

    }




    }
if(calldead)
{

      youendedpart() ;
    nameinput () ;
	if(inputmode == 1)
	{
		iSetColor(255, 255, 255);
		iText(60,midh+2, str ,(void*)8);
	}


}








}

















int pd=0 ;
void valueofbricks()
{





    int i ;
    int x1=20 , y1=600 ;
    for(i=0 ; i<totalbricks ; i=i+14)
    {
        red=rand()%255 ;
        blue=rand()%255 ;
        green=rand()%255 ;
        for(int j=i ; j<i+14 ; j++)
        {
             box[j].brcol.red  = (red+300*blockrandcol)%255 ;
             box[j].brcol.blue=( blue+200*blockrandcol)%255 ;
            box[j].brcol.green=(green+100*blockrandcol)%255 ;


        }
    }

    for(i = 0 ; i<totalbricks ; i++)
    {
        if(i%10==0)
           {
                box[i].boxpower=100  ;

                box[i].brcol.red  = 192;
             box[i].brcol.blue=192 ;
            box[i].brcol.green=192 ;


           }
        else
            box[i].boxpower=0 ;
    }














     for(i=0 ; i<totalbricks ; i++)
    {
        box[i].x = x1  ;
        box[i].y=y1 ;
        x1+=bxlen+1 ;
        if(x1>=row*bxlen)
           {
               y1-=21 ;
               x1=20 ;
           }
        if( i% 12 ==0) /* ^^^^^^^^ */
        {

            box[i].power=pd %12  ;/* ^^^^^^^^ */
            pd++ ;
        // printf("%d\n",box[i].power) ;
        }



    }

}

void powertouch()
{

  for(int i = 0 ; i<totalbricks ; i++)
  {

      if( i%12==0 )
      {
          if(box[i].dpx>=xboard && box[i].dpx<=xboard+xxboard && box[i].dpy>=yboard+yyboard)
        {
            box[i].touched=1 ;
            box[i].dpn=0 ;
            if(callpower[box[i].power]!=0)
           {
//               printf("calling power                    %d \n",box[i].power) ;
            powercontrol(box[i].power) ;
           }
        callpower[box[i].power]=0 ;
            return ;

       }
      }

  }







}









int boxhit = 0 , cp= 0  ;
void powercontrol(int d)
{
    //include time control for the power
    //shield and fireball taking input continuously
//    printf("%d is %s \n",d,namepower[d]) ;
 int x ;
    int count=1 ;
    double clife = life , cboard=xxboard , cvelocity=velocity  ;

       if(d==0 )
       {
           for(int x1=1 ; x1<=10000 ; x1+=500)
           modefire=1 ;




       }
        if(d==6)
        {
                for(int x2=1 ; x2<=10000 ; x2+=500)
                 xxboard=150 ;
              cp=1 ;
              if(boxhit>10)
                xxboard=100 ;



        }
     if(d==2)
       {
            for(int x3=1 ; x3<=10000 ; x3+=500)
           velocity=20;




       }
     if(d==3)
      {
           for(int i=0 ; i<1 ; i++)
            {
                life++ ;
                death-- ;
                 break ;
            }
           // printf("life : %d\n",life) ;


      }
      if(d==4)
      {
          for(int x4=1 ; x4<=10000 ; x4+=500)
          sline=1 ;


      }

       if(d==5)
       {
           death++ ;
           life-- ;
       }

       if(d==7)
       {
           for(int x5=1 ; x5<=10000 ; x5+=500)
                 velocity=5 ;


       }

       if(d==1)
       {
          for(int x6=1 ; x6<=10000 ; x6+=500)
                 radius=10 ;


       }

       if(d==8)
        initialtime+=20 ;
       if(d==9)
        {
            int r=rand()%100 ;
            for(int i=r ; i<r+15 ; i++)
                box[i].showbrick = 0 ;

            score+=100 ;
        }
       if(d==10)
       {
           for(int x7=1 ; x7<=10000 ; x7+=500)
           radius=3 ;


       }
         if(d==11)
            score+=50 ;





}
int currentbrick  = totalbricks  ;
void restartgame() ;
void contractchecker()
{
    strikebox=0  ;
    for(int i=0 ; i<totalbricks ; i++)
    {
        if(box[i].showbrick)
        {
            if ( xpos>=box[i].x - radius+1 && xpos<=box[i].x+bxlen+radius-1 && ypos>=box[i].y && ypos<=box[i].y+bylen &&box[i].showbrick  )
            {
                 strikebox=1 ;
                if(box[i].boxpower==0)
                {
                    if(cp)
           boxhit++ ;

                score+=10 ;
                currentbrick-- ;
                 box[i].showbrick=0 ;
                if(i%12==0)
                {
                    box[i].dpx=box[i].x  ;
                    box[i].dpy= box[i].y ;
                    box[i].dpp=box[i].power  ;
                    box[i].dpn=1;
                    //movedrawpower( box[i].power , box[i].x  , box[i].y) ;


                    // powertouch( box[i].power , box[i].x  , box[i].y) ;
                }
                else
                {
                    box[i].dpx=0  ;
                    box[i].dpy= 0 ;
                    box[i].dpp=0 ;
                    box[i].dpn=0;
                }
                }
                else
                    box[i].boxpower=0;




                }

            }
        }


    int count = 0  ;
    for(int i=0 ; i<totalbricks ; i++)
    {
        if(box[i].showbrick ==0)
            count++ ;
    }


if(actime>initialtime)
{
    success=0 ;
    calldead=1 ;
    gameportal=0 ;
    showreturn=0 ;


}

if(count==totalbricks-1)
    {

        success =1 ;
         calldead=1 ;
           gameportal=0 ;
    showreturn=0 ;


    }



}


void restartgame()
{
if(!previous || !paused)
{
    xpos=width/2 ;
     ypos= 100  ;
     xboard = xpos-50 ;
     yboard=ypos-20  ;
      xxboard=100 ;
       yyboard=15 ;
       startgame=0 ;
       velocity=7 ;
radius=5 ;
angle=45 ;
modefire=0 ;
for(int e=0 ; e<=12 ; e++)
    callpower[e]=1  ;

}


}

void ddxyfinder()
{
    if(strikeboard)
    {
        if(first)
        {
            first=0 ;
            angle=45 ;
        }
       else
       {
           angle=xxboard - xpos +xboard + (180 - xxboard) /2 ;
        dx =  velocity * 1.0 * cos(3.1416*angle/180) ;
        dy = velocity *1.0 * sin(3.1416*angle/180) ;
       }


    }

}

void moveball()
{



    ddxyfinder() ;




    if(startgame)
    {
        xpos+=dx  ;

        ypos+=dy ;
    if(xpos>=width-radius || xpos<=radius)
        dx*=-1 ;
    if(ypos>=height || ypos<=0)
        dy*=-1 ;
    }

    if(xpos>=xboard && xpos<=xboard+xxboard && ypos>yboard && ypos<=yboard+yyboard+1)
        {
            dy*=-1 ;
            strikeboard=1 ;
        }
    else
        strikeboard=0 ;
 contractchecker() ;
    if(ypos<yboard-10 && sline==0)
    {
        death++ ;
        life--  ;
        //modefire=0 ;
        psec=second ;
        if(life==0)
        {
              calldead=1 ;
            gameportal=0 ;
            showreturn=0 ;
            success=0 ;
        }
       //if(!previous)
       restartgame()  ;
    }

    if(strikebox)
    {
        if(!modefire)
        dy*=-1 ;
        if(playsfx)
        PlaySound("blockhit.wav" , NULL , SND_ASYNC ) ;

    }
    if(sline)
    {
        if(ypos<=yboard)
           {
               dy*=-1 ;
            sline = 0 ;
           }
    }
 if(strikeboard && playsfx)
  PlaySound("boardhit.wav" , NULL , SND_ASYNC ) ;




}


void iMouseMove(int mx, int my)
{


        xboard=mx;
        if(xboard<=100)
        {
            xboard=0  ;
            xboard=mx ;
        }
        if(xboard>=width)
        {
            xboard=width-300 ;
            xboard=mx ;
        }


         if(!startgame||!paused)
         {
             if(ypos==yboard+20)
                xpos=xboard+xxboard/2 ;
         }


}

void musicoff() ;
void musicon() ;

void sortn( struct game *a   ,int n  )
{
    int i , j  ;
    for(i=0 ; i<n-1 ; i++)
    {
        for(j=i+1 ; j<n  ; j++)
        {
            if(a [i].data <a[j].data )
            {
             struct game  temp=a[i] ;
          a[i]  =a[j] ;
           a[j ] = temp  ;
            }
        }
    }

}


void gamesave() ;




void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	    //printf("%d %d\n",mx,my) ;


            if(helpdesk==1 && gameportal==0)
            {

                 if(mx>=1100 && mx<=1250 && my >=100 && my<=160&& turnoptions==0 && !credits && !about)

                {
                     if(playsfx)
                      PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
                    about=1 ;
                }
                if(mx>=1000 && mx<=1150 && my >= 50 && my<=110&& !credits&& about)
                     {
                          if(playsfx)
                           PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
                           about=0 ;
                     }




/////////////////////START/////////////////////////////////////
                if(mx>=midw-100 && mx<=midw+150 && my>=midh-55 && my<=midh+55 && turnoptions==0 && !credits && !about)
                {
                     if(playsfx)
                      PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
                    gameportal=1 ;
                    helpdesk=0 ;
                    startsec=second ;
                    spacecount=0 ;
                    startgame=0 ;
                  score=0 ;
                  totalbricks=140  ;
                  for(int i=0 ; i<totalbricks  ; i++)
                    box[i].showbrick=1 ;
                    life=3  ;
                    sline=0 ;
                    modefire=0 ;
                    radius=5;
                      xpos=width/2, ypos= 100  ;
                     velocity=7 ;
                     xboard = xpos-50 , yboard=ypos-20 , xxboard=100 , yyboard=15 , boardspeed=25 ;
                   turnoptions=0 ;
for(int e=0 ; e<=12 ; e++)
    callpower[e]=1  ;
bi=0 ;
    boxhit=0  ;
    cp=0 ;

savedgame=0 ;
str[0]=32 ;

previous=0 ;








                }


                //I have clicked on previous button , now saving all the files

                 if(mx>=midw-100 && mx<=midw+150 && my >= midh+70 && my<=midh+140 &&!paused && turnoptions==0 && !credits&&!rankmode && !about)
                {
                    savedgame=0 ;
                    previous=1 ;
                    if(playsfx)
                      PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;


                    FILE *fp = fopen("savegame.txt" , "r")  ;
      fscanf(fp ,"%d %d %d %d %d %d %lf %d %d %d %d %d %d %d %d %d "  , &spacecount , &score , &currentbrick , &life , &sline , &modefire , &velocity , &radius , &xpos , &ypos , &xboard , &yboard , &xxboard , &yyboard , &boxhit , &cp  ) ;
 //printf("%d %d %d %d %d %d %d %d %lf %d %d %d %d %d %d %d %d %d done" , second ,actime, spacecount , score , currentbrick , life , sline , modefire , velocity , radius , xpos , ypos , xboard , yboard , xxboard , yyboard , boxhit , cp  ) ;

      for ( int i = 0  ; i<totalbricks ; i++)
     fscanf(fp , "%d " , &box[i].boxpower) ;
 for ( int i = 0  ; i<totalbricks ; i++)
     fscanf(fp , "%d " , &box[i].showbrick) ;
  for(int e=0 ; e<=12 ; e++)
    fscanf(fp , "%d " , &callpower[e]) ;
       for ( int i = 0  ; i<totalbricks ; i++)
       {
           if(i%12==0)
           {
                   fscanf(fp , "%d %d %d %d " , &box[i].dpx , &box[i].dpy  , &box[i].dpp  , &box[i].dpn) ;
           }

       }


fclose(fp)  ;

FILE *fp1 = fopen("timer.txt","r") ;
fscanf(fp1,"%d %d %d",&second,&actime,&startsec) ;
fclose(fp1) ;






 gameportal=1 ;
                    helpdesk=0 ;




                }


















                if(mx>=midw-100 && mx<=midw+150 && my >= midh-300 && my<=midh-223 && turnoptions==0 && !credits&&!rankmode && !about)
                   {
                       if(life)
                       wanna=1 ;
                       else
                        exit(0) ;
                   }

                       if(mx>=389 && mx<=600 && my >=215 && my<=270&&wanna)
                       {
                           savedgame=1 ;
                           FILE *fp2=fopen("isgamesave","w") ;
                           fprintf(fp2 , "%d " , savedgame) ;
                           fclose(fp2) ;

                           gamesave() ;
                            exit(0) ;
                       }
                       else if(mx>=660 && mx<=870 && my >=215 && my<=270&&wanna)
                         {
                             savedgame=0 ;
                           FILE *fp2=fopen("isgamesave","w") ;
                           fprintf(fp2 , "%d " , savedgame) ;
                           fclose(fp2) ;

                             exit(0) ;

                         }











                 if(mx>=midw-100 && mx<=midw+150 && my >= midh-160 && my<=midh-55 &&paused && showreturn && turnoptions==0&& !credits && !about)
                 {
                      if(playsfx)
                       PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
                      gameportal=1 ;
                    helpdesk=0 ;
                    second=psec   ;
                    startgame=0 ;
                    turnoptions=0 ;


                 }
            if(mx>=midw-100 && mx<=midw+150 && my >= midh-220 && my<=midh-160&& !credits && !about)
            {
                 if(playsfx)
                  PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
                  turnoptions=1 ;
            }

                  if(mx>=midw+40 && mx<=midw+60  && my>=midh+115 && my<=midh+135 && turnoptions&& !credits && !about)
                  {
                       if(playsfx)
                        PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
//                      printf("%d\n",playsfx) ;

                      if(playsfx==0)playsfx=1 ;
                      else playsfx=0 ;
                  }



                  if(mx>=midw+40 && mx<=midw+60  && my>=midh+50 && my<=midh+70 && turnoptions&& !credits && !about)
                  {
                       if(playsfx)
                        PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
//                      printf("%d\n",playmusic1) ;

                      if(playmusic1==0)
                      {
                           if(playsfx)
                            PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
                          playmusic1=1 ;  musicon() ;
                      }
                      else
                      {
                           if(playsfx)
                            PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
                          playmusic1=0 ;  musicoff() ;
                      }
                  }




                 if(mx>=midw-100 && mx<=midw+50 && my>=midh-150 && my<=midh-100 && turnoptions && !credits && !about)
                  {
                       if(playsfx)
                        PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
                      turnoptions=0 ;
                      helpdesk=1;
                  }
     if(mx>=100 && mx<=250 && my>=100 && my<=250  && !turnoptions&& !credits && !about &&!rankmode)
     {
         rankmode=1 ;
          if(playsfx)
  PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;


     }
     if(mx>=1000 && mx<=1150 && my >= 50 && my<=110&& !turnoptions && !credits&& !about&&rankmode)
        {
             if(playsfx)
              PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
            rankmode=0 ;
            helpdesk=1 ;
        }







                 if(mx>=1100 && mx<=1250 && my >= 150 && my<=210&& turnoptions==0 &&!rankmode&& !credits&& !about)
                   {
                        if(playsfx)
                         PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;

                       credits=1 ;

                   }
if(mx>=1000 && mx<=1150 && my >= 50 && my<=110&&!rankmode&& credits&& !about)
                {
                     if(playsfx)
                      PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
                      credits=0 ;
                }




            }

            if(calldead==1 && helpdesk==0)
            {
                  if(mx>=75 && mx<=215 && my >= height-150 && my<=height-120  )
                  {
                       if(playsfx)
                        PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
                      calldead=0 ;
                         success=0  ;
                      helpdesk=1  ;
                      gameportal=0 ;

                        // printf("done2\n") ;
                  }

                  if(mx >= 60 && mx <= 160 && my >= midh && my <= midh+30 && inputmode == 0 && calldead==1)
		          {
		               if(playsfx)
		                PlaySound("button-3.wav" , NULL , SND_ASYNC ) ;
			inputmode = 1;
		          }




            }




            if(gameportal)
            {
                 if(mx>=1400 && mx<=1450 && my >= height-50 && my<=height  )
                 {
                     startgame=0 ;
     gameportal=0 ;
     helpdesk=1 ;
     paused=1 ;
     psec=second ;
     rstart=0 ;
     showreturn=1;
                 }






            }




	}




	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	    if(gameportal==1 && helpdesk==0 && startgame==0)
        {

          if(mx>0 && mx<width)
               {
                   startgame=1 ;
                   angle=45 ;
               }
        }
















	}



}
 int len  = 0  ;
void gamesave() ;
void iKeyboard(unsigned char key)
{
if(key==' ')
 {

     if(helpdesk==0 && gameportal)
     {
         spacecount++ ;
          if(startgame==0)
        startgame=1 ;
        if(spacecount==1)
     startsec=second ;
     else
        second=psec  ;
        angle=45 ;
     }


 }

 //I have clicked on paused button , now saving all the files
 if(key=='p'||key=='P')
 {
     startgame=0 ;
     gameportal=0 ;
     helpdesk=1 ;
     paused=1 ;
     psec=second ;
     rstart=0 ;
     showreturn=1;


 }
if(key=='q'||key=='Q')
{
    gameportal=0 ;
    startgame=0 ;
    helpdesk=1 ;
    wanna=1 ;
}





  if(inputmode==1)

{


    int k =0;
    if(key!='\r')
        {
            if (key == 8 )
	 {
	     k++ ;
        str[len-1] = 32 ;
        if(len>0)
        len-- ;

	 }

		else
		{
			str[len] = key;
			len++;

			nameboxx+=5 ;
		}
     }

	else
    {
        lost=1 ;
        bi=1 ;
     FILE* fp=fopen("high score.txt","r");
 struct game  player[11] = {0} ;
           int i=-1 ;
            while(1)
            {
                    i++;
                fscanf(fp,"%d %[^\n]",&player[i].data  , player[i].name);

                if(feof(fp))break;
            }
            fclose(fp);
            player[i].data = finalresult;
            strcpy(player[i].name,str);
            sortn(player , 11 );


    //for(int j=0;j<10;j++)printf("%d %s\n",player[j].data , player[j].name);


fp=fopen("high score.txt","w");
            for(i=0;i<10;i++)
            {
                fprintf(fp,"%d %s\n",player[i].data , player[i].name);
                fflush(fp) ;
            }
            fclose(fp);









    }






}


}

void gamesave()
{
    savedgame  = 1 ;
    FILE *fp=fopen("savegame.txt" , "w") ;
     fprintf(fp , "%d %d %d %d %d %d %lf %d %d %d %d %d %d %d %d %d " , spacecount , score , currentbrick , life , sline , modefire , velocity , radius , xpos , ypos , xboard , yboard , xxboard , yyboard , boxhit , cp  ) ;
//      printf("ssjsjsjsj %d %d %d\n",actime,second,startsec) ;
     for ( int i = 0  ; i<totalbricks ; i++)
     fprintf(fp , "%d " , box[i].boxpower) ;
      for ( int i = 0  ; i<totalbricks ; i++)
     fprintf(fp , "%d " , box[i].showbrick) ;
  for(int e=0 ; e<=12 ; e++)
    fprintf(fp , "%d " , callpower[e]) ;
       for ( int i = 0  ; i<totalbricks ; i++)
       {
           if(i%12==0)
           {
                   fprintf(fp , "%d %d %d %d " , box[i].dpx , box[i].dpy  , box[i].dpp  , box[i].dpn) ;
           }

       }

fclose(fp)  ;


fclose(fp)  ;

FILE *fp3= fopen("timer.txt","w") ;
fprintf(fp3,"%d %d %d",second,actime,startsec) ;
fclose(fp3) ;




}















void iSpecialKeyboard(unsigned char key)
{

 if(key==GLUT_KEY_RIGHT)
 {
     if(xboard<width-xxboard)
       xboard+=boardspeed;
    if(!startgame && xpos<width-xxboard/2)
       xpos+=boardspeed ;

 }
 if(key==GLUT_KEY_LEFT)
 {
     if(xboard>0)
       xboard-=boardspeed ;
    if(!startgame && xpos>xxboard/2)
        xpos-=boardspeed;

 }

if(key==GLUT_KEY_F2 && startgame ==0 && gameportal==1)
    bgcounter++ ;

if(key==GLUT_KEY_F3 && startgame ==0 && gameportal==1)

{
     blockrandcol++ ;
//     printf("%d\n",blockrandcol)  ;
}



}

void timer()
{

   t+=50  ;

    if(t%1000==0)second++ ;
}
void musicon()
{
    PlaySound((LPCSTR)"actbgm.wav" , NULL , SND_FILENAME|SND_ASYNC) ;
}
void musicoff()
{
    PlaySound((LPCSTR)NULL, NULL , SND_FILENAME|SND_ASYNC) ;
}
int main()
{
   valueofbricks() ;
    /*
    if(playmusic1==1)
    {
        musicon() ;
    }
    else
        musicoff()  ;
*/

iSetTimer(50 , timer) ;
   iSetTimer(20 , moveball) ;

	iInitialize(width , height  , "dxball demo");

	return 0;
}
