// Copyright ZX.Diablo 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Public/UE4WindPongBall.h"
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
	 * Set player state current lives to maximum lives
	 */
	virtual void PostLogin (APlayerController* NewPlayer) override;

	/**
	 * Start new game round, spawns new ball. Called after level load and on every restart
	 */
	void StartRound ();

	/**
	 * Called when the ball is destroyed, restarts game if player has more lives otherwise ends it
	 */
	void BallFellOutWorld ();

public:
	/**
	 * Get how much player scores per every ball hit
	 */
	FORCEINLINE float GetScorePerHit () const { return this->ScorePerHit; }

private:
	/** Ball to spawn */
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	TSubclassOf<AUE4WindPongBall> BallClass = AUE4WindPongBall::StaticClass();

	/** Initial ball spawn location */
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	FVector BallSpawnLocation = FVector(0.0f, 0.0f, 150.0f);

	/** How much score added after every ball hit */
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	float ScorePerHit = 1.0f;

	/** How many lives (balls) player has */
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	int32 MaximumLives = 3;
};
