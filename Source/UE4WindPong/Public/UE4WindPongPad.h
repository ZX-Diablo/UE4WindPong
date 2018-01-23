// Copyright ZX.Diablo 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UE4WindPongPad.generated.h"

UCLASS()
class UE4WINDPONG_API AUE4WindPongPad : public APawn
{
	GENERATED_BODY()

public:
	AUE4WindPongPad ();

	virtual void Tick (float DeltaTime) override;

	virtual void SetupPlayerInputComponent (class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay () override;

private:
	/** Pad collision box (root component) */
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* CollisionBox;

	/** Pad static mesh (cylinder) */
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMesh;

	/** Pad camera */
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

private:
	/** Default size of the Pad's collision box */
	UPROPERTY(VisibleDefaultsOnly, Category = "Pad Defaults")
	FVector CollisionBoxExtent = FVector(100.0f, 100.0f, 5.0f);

	/** Default size of the Pad's cylinder mesh (before scaling) */
	UPROPERTY(VisibleDefaultsOnly, Category = "Pad Defaults")
	FVector CylinderBoundingBox = FVector(50.0f, 50.0f, 40.0f);

	/** Default camera position */
	UPROPERTY(VisibleDefaultsOnly, Category = "Pad Defaults|Camera")
	FVector CameraLocation = FVector(-200.0f, 0.0f, 50.0f);

	/** Camera view point relative location */
	UPROPERTY(VisibleDefaultsOnly, Category = "Pad Defaults|Camera")
	FVector CameraViewPoint = FVector(200.0f, 0.0f, 5.0f);
};
