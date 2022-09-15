// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TouchWidget.h"
#include "UMG/Public/Components/SizeBox.h"
#include "UMG/Public/Components/Image.h"

#include "TouchControlWidget.generated.h"

/**
 * 
 */
UCLASS()
class ULTOUCH_API UTouchControlWidget : public UTouchWidget
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

	UPROPERTY(BlueprintReadWrite, Category = "Aimo|Variable")
		/** * 触控索引组 */
		TArray<uint8> TouchFingerIndexs;

	UPROPERTY(BlueprintReadWrite, Category = "Aimo|Variable")
		/** * 触控索引位置组 */
		TArray<FVector2D> TouchLocations;


protected:

	virtual void NativePreConstruct() override;

public:

	virtual	void TouchIndex(FVector Moved, uint8 FingerIndex) override;

	virtual void TouchMoved(FVector Moved) override;

};
