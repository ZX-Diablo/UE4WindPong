// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongWind.h"

#include "Components/BoxComponent.h"

#include "Public/UE4WindPongBall.h"

AUE4WindPongWind::AUE4WindPongWind ()
{
	this->PrimaryActorTick.bCanEverTick = true;

	this->VolumeBox = this->CreateDefaultSubobject<UBoxComponent>(TEXT("VolumeBox"));
	this->VolumeBox->InitBoxExtent(this->VolumeBoxExtent);
	this->VolumeBox->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	this->RootComponent = this->VolumeBox;
}

void AUE4WindPongWind::Tick (float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (this->TimeElapsed <= 0)
	{
		this->CurrentVelocity = this->GenerateVelocity();
		this->CurrentDuration = this->GenerateDuration();
		this->TimeElapsed = this->CurrentDuration;
	}

	TArray<AActor*> Balls;

	this->GetOverlappingActors(Balls, AUE4WindPongBall::StaticClass());
	for (const auto& Ball : Balls)
	{
		Cast<AUE4WindPongBall>(Ball)->AddWind(this->CurrentVelocity);
	}

	this->TimeElapsed -= DeltaTime;
}

void AUE4WindPongWind::BeginPlay ()
{
	Super::BeginPlay();
}

FVector AUE4WindPongWind::GenerateVelocity () const
{
	FVector WindVelocity = FMath::VRand();
	float Strength = FMath::FRandRange(this->MinStrength, this->MaxStrength);

	WindVelocity *= Strength;
	WindVelocity.Z = 0.0f;

	return WindVelocity;
}

float AUE4WindPongWind::GenerateDuration () const
{
	return FMath::FRandRange(this->MinDuration, this->MaxDuration);
}
