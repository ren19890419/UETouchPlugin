// Fill out your copyright notice in the Description page of Project Settings.


#include "TouchPlayerController.h"


ATouchPlayerController::ATouchPlayerController()
{
	//TouchComponent = CreateEditorOnlyDefaultSubobject<UTouchComponent>(TEXT("TouchComponent"));
	
}

void ATouchPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (IsLocalController())
	{
		TouchComponent = NewObject<UTouchComponent>(this);
		if (InputComponent == nullptr)
		{
			InputComponent = NewObject<UInputComponent>(this);
		}
		SetupPlayerInputComponent(InputComponent);
	}
}
	

void ATouchPlayerController::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent); 

	PlayerInputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ATouchPlayerController::TouchPressed);
	PlayerInputComponent->BindTouch(EInputEvent::IE_Released, this, &ATouchPlayerController::TouchReleased);
	PlayerInputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ATouchPlayerController::TouchMove);

}


void ATouchPlayerController::TouchPressed(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (TouchComponent)
	{
		TouchComponent->Touch(Location, FingerIndex);
	}
}

void ATouchPlayerController::TouchReleased(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (TouchComponent)
	{
		TouchComponent->Touch(Location, FingerIndex);
	}
}

void ATouchPlayerController::TouchMove(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (TouchComponent)
	{
		Location.Z = 2;
		TouchComponent->Touch(Location, FingerIndex);
	}
}

