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
		/** ���ſؼ����� */
		USizeBox* SizeBoxWidget;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** �����ؼ����ӿ� */
		UCanvasPanel* CanvasPanelWidget;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/**  �ٿظ˱���ͼƬ */
		UImage* BackdropImageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
		/** �ٿظ˱���ͼƬ���� */
		FSlateBrush BackdropSlateBrush;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** �ٿظ�ͼƬ���� */
		UImage* ControlImageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
		/** �ٿظ�ͼƬ���� */
		FSlateBrush ControlSlateBrush;

	UPROPERTY(BlueprintReadWrite, Category = "Aimo|Variable")
		/** * �������� */
		uint8 TouchFingerIndex = 255;

	UPROPERTY(BlueprintReadWrite, Category = "Aimo|Variable")
		/** * Y�ᱶ�� */
		float YShaftTimes = -1.0;

protected:

	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;
	

public:

	virtual	void TouchIndex(FVector Moved, uint8 FingerIndex) override;

	virtual void TouchMoved(FVector Moved) override;

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * ���òٿظ�λ�� */
		virtual void SetControlPosition(FVector2D Moved);

};
