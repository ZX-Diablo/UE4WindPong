// Copyright ZX.Diablo 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "UE4WindPongHighScores.generated.h"

USTRUCT(BlueprintType)
struct FUE4WindPongHighScoreEntry
{
	GENERATED_USTRUCT_BODY()

public:
	/** Player name */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame)
	FString PlayerName;

	/** Player score */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame)
	float Score;
};

/**
 * 
 */
UCLASS()
class UE4WINDPONG_API UUE4WindPongHighScores : public USaveGame
{
	GENERATED_BODY()

public:
	UUE4WindPongHighScores ();

	/**
	 * Insert new high scores entry at given position and remove the last one
	 * @param Position Position in high scores array, should be less than MaxEntries
	 * @param Entry New entry value
	 */
	void InsertEntry (uint32 Position, const FUE4WindPongHighScoreEntry& Entry);

	/**
	 * Set value for high scores entry at given position
	 * @param Position Position in high scores array, should be less than MaxEntries
	 * @param Entry New entry value
	 */
	void SetEntry (uint32 Position, const FUE4WindPongHighScoreEntry& Entry);

	/**
	 * Get all high scores entries
	 * @return High scores array
	 */
	const TArray<FUE4WindPongHighScoreEntry>& GetEntries () const;

public:
	/** Save slot name */
	static const FString SlotName;

	/** Maximum allowed number of high scores entries */
	static const uint32 MaxEntries;

private:
	UPROPERTY()
	TArray<FUE4WindPongHighScoreEntry> HighScoreEntries;
};
