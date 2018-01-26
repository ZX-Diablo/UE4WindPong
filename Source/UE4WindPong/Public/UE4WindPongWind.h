// Copyright ZX.Diablo 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UE4WindPongWind.generated.h"

UCLASS()
class UE4WINDPONG_API AUE4WindPongWind : public AActor
{
	GENERATED_BODY()

public:
	AUE4WindPongWind ();

	virtual void Tick (float DeltaTime) override;

protected:
	virtual void BeginPlay () override;

private:
	FVector GenerateVelocity () const;
	float GenerateDuration () const;

private:
	/** Wind's area of effect (inside box volume) */
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* VolumeBox;

private:
	/** Minimum wind strength (direction multiplier) */
	UPROPERTY(EditAnywhere, Category = "Wind Parameters")
	float MinStrength = 0.1f;

	/** Maximum wind strength (direction multiplier) */
	UPROPERTY(EditAnywhere, Category = "Wind Parameters")
	float MaxStrength = 0.3f;

	/** Current wind velocity (read only, calculated using given parameters) */
	UPROPERTY(VisibleAnywhere, Category = "Wind Parameters")
	FVector CurrentVelocity;

	/** Minimum wind duration (in seconds) */
	UPROPERTY(EditAnywhere, Category = "Wind Parameters")
	float MinDuration = 5.0f;

	/** Maximum wind duration (in seconds) */
	UPROPERTY(EditAnywhere, Category = "Wind Parameters")
	float MaxDuration = 10.0f;

	/** Current wind duration (read only, calculated using given parameters) */
	UPROPERTY(VisibleAnywhere, Category = "Wind Parameters")
	float CurrentDuration;

	/** Default size of the Wind's volume box */
	UPROPERTY(VisibleDefaultsOnly, Category = "Wind Defaults")
	FVector VolumeBoxExtent = FVector(400.0f, 400.0f, 400.0f);

private:
	float TimeElapsed = 0.0f;
};
