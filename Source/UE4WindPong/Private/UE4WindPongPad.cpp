// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongPad.h"

AUE4WindPongPad::AUE4WindPongPad ()
{
	this->PrimaryActorTick.bCanEverTick = true;
}

void AUE4WindPongPad::Tick (float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUE4WindPongPad::SetupPlayerInputComponent (UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AUE4WindPongPad::BeginPlay ()
{
	Super::BeginPlay();
}
