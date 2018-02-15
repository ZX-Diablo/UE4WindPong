// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongPad.h"

#include "Camera/CameraComponent.h"

#include "Components/BoxComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"

#include "ConstructorHelpers.h"

#include "GameFramework/SpringArmComponent.h"

#include "Public/UE4WindPongBall.h"
#include "Public/UE4WindPongPlayerControllerGame.h"

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

	this->SpringArm = this->CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	this->SpringArm->SetupAttachment(this->RootComponent);
	this->SpringArm->SetWorldRotation(FRotator(this->CameraAngle, 0.0f, 0.0f));
	this->SpringArm->TargetArmLength = this->CameraDistance;
	this->SpringArm->bDoCollisionTest = false;
	this->SpringArm->bEnableCameraLag = false;
	this->SpringArm->bEnableCameraRotationLag = false;
	this->SpringArm->bUsePawnControlRotation = false;
	this->SpringArm->bInheritPitch = false;
	this->SpringArm->bInheritYaw = false;
	this->SpringArm->bInheritRoll = false;

	this->Camera = this->CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	this->Camera->SetupAttachment(this->SpringArm, USpringArmComponent::SocketName);
	this->Camera->bUsePawnControlRotation = false;
}

void AUE4WindPongPad::SetupPlayerInputComponent (UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("TurnForward", this, &AUE4WindPongPad::TurnForward);
	PlayerInputComponent->BindAxis("TurnRight", this, &AUE4WindPongPad::TurnRight);
}

void AUE4WindPongPad::BeginPlay ()
{
	Super::BeginPlay();

	this->OnActorHit.AddDynamic(this, &AUE4WindPongPad::OnHitByBall);
}

void AUE4WindPongPad::TurnForward (float AxisValue)
{
	FRotator NewRotation = this->GetActorRotation();

	NewRotation.Pitch = FMath::ClampAngle(NewRotation.Pitch - AxisValue, -this->TurnAngleLimit, this->TurnAngleLimit);

	this->SetActorRotation(NewRotation);
}

void AUE4WindPongPad::TurnRight (float AxisValue)
{
	FRotator NewRotation = this->GetActorRotation();

	NewRotation.Roll = FMath::ClampAngle(NewRotation.Roll + AxisValue, -this->TurnAngleLimit, this->TurnAngleLimit);

	this->SetActorRotation(NewRotation);
}

void AUE4WindPongPad::OnHitByBall (AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	auto PlayerController = Cast<AUE4WindPongPlayerControllerGame>(this->GetController());

	if (PlayerController && Cast<AUE4WindPongBall>(OtherActor))
	{
		PlayerController->HitByBall();
	}
}
