// Copyright ZX.Diablo 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UE4WindPongPlayerControllerGame.generated.h"

/**
 * 
 */
UCLASS()
class UE4WINDPONG_API AUE4WindPongPlayerControllerGame : public APlayerController
{
	GENERATED_BODY()

public:
	/**
	 * Restarts the game (reload game map)
	 */
	UFUNCTION(BlueprintCallable, Category = "Interface")
	void RestartGame ();

	/**
	 * Returns to the main menu (load main menu map)
	 */
	UFUNCTION(BlueprintCallable, Category = "Interface")
	void ReturnToMainMenu ();

public:
	/**
	 * Called by the pad when it hits the ball, updates player score
	 */
	void HitByBall ();

	/**
	 * Called by the game mode when run out of lives, shows high scores
	 */
	void EndGame ();

protected:
	virtual void BeginPlay () override;

protected:
	/** Game HUD menu widget class */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> HUDClass;

	/** High scores modal window widget class */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> HighScoresModalClass;

private:
	UPROPERTY()
	UUserWidget* HUD;

	UPROPERTY()
	UUserWidget* HighScoresModal;
};
