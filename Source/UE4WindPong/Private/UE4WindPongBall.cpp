// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongBall.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

#include "ConstructorHelpers.h"

#include "Engine/World.h"

#include "GameFramework/ProjectileMovementComponent.h"

#include "Kismet/GameplayStatics.h"

#include "Sound/SoundBase.h"

AUE4WindPongBall::AUE4WindPongBall ()
{
	this->PrimaryActorTick.bCanEverTick = true;

	this->CollisionSphere = this->CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	this->CollisionSphere->InitSphereRadius(this->CollisionSphereRadius);
	this->CollisionSphere->SetCollisionProfileName(TEXT("PhysicsActor"));

	this->RootComponent = this->CollisionSphere;

	this->StaticMesh = this->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	this->StaticMesh->SetupAttachment(this->CollisionSphere);

	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("/Engine/BasicShapes/Sphere"));

	if (SphereMesh.Succeeded())
	{
		this->StaticMesh->SetStaticMesh(SphereMesh.Object);
		this->StaticMesh->SetRelativeScale3D(FVector(this->CollisionSphereRadius / this->MeshSphereRadius));
	}

	this->Movement = this->CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	this->Movement->bShouldBounce = true;
	this->Movement->Bounciness = 1.0f;
	this->Movement->Friction = 0.0f;
	this->Movement->Velocity = FVector(0.0f, 0.0f, 0.0f);
}

void AUE4WindPongBall::Tick (float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUE4WindPongBall::AddWind (const FVector& WindVelocity)
{
	if (this->Movement)
	{
		this->Movement->Velocity += WindVelocity;
	}
}

void AUE4WindPongBall::BeginPlay ()
{
	Super::BeginPlay();

	this->Movement->OnProjectileBounce.AddDynamic(this, &AUE4WindPongBall::OnBounce);
	this->OnDestroyed.AddDynamic(this, &AUE4WindPongBall::OnFellOutWorld);
}

void AUE4WindPongBall::OnBounce (const FHitResult& ImpactResult, const FVector& ImpactVelocity)
{
	if (this->BounceSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this->GetWorld(), this->BounceSound, ImpactResult.ImpactPoint);
	}
}

void AUE4WindPongBall::OnFellOutWorld (AActor* Actor)
{
	this->GetWorld()->GetFirstPlayerController()->RestartLevel();
}
