// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TouchWidget.h"
#include "UMG/Public/Components/SizeBox.h"
#include "UMG/Public/Components/Image.h"
#include "UMG/Public/Components/CanvasPanel.h"

#include "TouchJoystickWidget.generated.h"

/**
 * 
 */
UCLASS()
class UITOUCH_API UTouchJoystickWidget : public UTouchWidget
{
	GENERATED_BODY()
	


public:

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** 缩放控件变量 */
		USizeBox* SizeBoxWidget;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** 包裹控件的视口 */
		UCanvasPanel* CanvasPanelWidget;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/**  操控杆背景图片 */
		UImage* BackdropImageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
		/** 操控杆背景图片设置 */
		FSlateBrush BackdropSlateBrush;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** 操控杆图片变量 */
		UImage* ControlImageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
		/** 操控杆图片设置 */
		FSlateBrush ControlSlateBrush;

	UPROPERTY(BlueprintReadWrite, Category = "Aimo|Variable")
		/** * 触控索引 */
		uint8 TouchFingerIndex = 255;

	UPROPERTY(BlueprintReadWrite, Category = "Aimo|Variable")
		/** * Y轴倍数 */
		float YShaftTimes = -1.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
		/** * 忽略值 */
		FVector2D IgnoreNumerical;

protected:

	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;
	

public:

	virtual	void TouchIndex(FVector Moved, uint8 FingerIndex) override;

	virtual void TouchMoved(FVector Moved) override;

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * 设置操控杆位置 */
		virtual void SetControlPosition(FVector2D Moved);

};
