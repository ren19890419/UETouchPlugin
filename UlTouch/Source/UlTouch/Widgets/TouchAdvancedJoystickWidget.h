// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TouchJoystickWidget.h"
#include "TouchAdvancedJoystickWidget.generated.h"

/**
 * 
 */
UCLASS()
class ULTOUCH_API UTouchAdvancedJoystickWidget : public UTouchJoystickWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/**  加速图片 */
		UImage* UpSpeedImageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
		/** 加速图片设置 */
		FSlateBrush UpSpeedSlateBrush;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
		/** 触发的加速图片设置 */
		FSlateBrush TriggerUpSpeedSlateBrush;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
		/** * 是否触发加速 */
		bool bTriggerUpSpeed = false;

protected:

	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

public:

	virtual	void TouchIndex(FVector Moved, uint8 FingerIndex) override;

	virtual void TouchMoved(FVector Moved) override;

};
