// Fill out your copyright notice in the Description page of Project Settings.


#include "TouchPlayerController.h"
#include "Kismet/KismetSystemLibrary.h" 




void ATouchPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (IsLocalController())
	{
		if (InputComponent == nullptr)
	{
			InputComponent = NewObject<UInputComponent>(this);
		}
		SetupPlayerInputComponent(InputComponent);
	}
	TouchComponent = CreateEditorOnlyDefaultSubobject<UTouchComponent>(TEXT("TouchComponent"));
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
	UKismetSystemLibrary::PrintString(this, "1", true, false, FColor::Blue, 2);
}

void ATouchPlayerController::TouchReleased(ETouchIndex::Type FingerIndex, FVector Location)
{
	UKismetSystemLibrary::PrintString(this, "2", true, false, FColor::Blue, 2);
}

void ATouchPlayerController::TouchMove(ETouchIndex::Type FingerIndex, FVector Location)
{
	UKismetSystemLibrary::PrintString(this, "3", true, false, FColor::Blue, 2);
}

