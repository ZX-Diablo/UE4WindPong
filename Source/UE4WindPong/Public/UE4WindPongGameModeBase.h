// Copyright ZX.Diablo 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UE4WindPongGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE4WINDPONG_API AUE4WindPongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	/**
	 * Get how much player scores per every ball hit
	 */
	FORCEINLINE float GetScorePerHit () const { return this->ScorePerHit; }

private:
	/** How much score added after every ball hit */
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	float ScorePerHit = 1.0f;
};
