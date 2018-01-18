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

	virtual void Tick (float DeltaTime) override;

protected:
	virtual void BeginPlay () override;
};
