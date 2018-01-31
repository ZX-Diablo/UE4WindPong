// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongPlayerControllerMenu.h"

#include "UserWidget.h"

AUE4WindPongPlayerControllerMenu::AUE4WindPongPlayerControllerMenu ()
{
	this->bShowMouseCursor = true;
}

void AUE4WindPongPlayerControllerMenu::ShowMainMenu ()
{
	this->ShowMenuHelper(this->MainMenu);
}

void AUE4WindPongPlayerControllerMenu::ShowHighScoresMenu ()
{
	this->ShowMenuHelper(this->HighScoresMenu);
}

void AUE4WindPongPlayerControllerMenu::BeginPlay ()
{
	Super::BeginPlay();

	this->SetInputMode(FInputModeUIOnly());
	this->ShowMainMenu();
}

void AUE4WindPongPlayerControllerMenu::ShowMenuHelper (TSubclassOf<UUserWidget> Menu)
{
	if (Menu)
	{
		this->CloseCurrentMenu();

		this->CurrentMenu = CreateWidget<UUserWidget>(this, Menu);
		if (this->CurrentMenu)
		{
			this->CurrentMenu->AddToViewport();
		}
	}
}

void AUE4WindPongPlayerControllerMenu::CloseCurrentMenu ()
{
	if (this->CurrentMenu && this->CurrentMenu->IsInViewport())
	{
		this->CurrentMenu->RemoveFromViewport();
		this->CurrentMenu = nullptr;
	}
}
