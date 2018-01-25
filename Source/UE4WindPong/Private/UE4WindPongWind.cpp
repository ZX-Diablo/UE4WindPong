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

	TArray<AActor*> Balls;

	this->GetOverlappingActors(Balls, AUE4WindPongBall::StaticClass());
	for (const auto& Ball : Balls)
	{
		FVector WindVelocity = FMath::VRand();

		WindVelocity.Z = 0.0f;
		WindVelocity *= 5.0f;

		Cast<AUE4WindPongBall>(Ball)->AddWind(WindVelocity);
	}
}

void AUE4WindPongWind::BeginPlay ()
{
	Super::BeginPlay();
}
