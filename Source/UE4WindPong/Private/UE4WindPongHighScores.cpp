// Copyright ZX.Diablo 2018

#include "Public/UE4WindPongHighScores.h"

const FString UUE4WindPongHighScores::SlotName = TEXT("highscores");
const uint32 UUE4WindPongHighScores::MaxEntries = 10;

UUE4WindPongHighScores::UUE4WindPongHighScores ()
{
	this->HighScoreEntries.Init({}, UUE4WindPongHighScores::MaxEntries);
}

void UUE4WindPongHighScores::InsertEntry (uint32 Position, const FUE4WindPongHighScoreEntry& Entry)
{
	if (Position < UUE4WindPongHighScores::MaxEntries)
	{
		this->HighScoreEntries.Insert(Entry, Position);
		this->HighScoreEntries.Pop();
	}
}

void UUE4WindPongHighScores::SetEntry (uint32 Position, const FUE4WindPongHighScoreEntry& Entry)
{
	if (Position < UUE4WindPongHighScores::MaxEntries)
	{
		this->HighScoreEntries[Position] = Entry;
	}
}

const TArray<FUE4WindPongHighScoreEntry>& UUE4WindPongHighScores::GetEntries () const
{
	return this->HighScoreEntries;
}
