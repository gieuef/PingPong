//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
         ball->Left+= x;
        ball->Top+= y;

        if (ball->Left - 5 <= 0) x= -x;

        if (ball->Left +ball->Width +5 >= background->Width) x= -x;

        if (ball->Top - 5 <= 0) y= -y;

        if (ball->Top + ball->Height + 5 >= background->Height) y= -y;
}
//---------------------------------------------------------------------------
