// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongGameModeBase.h"

#include "Engine/World.h"

#include "Public/UE4WindPongPlayerControllerGame.h"
#include "Public/UE4WindPongPlayerStateGame.h"

void AUE4WindPongGameModeBase::PostLogin (APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	auto PlayerState = Cast<AUE4WindPongPlayerStateGame>(NewPlayer->PlayerState);

	if (PlayerState)
	{
		PlayerState->CurrentLives = this->MaximumLives;
	}
}

void AUE4WindPongGameModeBase::StartRound ()
{
	if (this->BallClass)
	{
		this->GetWorld()->SpawnActor(this->BallClass, &this->BallSpawnLocation);
	}
}

void AUE4WindPongGameModeBase::BallFellOutWorld ()
{
	auto PlayerController = this->GetWorld()->GetFirstPlayerController();
	auto PlayerState = Cast<AUE4WindPongPlayerStateGame>(PlayerController->PlayerState);

	if (PlayerState && PlayerState->CurrentLives > 0)
	{
		PlayerState->CurrentLives--;

		this->ResetLevel();
		this->RestartPlayer(PlayerController);

		this->StartRound();
	}
	else
	{
		Cast<AUE4WindPongPlayerControllerGame>(PlayerController)->EndGame();
	}
}
