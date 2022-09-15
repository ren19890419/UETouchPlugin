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
class ULTOUCH_API UTouchButtonWidget : public UTouchWidget
{
	GENERATED_BODY()

public:

		UPROPERTY(BlueprintReadWrite, Meta = (BindWidget), Category = "Aimo|Variable")
			/** ���ſؼ����� */
			USizeBox* SizeBoxWidget;

		UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
			/** ͼ����� */
			UImage* ImageWidget;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
			/** ͼƬ���� */
			FSlateBrush SlateBrush;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
			/** ͼƬ���� */
			FSlateBrush PressedSlateBrush;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
			/** ͼƬ���� */
			FSlateBrush DisabledSlateBrush;

		UPROPERTY(BlueprintReadWrite, Category = "Aimo|Variable")
			/** * �������� 255=�� */
			uint8 TouchFingerIndex = 255;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
			/** * �л�����ģʽ */
			bool bPressedHandover = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
			/** * ���� */
			bool bPressed = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aimo|Variable")
			/** * ���� */
			bool bDisabled = false;
		
protected:

		virtual void NativePreConstruct() override;
	
public:

	virtual	void TouchIndex(FVector Moved, uint8 FingerIndex) override;

};
