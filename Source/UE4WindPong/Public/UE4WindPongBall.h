// Copyright ZX.Diablo 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UE4WindPongBall.generated.h"

UCLASS()
class UE4WINDPONG_API AUE4WindPongBall : public AActor
{
	GENERATED_BODY()
	
public:
	AUE4WindPongBall ();

	/**
	 * Apply wind force to the Ball
	 * @param WindVelocity Direction and strength of the wind
	 */
	void AddWind (const FVector& WindVelocity);

protected:
	virtual void BeginPlay () override;

private:
	UFUNCTION()
	void OnBounce (const FHitResult& ImpactResult, const FVector& ImpactVelocity);

	UFUNCTION()
	void OnFellOutWorld (AActor* Actor);

private:
	/** Ball collision sphere (root component) */
	UPROPERTY(VisibleAnywhere)
	class USphereComponent* CollisionSphere;

	/** Ball static mesh (sphere) */
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMesh;

	/** Ball movement logic */
	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* Movement;

private:
	/** Ball bounce sound */
	UPROPERTY(EditAnywhere, Category = "Ball Parameters")
	class USoundBase* BounceSound;

	/** Default size of the Ball's collision sphere */
	UPROPERTY(VisibleDefaultsOnly, Category = "Ball Defaults")
	float CollisionSphereRadius = 20.0f;

	/** Default radius of the Ball's mesh (before scaling) */
	UPROPERTY(VisibleDefaultsOnly, Category = "Ball Defaults")
	float MeshSphereRadius = 50.0f;
};
