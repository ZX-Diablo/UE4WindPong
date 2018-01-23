// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongPad.h"

#include "Camera/CameraComponent.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

#include "ConstructorHelpers.h"

AUE4WindPongPad::AUE4WindPongPad ()
{
	this->PrimaryActorTick.bCanEverTick = true;

	this->CollisionBox = this->CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	this->CollisionBox->InitBoxExtent(this->CollisionBoxExtent);
	this->CollisionBox->SetCollisionProfileName(TEXT("Pawn"));

	this->RootComponent = this->CollisionBox;

	this->StaticMesh = this->CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	this->StaticMesh->SetupAttachment(this->CollisionBox);

	ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMesh(TEXT("/Engine/BasicShapes/Cylinder"));

	if (CylinderMesh.Succeeded())
	{
		this->StaticMesh->SetStaticMesh(CylinderMesh.Object);
		this->StaticMesh->SetWorldScale3D(this->CollisionBoxExtent / this->CylinderBoundingBox);
	}

	this->Camera = this->CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	this->Camera->SetupAttachment(this->RootComponent);
	this->Camera->SetRelativeLocation(this->CameraLocation);
	this->Camera->SetRelativeRotation(FRotationMatrix::MakeFromX(this->CameraViewPoint - this->CameraLocation).Rotator());
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
