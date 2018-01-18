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
};
