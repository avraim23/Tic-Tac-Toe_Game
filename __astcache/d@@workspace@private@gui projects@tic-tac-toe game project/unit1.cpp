//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
char CurrectPlayerSymmbol = 'X' ;
void TForm1::disable()
{
	Button1->Enabled = false ;
	Button2->Enabled = false ;
	Button3->Enabled = false ;
	Button4->Enabled = false ;
	Button5->Enabled = false ;
	Button6->Enabled = false ;
	Button7->Enabled = false ;
	Button8->Enabled = false ;
	Button9->Enabled = false ;
}
bool TForm1::checkIsWinner ()
{
	if ( !Button1->Text.IsEmpty() && Button1->Text == Button2->Text && Button1->Text == Button3->Text )
	{
			return true ;
	}
	else if ( !Button4->Text.IsEmpty() && Button4->Text == Button5->Text && Button4->Text == Button6->Text )
	{
			return true ;
	}
	else if ( !Button7->Text.IsEmpty() && Button7->Text == Button8->Text && Button7->Text == Button9->Text )
	{
			return true ;
	}
	else if ( !Button1->Text.IsEmpty() && Button1->Text == Button4->Text && Button1->Text == Button7->Text )
	{
			return true ;
	}
	else if ( !Button2->Text.IsEmpty() && Button2->Text == Button5->Text && Button2->Text == Button8->Text )
	{
			return true ;
	}
	else if ( !Button3->Text.IsEmpty() && Button3->Text == Button6->Text && Button3->Text == Button9->Text )
	{
			return true ;
	}
	else if ( !Button1->Text.IsEmpty() && Button1->Text == Button5->Text && Button1->Text == Button9->Text )
	{
			return true ;
	}
	else if ( !Button3->Text.IsEmpty() && Button3->Text == Button5->Text && Button3->Text == Button7->Text )
	{
			return true ;
	}
	else
	{
		return false ;
	}
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	CurrentPlayerSymbolLabel->Text =  CurrectPlayerSymmbol ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonClick(TObject *Sender)
{
	TButton* CLickedBuitton = dynamic_cast<TButton*>(Sender) ;
	CLickedBuitton->Text = CurrectPlayerSymmbol ;
	CLickedBuitton->Enabled = false ;





	if (checkIsWinner())
	{
		WinnerLabel->Text = "YOU WON !!" ;
		disable() ;
		return ;
	}

	if ( CurrectPlayerSymmbol=='X' )
	{
		CurrectPlayerSymmbol = 'O' ;
	}
	else
	{
		CurrectPlayerSymmbol = 'X' ;
	}
	CurrentPlayerSymbolLabel->Text =  CurrectPlayerSymmbol ;
}
//---------------------------------------------------------------------------


