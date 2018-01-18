// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongWind.h"

AUE4WindPongWind::AUE4WindPongWind ()
{
	this->PrimaryActorTick.bCanEverTick = true;
}

void AUE4WindPongWind::Tick (float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUE4WindPongWind::BeginPlay ()
{
	Super::BeginPlay();
}
