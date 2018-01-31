// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongPlayerControllerGame.h"

#include "Engine/World.h"

#include "UserWidget.h"

#include "Public/UE4WindPongGameModeBase.h"
#include "Public/UE4WindPongPlayerStateGame.h"

void AUE4WindPongPlayerControllerGame::HitByBall ()
{
	auto GameMode = this->GetWorld()->GetAuthGameMode<AUE4WindPongGameModeBase>();
	auto PlayerState = Cast<AUE4WindPongPlayerStateGame>(this->PlayerState);

	if (GameMode && PlayerState)
	{
		PlayerState->AddScore(GameMode->GetScorePerHit());
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
