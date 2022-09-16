// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "../Components/TouchComponent.h"

#include "TouchPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UITOUCH_API ATouchPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Aimo|Variable")
		TObjectPtr <UTouchComponent> TouchComponent = nullptr;

/**
protected:

	/** ÷ÿ–¥ ÕÊº“ ‰»Î */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * …Ë÷√≤Ÿøÿ∏ÀŒª÷√ */
		virtual void TouchPressed(ETouchIndex::Type FingerIndex, FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * …Ë÷√≤Ÿøÿ∏ÀŒª÷√ */
		virtual void TouchReleased(ETouchIndex::Type FingerIndex, FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * …Ë÷√≤Ÿøÿ∏ÀŒª÷√ */
		virtual void TouchMove(ETouchIndex::Type FingerIndex, FVector Location);

};
