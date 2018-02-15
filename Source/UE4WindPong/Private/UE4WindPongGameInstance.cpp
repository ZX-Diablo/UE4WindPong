// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongGameInstance.h"

#include "Kismet/GameplayStatics.h"

void UUE4WindPongGameInstance::InsertHighScore (int32 Position, const FUE4WindPongHighScoreEntry& Entry)
{
	this->CacheHighScores();

	if (Position >= 0)
	{
		this->HighScores->InsertEntry(Position, Entry);

		UGameplayStatics::SaveGameToSlot(this->HighScores, UUE4WindPongHighScores::SlotName, 0);
	}
}

void UUE4WindPongGameInstance::SetHighScore (int32 Position, const FUE4WindPongHighScoreEntry& Entry)
{
	this->CacheHighScores();

	if (Position >= 0)
	{
		this->HighScores->SetEntry(Position, Entry);

		UGameplayStatics::SaveGameToSlot(this->HighScores, UUE4WindPongHighScores::SlotName, 0);
	}
}

const TArray<FUE4WindPongHighScoreEntry>& UUE4WindPongGameInstance::GetHighScores () const
{
	this->CacheHighScores();

	return this->HighScores->GetEntries();
}

void UUE4WindPongGameInstance::CacheHighScores () const
{
	if (!this->HighScores)
	{
		this->HighScores = Cast<UUE4WindPongHighScores>(UGameplayStatics::LoadGameFromSlot(UUE4WindPongHighScores::SlotName, 0));
		if (!this->HighScores)
		{
			this->HighScores = Cast<UUE4WindPongHighScores>(UGameplayStatics::CreateSaveGameObject(UUE4WindPongHighScores::StaticClass()));
		}
	}
}
