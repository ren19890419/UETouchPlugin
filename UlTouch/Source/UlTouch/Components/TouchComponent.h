// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"


#include "TouchComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class ULTOUCH_API UTouchComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTouchComponent();


	/** * ����ͨѶ������ */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTouchDynmic, FVector, Moved, uint8, FingerIndex);

	/** * �ಥ���н��յ��ĵ����� */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTouchDynmic,FVector, Moved, uint8, FingerIndex);

	/** * �ಥָ�����յ��ĵ����� */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIndexTouchDynmic, FVector, Moved);


	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		/** * ����ͨѶ������ */
		FTouchDynmic OnAllTouch;

	/** * �ಥ���н��յ��ĵ����� */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnTouchDynmic OnPressedTouch;

	/** * �ಥָ�����յ��ĵ����� */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch1;

	/** * �ಥָ�����յ��ĵ����� */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch2;

	/** * �ಥָ�����յ��ĵ����� */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch3;

	/** * �ಥָ�����յ��ĵ����� */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch4;

	/** * �ಥָ�����յ��ĵ����� */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch5;

	/** * �ಥָ�����յ��ĵ����� */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch6;

	/** * �ಥָ�����յ��ĵ����� */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch7;

	/** * �ಥָ�����յ��ĵ����� */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch8;

	/** * �ಥָ�����յ��ĵ����� */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch9;

	/** * �ಥָ�����յ��ĵ����� */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch10;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		virtual void Touch(FVector Moved, uint8 FingerIndex);


	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		virtual void TouchIndex(FVector Moved, uint8 FingerIndex);

	

};
