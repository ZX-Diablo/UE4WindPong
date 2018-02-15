// Copyright ZX.Diablo 2018

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Public/UE4WindPongHighScores.h"
#include "UE4WindPongGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE4WINDPONG_API UUE4WindPongGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	/**
	 * Insert new high score and save
	 * @param Position High score position
	 * @param Entry High score value
	 */
	UFUNCTION(BlueprintCallable, Category = "High Scores")
	void InsertHighScore (int32 Position, const FUE4WindPongHighScoreEntry& Entry);

	/**
	 * Set new high score and save
	 * @param Position High score position
	 * @param Entry High score value
	 */
	UFUNCTION(BlueprintCallable, Category = "High Scores")
	void SetHighScore (int32 Position, const FUE4WindPongHighScoreEntry& Entry);

	/**
	 * Load and get array of high scores
	 * @return High scores
	 */
	UFUNCTION(BlueprintCallable, Category = "High Scores")
	const TArray<FUE4WindPongHighScoreEntry>& GetHighScores () const;

private:
	void CacheHighScores () const;

private:
	UPROPERTY()
	mutable UUE4WindPongHighScores* HighScores;
};
