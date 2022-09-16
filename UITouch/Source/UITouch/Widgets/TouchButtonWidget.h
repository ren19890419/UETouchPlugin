// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TouchWidget.h"
#include "UMG/Public/Components/SizeBox.h"
#include "UMG/Public/Components/Image.h"


#include "TouchButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class UITOUCH_API UTouchButtonWidget : public UTouchWidget
{
	GENERATED_BODY()

public:

		UPROPERTY(BlueprintReadWrite, Meta = (BindWidget), Category = "Aimo|Variable")
			/** 缩放控件变量 */
			USizeBox* SizeBoxWidget;

		UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
			/** 图像变量 */
			UImage* ImageWidget;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
			/** 图片设置 */
			FSlateBrush SlateBrush;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
			/** 图片设置 */
			FSlateBrush PressedSlateBrush;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
			/** 图片设置 */
			FSlateBrush DisabledSlateBrush;

		UPROPERTY(BlueprintReadWrite, Category = "Aimo|Variable")
			/** * 触控索引 255=空 */
			uint8 TouchFingerIndex = 255;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
			/** * 切换按下模式 */
			bool bPressedHandover = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
			/** * 按下 */
			bool bPressed = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
			/** * 禁用 */
			bool bDisabled = false;
		
protected:

		virtual void NativePreConstruct() override;
	
public:

	virtual	void TouchIndex(FVector Moved, uint8 FingerIndex) override;

};
