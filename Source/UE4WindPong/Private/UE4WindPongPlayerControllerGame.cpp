// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongPlayerControllerGame.h"

#include "Engine/World.h"

#include "Kismet/GameplayStatics.h"

#include "UserWidget.h"

#include "Public/UE4WindPongGameModeBase.h"
#include "Public/UE4WindPongPlayerStateGame.h"

void AUE4WindPongPlayerControllerGame::RestartGame ()
{
	this->RestartLevel();
}

void AUE4WindPongPlayerControllerGame::ReturnToMainMenu ()
{
	UGameplayStatics::OpenLevel(this->GetWorld(), "MenuMap");
}

void AUE4WindPongPlayerControllerGame::HitByBall ()
{
	auto GameMode = this->GetWorld()->GetAuthGameMode<AUE4WindPongGameModeBase>();
	auto PlayerState = Cast<AUE4WindPongPlayerStateGame>(this->PlayerState);

	if (GameMode && PlayerState)
	{
		PlayerState->AddScore(GameMode->GetScorePerHit());
	}
}

void AUE4WindPongPlayerControllerGame::EndGame ()
{
	this->SetInputMode(FInputModeUIOnly());
	this->bShowMouseCursor = true;

	if (this->HighScoresModalClass)
	{
		this->HighScoresModal = CreateWidget<UUserWidget>(this, this->HighScoresModalClass);
		if (this->HighScoresModal)
		{
			this->HighScoresModal->AddToViewport();
		}
	}
}

void AUE4WindPongPlayerControllerGame::BeginPlay ()
{
	Super::BeginPlay();

	this->SetInputMode(FInputModeGameOnly());

	if (this->HUDClass)
	{
		this->HUD = CreateWidget<UUserWidget>(this, this->HUDClass);
		if (this->HUD)
		{
			this->HUD->AddToViewport();
		}
	}

	auto GameMode = this->GetWorld()->GetAuthGameMode<AUE4WindPongGameModeBase>();

	if (GameMode)
	{
		GameMode->StartRound();
	}
}
