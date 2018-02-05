// Copyright ZX.Diablo 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UE4WindPongPlayerControllerMenu.generated.h"

/**
 * 
 */
UCLASS()
class UE4WINDPONG_API AUE4WindPongPlayerControllerMenu : public APlayerController
{
	GENERATED_BODY()

public:
	AUE4WindPongPlayerControllerMenu ();

	/**
	 * Start the game (load game map)
	 */
	UFUNCTION(BlueprintCallable, Category = "Interface")
	void StartGame ();

	/**
	 * Show main menu
	 */
	UFUNCTION(BlueprintCallable, Category = "Interface")
	void ShowMainMenu ();

	/**
	 * Show high scores menu
	 */
	UFUNCTION(BlueprintCallable, Category = "Interface")
	void ShowHighScoresMenu ();

protected:
	virtual void BeginPlay () override;

protected:
	/** Main menu widget class */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> MainMenu;

	/** High scores menu widget class */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> HighScoresMenu;

private:
	void ShowMenuHelper (TSubclassOf<UUserWidget> Menu);
	void CloseCurrentMenu ();

private:
	UPROPERTY()
	UUserWidget* CurrentMenu;
};
