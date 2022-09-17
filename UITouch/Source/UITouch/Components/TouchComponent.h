// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"


#include "TouchComponent.generated.h"


UCLASS(config = Game, Blueprintable, ClassGroup=(Custom), BlueprintType,  meta=(DisplayName = "TouchComponent", BlueprintSpawnableComponent))
class UITOUCH_API UTouchComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTouchComponent();


	/** * 接收通讯调度器 */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTouchDynmic, FVector, Moved, uint8, FingerIndex);

	/** * 多播所有接收到的调度器 */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTouchDynmic,FVector, Moved, uint8, FingerIndex);

	/** * 多播指定接收到的调度器 */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIndexTouchDynmic, FVector, Moved);


	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		/** * 接收通讯调度器 */
		FTouchDynmic OnAllTouch;

	/** * 多播所有接收到的调度器 */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnTouchDynmic OnPressedTouch;

	/** * 多播指定接收到的调度器 */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch1;

	/** * 多播指定接收到的调度器 */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch2;

	/** * 多播指定接收到的调度器 */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch3;

	/** * 多播指定接收到的调度器 */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch4;

	/** * 多播指定接收到的调度器 */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch5;

	/** * 多播指定接收到的调度器 */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch6;

	/** * 多播指定接收到的调度器 */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch7;

	/** * 多播指定接收到的调度器 */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch8;

	/** * 多播指定接收到的调度器 */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnIndexTouchDynmic OnTouch9;

	/** * 多播指定接收到的调度器 */
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
