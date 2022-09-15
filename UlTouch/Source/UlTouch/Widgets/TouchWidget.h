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
	
	/** * 多播指定接收到的调度器 */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPressed, FVector, Moved);

	/** * 多播所有接收到的调度器 */
	UPROPERTY(BlueprintAssignable, Category = "Aimo|On")
		FOnPressed OnPressedLocation;

protected:
	// Called when the game starts
	virtual void NativeConstruct() override;


public:

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * 接收触发位置和索引 */
		virtual void TouchIndex(FVector Moved, uint8 FingerIndex);

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * 设置触控是否绑定 */
		virtual void SetIndexTouchDelegate(bool bDelegateBind, uint8 FingerIndex);

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * 触发移动位置 */
		virtual void TouchMoved(FVector Moved);

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * 判断是否进入触控区域 */
		virtual bool IsTouchLocation(FVector Moved);

};
