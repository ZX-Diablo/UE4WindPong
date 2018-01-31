// Copyright ZX.Diablo 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UE4WindPongGameModeMenu.generated.h"

/**
 * 
 */
UCLASS()
class UE4WINDPONG_API AUE4WindPongGameModeMenu : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void RestartPlayer (AController* NewPlayer) override;
};
