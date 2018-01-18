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
};
