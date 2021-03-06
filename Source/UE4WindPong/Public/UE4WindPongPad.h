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

	virtual void SetupPlayerInputComponent (class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay () override;

private:
	UFUNCTION()
	void OnHitByBall (AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

private:
	void TurnForward (float AxisValue);
	void TurnRight (float AxisValue);

private:
	/** Pad collision box (root component) */
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* CollisionBox;

	/** Pad static mesh (cylinder) */
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMesh;

	/** Pad camera spring arm */
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	/** Pad camera */
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

private:
	/** Pad's turn angle limit in degrees */
	UPROPERTY(EditAnywhere, Category = "Pad Parameters")
	float TurnAngleLimit = 30.0f;

	/** Default size of the Pad's collision box */
	UPROPERTY(VisibleDefaultsOnly, Category = "Pad Defaults|Mesh")
	FVector CollisionBoxExtent = FVector(200.0f, 200.0f, 5.0f);

	/** Default size of the Pad's cylinder mesh (before scaling) */
	UPROPERTY(VisibleDefaultsOnly, Category = "Pad Defaults|Mesh")
	FVector CylinderBoundingBox = FVector(50.0f, 50.0f, 40.0f);

	/** Default camera distance (spring arm length) */
	UPROPERTY(VisibleDefaultsOnly, Category = "Pad Defaults|Camera")
	float CameraDistance = 500.0f;

	/** Default camera pitch angle in degrees */
	UPROPERTY(VisibleDefaultsOnly, Category = "Pad Defaults|Camera")
	float CameraAngle = -20.0f;
};
