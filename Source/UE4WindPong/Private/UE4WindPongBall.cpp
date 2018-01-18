// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongBall.h"

AUE4WindPongBall::AUE4WindPongBall ()
{
	this->PrimaryActorTick.bCanEverTick = true;
}

void AUE4WindPongBall::Tick (float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUE4WindPongBall::BeginPlay ()
{
	Super::BeginPlay();
}
