#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "choice.h"

using namespace std;

int getch()
{
   struct termios tm, tm_old;
   int fd = STDIN_FILENO,c;

   if (tcgetattr(fd, &tm) < 0)
   {
      return -1;
   }

   tm_old = tm;
   cfmakeraw(&tm);

   if (tcsetattr(fd, TCSANOW, &tm) < 0)
   {
      return -1;
   }

   c = fgetc(stdin);

   if (tcsetattr(fd,TCSANOW,&tm_old) < 0)
   {
      return -1;
   }

   return c;
}

void press_key()
{
   printf("Press enter to continue...\n");
   getch();
}

struct player{
    string army;
    string weapon;
    int armynum;
    bool ground;


};

struct boss{
    string name;
    string Boom;
    int blood;
    int kill;
    bool ground;
};
struct event{
    string object;
    string oper;
    int bywhat;
    string picture[16];

};

void showtime(string w){
    system("clear");

    cout<<"      333333333333333   "<<endl;
    cout<<"     3:::::::::::::::33 " <<endl;
    cout<<"     3::::::33333::::::3" <<endl;
    cout<<"     3333333     3:::::3" <<endl;
    cout<<"                 3:::::3" <<endl;
    cout<<"                 3:::::3" <<endl;
    cout<<"         33333333:::::3 " <<endl;
    cout<<"         3:::::::::::3  " <<endl;
    cout<<"         33333333:::::3 " <<endl;
    cout<<"                 3:::::3" <<endl;
    cout<<"                 3:::::3" <<endl;
    cout<<"                 3:::::3" <<endl;
    cout<<"     3333333     3:::::3" <<endl;
    cout<<"     3::::::33333::::::3" <<endl;
    cout<<"     3:::::::::::::::33 " <<endl;
    cout<<"      333333333333333   " <<endl;

    sleep(1);
    system("clear");

    cout<<"      222222222222222    " <<endl; 
    cout<<"     2:::::::::::::::22  " <<endl; 
    cout<<"     2::::::222222:::::2 " <<endl; 
    cout<<"     2222222     2:::::2 " <<endl; 
    cout<<"                 2:::::2 " <<endl; 
    cout<<"                 2:::::2 " <<endl; 
    cout<<"              2222::::2  " <<endl; 
    cout<<"         22222::::::22   " <<endl; 
    cout<<"       22::::::::222     " <<endl; 
    cout<<"      2:::::22222        " <<endl; 
    cout<<"     2:::::2             " <<endl; 
    cout<<"     2:::::2             " <<endl; 
    cout<<"     2:::::2       222222" <<endl; 
    cout<<"     2::::::2222222:::::2" <<endl; 
    cout<<"     2::::::::::::::::::2" <<endl; 
    cout<<"     22222222222222222222" <<endl; 
                    
    sleep(1);
    system("clear");

    cout<<"           1111111       "<<endl;
    cout<<"          1::::::1       "<<endl;
    cout<<"         1:::::::1       "<<endl;
    cout<<"         111:::::1       "<<endl;
    cout<<"            1::::1       "<<endl;
    cout<<"            1::::1       "<<endl;
    cout<<"            1::::1       "<<endl;
    cout<<"            1::::l       "<<endl;
    cout<<"            1::::l       "<<endl;
    cout<<"            1::::l       "<<endl;
    cout<<"            1::::l       "<<endl;
    cout<<"            1::::l       "<<endl;
    cout<<"         111::::::111    "<<endl;
    cout<<"         1::::::::::1    "<<endl;
    cout<<"         1::::::::::1    "<<endl;
    cout<<"         111111111111    "<<endl;

    sleep(1);
    system("clear");
    
    cout<<".----------------.  .----------------.  .----------------.  .----------------.  .----------------. "<<endl;
    cout<<"| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" <<endl;
    cout<<"| |    _______   | || |  _________   | || |      __      | || |  _______     | || |  _________   | |" <<endl;
    cout<<"| |   /  ___  |  | || | |  _   _  |  | || |     /  \\     | || | |_   __ \\    | || | |  _   _  |  | |" <<endl;
    cout<<"| |  |  (__ \\_|  | || | |_/ | | \\_|  | || |    / /\\ \\    | || |   | |__) |   | || | |_/ | | \\_|  | |" <<endl;
    cout<<"| |   '.___`-.   | || |     | |      | || |   / ____ \\   | || |   |  __ /    | || |     | |      | |" <<endl;
    cout<<"| |  |`\\____) |  | || |    _| |_     | || | _/ /    \\ \\_ | || |  _| |  \\ \\_  | || |    _| |_     | |" <<endl;
    cout<<"| |  |_______.'  | || |   |_____|    | || ||____|  |____|| || | |____| |___| | || |   |_____|    | |" <<endl;
    cout<<"| |              | || |              | || |              | || |              | || |              | |" <<endl;
    cout<<"| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" <<endl;
    cout<<" '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " <<endl;
    sleep(2);
}
//tell the time

void changearmynum(player &a, double factor){
    a.armynum=a.armynum+factor;
}
void roadbonus(player &a, string oper, int by){
if(oper=="+")a.armynum=a.armynum+by;
if(oper=="-")a.armynum=a.armynum-by;
if(oper=="*")a.armynum=a.armynum*by;
if(oper=="/")a.armynum=a.armynum/by;
if(a.armynum<1)a.armynum=1;
}
void seekbest(int &a,string oper,int by){
    if(oper=="+")a=a+by;
    if(oper=="-")a=a-by;
    if(oper=="*")a=a*by;
    if(oper=="/")a=a/by;
    if(a<1)a=1;
}
void showinfo(player &a){
    cout <<"You have "<<a.armynum<<" "<<a.army<<"s"<<endl;
}

void showbossinfo(boss &a){
    cout<<"This is the "<<endl;
}

int getVal(int defaultValue)
{
    int val = 0;
    thread t1([&]() {
        cin.clear();
        //while (cin.get() != '\n'){
        //    continue;
        //}
        cin.ignore();
        //cin.sync();
        cin >> val;
        if (val != 0)
        {   return val;
            //printf("get value:%d\n", val); why cancelling this line make the program work?...
            exit(0);
        }
        return val;
    });

    this_thread::sleep_for(chrono::seconds(2));
    //t1.detach();
    return val;
}

int chooseroad(player &a){
    int val1,val2,val3;
    sleep(1);
    cout << "You have six seconds to decide" << endl;
    val1=getVal(0);
    if (val1==0){
        
        cout << "Four seconds to go!" <<endl;
        val2=getVal(0);
        if (val2==0){
            
            cout << "Two seconds to go!" <<endl;
            val3=getVal(0);
            if (val3==0){
                cout << "Exceed time.You are automatically assigned the left road." << endl;
                changearmynum(a,-1);
                cout<<"As punishment, your army decreases by 1."<<endl;
                return 1;
            }
            else{
                if (val3==1)cout<<"You have chosen the left road."<<endl;
                else cout<<"You have chosen the right road."<<endl;
                return val3;
            }
        }
        else{
            if (val2==1)cout<<"You have chosen the left road."<<endl;
            else cout<<"You have chosen the right road."<<endl;
            return val2;
        }
    }
    else{
        if (val1==1)cout<<"You have chosen the left road."<<endl;
        else cout<<"You have chosen the right road."<<endl;
        return val1;
    }
}

void sbpart(player &a,string b,event eventlist[],int &best){
    system("clear");
    int left ,right,t,k;
    if (b=="add"){
        t=6;
        k=0;
    }
    if (b=="diminish"){
        t=6;
        k=6;
    }
    if (b=="all"){
        t=12;
        k=0;
    }
    left=(rand()%t)+k;
    right=(rand()%t)+k;
    if (right==left){
        right=(rand()%t)+k;
    }
    for (int i=0;i<16;i++){
        cout<<eventlist[left].picture[i];
        cout<<"     ||     ";
        cout<<eventlist[right].picture[i]<<endl;
        
    }
    int choicer;
    choicer=chooseroad(a);
    if (choicer==1){
        roadbonus(a,eventlist[left].oper,eventlist[left].bywhat);
    }
    else{
        roadbonus(a,eventlist[right].oper,eventlist[right].bywhat);
    }
    int b1=0,b2=0;
    b1=best;
    b2=best;
    seekbest(b1,eventlist[left].oper,eventlist[left].bywhat);
    seekbest(b2,eventlist[right].oper,eventlist[right].bywhat);
    if (b1>=b2){
        seekbest(best,eventlist[left].oper,eventlist[left].bywhat);
    }
    else{
        seekbest(best,eventlist[right].oper,eventlist[right].bywhat);
    }
    showinfo(a);
    sleep(2);
}   
void idiotpart(player &a,boss bosslist[]){
    int bossNo;
    bossNo=rand()%6;
    showbossinfo(bosslist[bossNo]);
    cout<<"DO you want to challenge "<<bosslist[bossNo].name<<endl;
    cout<<"Print y to challenge. Print n to escape"<<endl;
    string yesno;
    cin.clear();
    cin.ignore();
    cin>>yesno;
    cout<<yesno;
    if (yesno=="y"){
        cout<<"You met"<<bosslist[bossNo].name<<endl;
        int kil;
        kil=bosslist[bossNo].kill;
        changearmynum(a,-kil);
        cout<<"After fighting"<<"You lost "<<kil<<a.army<<"s"<<endl;
        showinfo(a);
        a.weapon=bosslist[bossNo].Boom;
    }

}

bool choice(){
    boss bosslist[7]={
        {"Barbarian King","Golden Sword",500,5,true},
        {"Mountain Golem","The Heart of the Mountain",2000,4,true},
        {"Dragon","The wish of the princess",500,7,false},      //Dragon slayer sword
        {"Minion Scourge","elixir",500,8,false},
        {"Goblin Tyrant","Sneaky gloves",500,9,true},
        {"TAOTIE","The mouth of abyss",500,15,true},
        {"XiaoHeiZi","Dancing Claw",30,3,false}
    };

    player playerlist[4]={
        {"hogriders","no weapon",1,true},
        {"Kunzhiyin","no weapon",1,false},
        {"loong","no weapon",1,false},
        {"dementors","no weapon",1,true}
    };  

    event eventlist[12]={
        {"army","*",3,{"                     333333333333333   ",
"                    3:::::::::::::::33 ",
"                    3::::::33333::::::3",
"                    3333333     3:::::3",
"xxxxxxx      xxxxxxx            3:::::3",
" x:::::x    x:::::x             3:::::3",
"  x:::::x  x:::::x      33333333:::::3 ",
"   x:::::xx:::::x       3:::::::::::3  ",
"    x::::::::::x        33333333:::::3 ",
"     x::::::::x                 3:::::3",
"     x::::::::x                 3:::::3",
"    x::::::::::x                3:::::3",
"   x:::::xx:::::x   3333333     3:::::3",
"  x:::::x  x:::::x  3::::::33333::::::3",
" x:::::x    x:::::x 3:::::::::::::::33 ",
"xxxxxxx      xxxxxxx 333333333333333   "}},
        {"army","+",3,{"                      333333333333333   ",
"                     3:::::::::::::::33 ",
"                     3::::::33333::::::3",
"       +++++++       3333333     3:::::3",
"       +:::::+                   3:::::3",
"       +:::::+                   3:::::3",
" +++++++:::::+++++++     33333333:::::3 ",
" +:::::::::::::::::+     3:::::::::::3  ",
" +:::::::::::::::::+     33333333:::::3 ",
" +++++++:::::+++++++             3:::::3",
"       +:::::+                   3:::::3",
"       +:::::+                   3:::::3",
"       +++++++       3333333     3:::::3",
"                     3::::::33333::::::3",
"                     3:::::::::::::::33 ",
"                      333333333333333   "}},
        {"army","*",2,{"                     222222222222222    ",
"                    2:::::::::::::::22  ",
"                    2::::::222222:::::2 ",
"                    2222222     2:::::2 ",
"xxxxxxx      xxxxxxx            2:::::2 ",
" x:::::x    x:::::x             2:::::2 ",
"  x:::::x  x:::::x           2222::::2  ",
"   x:::::xx:::::x       22222::::::22   ",
"    x::::::::::x      22::::::::222     ",
"     x::::::::x      2:::::22222        ",
"     x::::::::x     2:::::2             ",
"    x::::::::::x    2:::::2             ",
"   x:::::xx:::::x   2:::::2       222222",
"  x:::::x  x:::::x  2::::::2222222:::::2",
" x:::::x    x:::::x 2::::::::::::::::::2",
"xxxxxxx      xxxxxxx22222222222222222222"}},
        {"army","+",2,{"                      222222222222222    ",
"                     2:::::::::::::::22  ",
"                     2::::::222222:::::2 ",
"       +++++++       2222222     2:::::2 ",
"       +:::::+                   2:::::2 ",
"       +:::::+                   2:::::2 ",
" +++++++:::::+++++++          2222::::2  ",
" +:::::::::::::::::+     22222::::::22   ",
" +:::::::::::::::::+   22::::::::222     ",
" +++++++:::::+++++++  2:::::22222        ",
"       +:::::+       2:::::2             ",
"       +:::::+       2:::::2             ",
"       +++++++       2:::::2       222222",
"                     2::::::2222222:::::2",
"                     2::::::::::::::::::2",
"                     22222222222222222222"}},
        {"army","*",5,{"                    555555555555555555 ",
"                    5::::::::::::::::5 ",
"                    5::::::::::::::::5 ",
"                    5:::::555555555555 ",
"xxxxxxx      xxxxxxx5:::::5            ",
" x:::::x    x:::::x 5:::::5            ",
"  x:::::x  x:::::x  5:::::5555555555   ",
"   x:::::xx:::::x   5:::::::::::::::5  ",
"    x::::::::::x    555555555555:::::5 ",
"     x::::::::x                 5:::::5",
"     x::::::::x                 5:::::5",
"    x::::::::::x    5555555     5:::::5",
"   x:::::xx:::::x   5::::::55555::::::5",
"  x:::::x  x:::::x   55:::::::::::::55 ",
" x:::::x    x:::::x    55:::::::::55   ",
"xxxxxxx      xxxxxxx     555555555     "}},
        {"army","*",6,{"                            66666666   ",
"                           6::::::6    ",
"                          6::::::6     ",
"                         6::::::6      ",
"xxxxxxx      xxxxxxx    6::::::6       ",
" x:::::x    x:::::x    6::::::6        ",
"  x:::::x  x:::::x    6::::::6         ",
"   x:::::xx:::::x    6::::::::66666    ",
"    x::::::::::x    6::::::::::::::66  ",
"     x::::::::x     6::::::66666:::::6 ",
"     x::::::::x     6:::::6     6:::::6",
"    x::::::::::x    6:::::6     6:::::6",
"   x:::::xx:::::x   6::::::66666::::::6",
"  x:::::x  x:::::x   66:::::::::::::66 ",
" x:::::x    x:::::x    66:::::::::66   ",
"xxxxxxx      xxxxxxx     666666666     "}},
        {"army","-",2,{"                  222222222222222    ",
"                 2:::::::::::::::22  ",
"                 2::::::222222:::::2 ",
"                 2222222     2:::::2 ",
"                             2:::::2 ",
"                             2:::::2 ",
"                          2222::::2  ",
" ---------------     22222::::::22   ",
" -:::::::::::::-   22::::::::222     ",
" ---------------  2:::::22222        ",
"                 2:::::2             ",
"                 2:::::2             ",
"                 2:::::2       222222",
"                 2::::::2222222:::::2",
"                 2::::::::::::::::::2",
"                 22222222222222222222"}},
        {"army","/",3,{"               /////// 333333333333333   ",
"              /:::::/ 3:::::::::::::::33 ",
"             /:::::/  3::::::33333::::::3",
"            /:::::/   3333333     3:::::3",
"           /:::::/                3:::::3",
"          /:::::/                 3:::::3",
"         /:::::/          33333333:::::3 ",
"        /:::::/           3:::::::::::3  ",
"       /:::::/            33333333:::::3 ",
"      /:::::/                     3:::::3",
"     /:::::/                      3:::::3",
"    /:::::/                       3:::::3",
"   /:::::/            3333333     3:::::3",
"  /:::::/             3::::::33333::::::3",
" /:::::/              3:::::::::::::::33 ",
"///////                333333333333333   "}},
        {"army","/",2,{"               /////// 222222222222222    ",
"              /:::::/ 2:::::::::::::::22  ",
"             /:::::/  2::::::222222:::::2 ",
"            /:::::/   2222222     2:::::2 ",
"           /:::::/                2:::::2 ",
"          /:::::/                 2:::::2 ",
"         /:::::/               2222::::2  ",
"        /:::::/           22222::::::22   ",
"       /:::::/          22::::::::222     ",
"      /:::::/          2:::::22222        ",
"     /:::::/          2:::::2             ",
"    /:::::/           2:::::2             ",
"   /:::::/            2:::::2       222222",
"  /:::::/             2::::::2222222:::::2",
" /:::::/              2::::::::::::::::::2",
"///////               22222222222222222222"}},
        {"army","-",6,{"                         66666666   ",
"                        6::::::6    ",
"                       6::::::6     ",
"                      6::::::6      ",
"                     6::::::6       ",
"                    6::::::6        ",
"                   6::::::6         ",
" ---------------  6::::::::66666    ",
" -:::::::::::::- 6::::::::::::::66  ",
" --------------- 6::::::66666:::::6 ",
"                 6:::::6     6:::::6",
"                 6:::::6     6:::::6",
"                 6::::::66666::::::6",
"                  66:::::::::::::66 ",
"                    66:::::::::66   ",
"                      666666666     "}},
        {"army","-",5,{"                 555555555555555555 ",
"                 5::::::::::::::::5 ",
"                 5::::::::::::::::5 ",
"                 5:::::555555555555 ",
"                 5:::::5            ",
"                 5:::::5            ",
"                 5:::::5555555555   ",
" --------------- 5:::::::::::::::5  ",
" -:::::::::::::- 555555555555:::::5 ",
" ---------------             5:::::5",
"                             5:::::5",
"                 5555555     5:::::5",
"                 5::::::55555::::::5",
"                  55:::::::::::::55 ",
"                    55:::::::::55   ",
"                      555555555     "}},
        {"army","-",4,{"                        444444444  ",
"                       4::::::::4  ",
"                      4:::::::::4  ",
"                     4::::44::::4  ",
"                    4::::4 4::::4  ",
"                   4::::4  4::::4  ",
"                  4::::4   4::::4  ",
" --------------- 4::::444444::::444",
" -:::::::::::::- 4::::::::::::::::4",
" --------------- 4444444444:::::444",
"                           4::::4  ",
"                           4::::4  ",
"                           4::::4  ",
"                         44::::::44",
"                         4::::::::4",
"                         4444444444"}}
    };


                    
 
    cout<<" █     █░▓█████  ██▓     ▄████▄   ▒█████   ███▄ ▄███▓▓█████ " <<endl;
    cout<<"▓█░ █ ░█░▓█   ▀ ▓██▒    ▒██▀ ▀█  ▒██▒  ██▒▓██▒▀█▀ ██▒▓█   ▀ " <<endl;
    cout<<"▒█░ █ ░█ ▒███   ▒██░    ▒▓█    ▄ ▒██░  ██▒▓██    ▓██░▒███   " <<endl;
    cout<<"░█░ █ ░█ ▒▓█  ▄ ▒██░    ▒▓▓▄ ▄██▒▒██   ██░▒██    ▒██ ▒▓█  ▄ " <<endl;
    cout<<"░░██▒██▓ ░▒████▒░██████▒▒ ▓███▀ ░░ ████▓▒░▒██▒   ░██▒░▒████▒" <<endl;
    cout<<"░ ▓░▒ ▒  ░░ ▒░ ░░ ▒░▓  ░░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░   ░  ░░░ ▒░ ░" <<endl;
    cout<<"  ▒ ░ ░   ░ ░  ░░ ░ ▒  ░  ░  ▒     ░ ▒ ▒░ ░  ░      ░ ░ ░  ░" <<endl;
    cout<<"  ░   ░     ░     ░ ░   ░        ░ ░ ░ ▒  ░      ░      ░   " <<endl;
    cout<<"    ░       ░  ░    ░  ░░ ░          ░ ░         ░      ░  ░" <<endl;
    cout<<"                        ░                                   " <<endl;
    sleep(2);
    system("clear");
    cout<<" "<<endl;
    cout<<"This trial test your ability to seize the fleeting opportunity."<<endl;
    press_key();
    
    //complete story
    cout<< "Now, choose your army first."<<endl;
    cout<< "Press 0, you get: hogriders"<<endl;
    cout<< "Press 1, you get: KunZhiyin"<<endl;
    cout<< "Press 2, you get: loong"<<endl;
    cout<< "Press 3, you get: dementors"<<endl;
            //complete army briefing
    int nu;
    cin>>nu;
    cout<< "You have choose "<<playerlist[nu].army<<endl;
    //playerlist[nu]
    cout<<"You step on the road to royal. From now on, you will encounter multiple opportunities."<<endl;
    cout<<"For each opportunity, two road with different events will be given. Try your best to expand your army!"<<endl;
    cout <<"Enter 1, you will choose the left road." << endl;
    cout <<"Enter any other number, you will choose the right road." << endl;
    cout <<"If you entered a character, you will be regarded as inputting nothing and thus get the exceed-time punishment. " << endl;
    char chrubbish;
    while((chrubbish=getchar())!='\n' && chrubbish!=EOF);
    sleep(5);
    press_key();
    showtime("start");
    //
    //
    //
    //
    int best;
    best=1;
    sbpart(playerlist[nu],"add",eventlist,best);
    sbpart(playerlist[nu],"add",eventlist,best);
    sbpart(playerlist[nu],"diminish",eventlist,best);
    sbpart(playerlist[nu],"add",eventlist,best);
    sbpart(playerlist[nu],"add",eventlist,best);
    sbpart(playerlist[nu],"diminish",eventlist,best);
    sbpart(playerlist[nu],"all",eventlist,best);
    sbpart(playerlist[nu],"add",eventlist,best);
    sbpart(playerlist[nu],"all",eventlist,best);
    sbpart(playerlist[nu],"add",eventlist,best);
    
    //idiotpart(playerlist[nu],bosslist);
    cout<<"The best you can do is "<<best<<playerlist[nu].army<<endl;
    double per,now;
    now=playerlist[nu].armynum;
    per=(double)now/(double)best;
    if(nu==1){
        cout<<"HAHA!Kunzhiyin is a useless creature and by no means can be your army. You fail!"<<endl;
        cout<<"You know~~~, choice is way more important than effort!"<<endl;
        return false;
    }
    if (per<0.2){
        cout<<"You havent even achieve 20%!\nYou failed! "<<endl;
        return false;
    }
    else{
        cout<<"Good job!"<<endl;
        return true;
    }
    //if(playerlist[nu].armynum>0){
    //    cout<<"You have successfully saved the crown of ?????????????????. You passed the trial of breaveness!"<<endl;
    //    return true;
    //}
    //else{
    //    cout<<"You failed...Errr..."<<endl;
    //    return false;
    //}
}
