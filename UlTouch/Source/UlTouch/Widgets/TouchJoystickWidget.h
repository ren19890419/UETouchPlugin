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
class ULTOUCH_API UTouchJoystickWidget : public UTouchWidget
{
	GENERATED_BODY()
	


public:

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** Ëõ·Å¿Ø¼þ±äÁ¿ */
		USizeBox* SizeBoxWidget;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** °ü¹ü¿Ø¼þµÄÊÓ¿Ú */
		UCanvasPanel* CanvasPanelWidget;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/**  ²Ù¿Ø¸Ë±³¾°Í¼Æ¬ */
		UImage* BackdropImageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
		/** ²Ù¿Ø¸Ë±³¾°Í¼Æ¬ÉèÖÃ */
		FSlateBrush BackdropSlateBrush;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** ²Ù¿Ø¸ËÍ¼Æ¬±äÁ¿ */
		UImage* ControlImageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
		/** ²Ù¿Ø¸ËÍ¼Æ¬ÉèÖÃ */
		FSlateBrush ControlSlateBrush;

	UPROPERTY(BlueprintReadWrite, Category = "Aimo|Variable")
		/** * ´¥¿ØË÷Òý */
		uint8 TouchFingerIndex = 255;

	UPROPERTY(BlueprintReadWrite, Category = "Aimo|Variable")
		/** * YÖá±¶Êý */
		float YShaftTimes = -1.0;

protected:

	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;
	

public:

	virtual	void TouchIndex(FVector Moved, uint8 FingerIndex) override;

	virtual void TouchMoved(FVector Moved) override;

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * ÉèÖÃ²Ù¿Ø¸ËÎ»ÖÃ */
		virtual void SetControlPosition(FVector2D Moved);

};
