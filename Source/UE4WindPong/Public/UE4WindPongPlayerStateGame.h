// Copyright ZX.Diablo 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "UE4WindPongPlayerStateGame.generated.h"

/**
 * 
 */
UCLASS()
class UE4WINDPONG_API AUE4WindPongPlayerStateGame : public APlayerState
{
	GENERATED_BODY()

public:
	/**
	 * Add value to current player's score counter
	 * @param Score Value to add
	 */
	void AddScore (float Score);

public:
	/** Current player's score */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	float CurrentScore;

	/** Current player's lives */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	int32 CurrentLives;
};
