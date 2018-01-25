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
	/** Wind's area of effect (inside box volume) */
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* VolumeBox;

private:
	/** Default size of the Wind's volume box */
	UPROPERTY(VisibleDefaultsOnly, Category = "Wind Defaults")
	FVector VolumeBoxExtent = FVector(400.0f, 400.0f, 400.0f);
};
