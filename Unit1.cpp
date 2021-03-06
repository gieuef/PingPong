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

int leftScore = 0;
int rightScore = 0;

int count = 0;


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

        if (ball->Top - 5 <= 0) y= -y;

        if (ball->Top + ball->Height + 5 >= background->Height) y= -y;

         if (ball->Left + ball->Width + 5 <= paddle1->Left + paddle1->Width)
        {
                rightScore ++;

                TimerBall->Enabled = false;
                ball->Visible = false;
                LabelWelcome->Caption = " Punkt dla gracza prawego >";
                LabelScore->Caption = IntToStr(leftScore) + " : "+ IntToStr(rightScore);
                LabelScore->Visible = true;

                LabelCount->Caption = "Ilosc odbic :" + IntToStr(count);
                LabelCount->Visible = true;

                LabelWelcome->Visible = true;
                ButtonNewGame->Visible = true;
                ButtonNewGame->Enabled = true;

                ButtonNewRound->Visible = true;

        } else if (ball->Top > paddle1->Top - ball->Height/2 && ball->Top < paddle1->Top + paddle1->Height &&
                ball->Left < paddle1->Left + paddle1->Width )
               {
                   count ++;

                   if (x<0) x= - x;


                   if (ball->Top + ball->Height/2 >= paddle1->Top + paddle1->Height/2 - 25
                   && ball->Top + ball->Height/2 <= paddle1->Top + paddle1->Height/2 +25)
                   {
                   if (TimerBall->Interval - 5 > 0) TimerBall->Interval-=3;

                   }   else TimerBall->Interval = 18;


               }

         if (ball->Left >= paddle2->Left +5)
         {
                leftScore ++;

                TimerBall->Enabled = false;
                ball->Visible = false;
                LabelWelcome->Caption = "< Punkt dla gracza lewego";
                LabelScore->Caption = IntToStr(leftScore) + " : "+ IntToStr(rightScore);
                LabelScore->Visible = true;

                LabelCount->Caption = "Ilosc odbic :" + IntToStr(count);
                LabelCount->Visible = true;

                LabelWelcome->Visible = true;
                ButtonNewGame->Visible = true;
                ButtonNewGame->Enabled = true;

                ButtonNewRound->Visible = true;

         } else if (ball->Top > paddle2->Top - ball->Height/2 && ball->Top < paddle2->Top + paddle2->Height &&
                ball->Left + ball->Width > paddle2->Left )
               {
                count ++;

                if (x>0) x= - x;


                if (ball->Top + ball->Height/2 >= paddle2->Top + paddle2->Height/2 - 25
                   && ball->Top + ball->Height/2 <= paddle2->Top + paddle2->Height/2 +25)
                   {
                   if (TimerBall->Interval - 5 > 0) TimerBall->Interval-=3;

                   }  else TimerBall->Interval = 18;


               }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1UpTimer(TObject *Sender)
{
       if (paddle1->Top >10)   paddle1->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddle1DownTimer(TObject *Sender)
{
      if (paddle1->Top + paddle1->Height  < background->Height - 10)  paddle1->Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddle2UpTimer(TObject *Sender)
{
       if (paddle2->Top >10)   paddle2->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddle2DownTimer(TObject *Sender)
{
       if (paddle2->Top + paddle2->Height  < background->Height -10)   paddle2->Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      if (Key == 0x41) paddle1Up->Enabled = false;
        if (Key == 0x5A) paddle1Down->Enabled = false;
        if (Key == VK_UP) paddle2Up->Enabled = false;
        if (Key == VK_DOWN) paddle2Down->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
       if (Key == 0x41) paddle1Up->Enabled = true;
        if (Key == 0x5A) paddle1Down->Enabled = true;
        if (Key == VK_UP) paddle2Up->Enabled = true;
        if (Key == VK_DOWN) paddle2Down->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ButtonNewGameClick(TObject *Sender)
{
        count = 0;
        ball->Top = 500;
        ball->Left = 500;
        ball->Visible = true;
        TimerBall->Interval = 20;
        TimerBall->Enabled = true;
        LabelCount->Visible = false;
    LabelWelcome->Visible = false;
    ButtonNewGame->Visible = false;
    LabelScore->Visible = false;
    ButtonNewRound->Visible = false;

    leftScore =0;
    rightScore = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   ShowMessage("Witaj w grze PingPong.\n\n"
                 "Lewy gracz steruje wciskaj�c A oraz Z.\n"
                 "Prawy gracz steruje wciskaj�c strza�ki do g�ry i w d�.\n\n"
                 "Dla urozmaicenia zabawy:\n"
                 "Kiedy odbijesz pi�k� na srodku paletki, w�wczas pi�ka przyspieszy\n"
                 "Im d�u�ej odbijasz, tym pi�ka szybciej si� przemieszcza.\n\n"
                 "Mi�ej zabawy!.");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNewRoundClick(TObject *Sender)
{
      count = 0;
       ball->Top = 500;
        ball->Left = 500;
        ball->Visible = true;
        TimerBall->Interval = 20;
        TimerBall->Enabled = true;
        LabelCount->Visible = false;
    LabelWelcome->Visible = false;
    ButtonNewGame->Visible = false;
    LabelScore->Visible = false;
    ButtonNewRound->Visible = false;
}
//---------------------------------------------------------------------------

