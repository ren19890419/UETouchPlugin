// Fill out your copyright notice in the Description page of Project Settings.


#include "TouchAdvancedJoystickWidget.h"
#include "UMG/Public/Components/CanvasPanelSlot.h"
#include "Runtime/UMG/Public/Blueprint/WidgetLayoutLibrary.h"


void UTouchAdvancedJoystickWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (UpSpeedImageWidget)
	{
		UpSpeedImageWidget->SetBrush(bTriggerUpSpeed ? TriggerUpSpeedSlateBrush :  UpSpeedSlateBrush);
		UCanvasPanelSlot* CanvasPanelSlot = Cast<UCanvasPanelSlot>(UpSpeedImageWidget->Slot);
		if (CanvasPanelSlot)
		{
			CanvasPanelSlot->SetSize(UpSpeedSlateBrush.GetImageSize()); /** * ���ü���ͼƬ��С */
			CanvasPanelSlot->SetPosition({0.0, (BackdropSlateBrush.GetImageSize() / 2 * -1).Y}); /** * ���ü���ͼƬλ�� */
		}
	}
}


void UTouchAdvancedJoystickWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (UpSpeedImageWidget->GetVisibility() == ESlateVisibility::Visible)
	{
		UpSpeedImageWidget->SetVisibility(ESlateVisibility::Hidden); /** * �������ؼ���ͼƬ */
	}
}

void UTouchAdvancedJoystickWidget::TouchIndex(FVector Moved, uint8 FingerIndex)
{
	if (TouchFingerIndex == 255 && Moved.Z > 0.0)
	{
		if (IsTouchLocation(Moved))
		{
			TouchFingerIndex = FingerIndex;
			OnPressedLocation.Broadcast({ 0.0, 0.0, Moved.Z + 1 });
			SetIndexTouchDelegate(true, FingerIndex);
			return;
		}
	}
	if (TouchFingerIndex == FingerIndex)
	{
		TouchFingerIndex = 255;
		SetIndexTouchDelegate(false, FingerIndex);
		OnPressedLocation.Broadcast({ 0.0, 0.0, Moved.Z + 1 });
		SetControlPosition(LocalWidgetLocation + GetPaintSpaceGeometry().GetLocalSize() / 2 * UWidgetLayoutLibrary::GetViewportScale(this));
		if (bTriggerUpSpeed == true && UpSpeedImageWidget)
		{
			UpSpeedImageWidget->SetBrush(UpSpeedSlateBrush);
			bTriggerUpSpeed = false;
			if (UpSpeedImageWidget->GetVisibility() == ESlateVisibility::Visible)
			{
				UpSpeedImageWidget->SetVisibility(ESlateVisibility::Hidden);/** * �������ؼ���ͼƬ */
			}
		}
		return;
	}
	return;
}

void UTouchAdvancedJoystickWidget::TouchMoved(FVector Moved)
{
	if (TouchFingerIndex != 255)
	{
		float ViewportScale = UWidgetLayoutLibrary::GetViewportScale(this);
		FVector2D SizeLocation = GetPaintSpaceGeometry().GetLocalSize() * ViewportScale / 2;
		FVector2D OffLocation = { Moved.X, Moved.Y };
		OffLocation = OffLocation - (LocalWidgetLocation + SizeLocation);
		float X = OffLocation.X / SizeLocation.X;
		float Y = OffLocation.Y / SizeLocation.Y * YShaftTimes;
		if(Y > 0.2 && X > -0.5 && X < 0.5)  /** * �ж��Ƿ�������ģʽ */
		{
			if (Y > 1.5) /** * �ж��Ƿ�������ģʽ */
			{
				Y = 2;
				OnPressedLocation.Broadcast({ FMath::Clamp(X,-1.0,1.0),  FMath::Clamp(Y,-1.0, 2), Moved.Z + 1 }); /** * ���� Y = 2 �Ǽ���ģʽ */
				if (bTriggerUpSpeed == false && UpSpeedImageWidget)
				{
					UpSpeedImageWidget->SetBrush(TriggerUpSpeedSlateBrush);
					bTriggerUpSpeed = true;
				}
			}
			else
			{
				OnPressedLocation.Broadcast({ FMath::Clamp(X,-1.0,1.0),  FMath::Clamp(Y,-1.0, 1.0), Moved.Z + 1 }); /** * �ַ���ͨ�ƶ� */
				if (bTriggerUpSpeed == true && UpSpeedImageWidget)
				{
					UpSpeedImageWidget->SetBrush(UpSpeedSlateBrush);
					bTriggerUpSpeed = false;
				}
			}
			if (UpSpeedImageWidget->GetVisibility() == ESlateVisibility::Hidden)
			{
				UpSpeedImageWidget->SetVisibility(ESlateVisibility::Visible); /** * ������ʾ����ͼƬ */
			}
		}
		else
		{
			OnPressedLocation.Broadcast({ FMath::Clamp(X,-1.0,1.0),  FMath::Clamp(Y,-1.0, 1.0), Moved.Z + 1 });
			if (UpSpeedImageWidget->GetVisibility() == ESlateVisibility::Visible)
			{
				UpSpeedImageWidget->SetVisibility(ESlateVisibility::Hidden); /** * �������ؼ���ͼƬ */
			}
		}
		SetControlPosition({ Moved.X, Moved.Y });
	}
}
