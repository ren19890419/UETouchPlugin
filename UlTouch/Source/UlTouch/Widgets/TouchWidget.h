// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"


#include "TouchWidget.generated.h"

/**
 * 
 */
UCLASS()
class ULTOUCH_API UTouchWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:


	UPROPERTY(BlueprintReadWrite, Category = "Aimo|Variable")
		FVector2D LocalWidgetLocation;
	
	/** * �ಥָ�����յ��ĵ����� */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPressed, FVector, Moved);

	/** * �ಥ���н��յ��ĵ����� */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnPressed OnPressedLocation;

protected:
	// Called when the game starts
	virtual void NativeConstruct() override;


public:

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * ���մ���λ�ú����� */
		virtual void TouchIndex(FVector Moved, uint8 FingerIndex);

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * ���ô����Ƿ�� */
		virtual void SetIndexTouchDelegate(bool bDelegateBind, uint8 FingerIndex);

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * �����ƶ�λ�� */
		virtual void TouchMoved(FVector Moved);

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * �ж��Ƿ���봥������ */
		virtual bool IsTouchLocation(FVector Moved);

};
