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
			CanvasPanelSlot->SetSize(UpSpeedSlateBrush.GetImageSize()); /** * 设置加速图片大小 */
			CanvasPanelSlot->SetPosition({0.0, (BackdropSlateBrush.GetImageSize() / 2 * -1).Y}); /** * 设置加速图片位置 */
		}
	}
}


void UTouchAdvancedJoystickWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (UpSpeedImageWidget->GetVisibility() == ESlateVisibility::Visible)
	{
		UpSpeedImageWidget->SetVisibility(ESlateVisibility::Hidden); /** * 设置隐藏加速图片 */
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
				UpSpeedImageWidget->SetVisibility(ESlateVisibility::Hidden);/** * 设置隐藏加速图片 */
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
		if(Y > 0.2 && X > -0.5 && X < 0.5)  /** * 判断是否进入加速模式 */
		{
			if (Y > 1.5) /** * 判断是否进入加速模式 */
			{
				Y = 2;
				OnPressedLocation.Broadcast({ FMath::Clamp(X,-1.0,1.0),  FMath::Clamp(Y,-1.0, 2), Moved.Z + 1 }); /** * 返回 Y = 2 是加速模式 */
				if (bTriggerUpSpeed == false && UpSpeedImageWidget)
				{
					UpSpeedImageWidget->SetBrush(TriggerUpSpeedSlateBrush);
					bTriggerUpSpeed = true;
				}
			}
			else
			{
				OnPressedLocation.Broadcast({ FMath::Clamp(X,-1.0,1.0),  FMath::Clamp(Y,-1.0, 1.0), Moved.Z + 1 }); /** * 分发普通移动 */
				if (bTriggerUpSpeed == true && UpSpeedImageWidget)
				{
					UpSpeedImageWidget->SetBrush(UpSpeedSlateBrush);
					bTriggerUpSpeed = false;
				}
			}
			if (UpSpeedImageWidget->GetVisibility() == ESlateVisibility::Hidden)
			{
				UpSpeedImageWidget->SetVisibility(ESlateVisibility::Visible); /** * 设置显示加速图片 */
			}
		}
		else
		{
			OnPressedLocation.Broadcast({ FMath::Clamp(X,-1.0,1.0),  FMath::Clamp(Y,-1.0, 1.0), Moved.Z + 1 });
			if (UpSpeedImageWidget->GetVisibility() == ESlateVisibility::Visible)
			{
				UpSpeedImageWidget->SetVisibility(ESlateVisibility::Hidden); /** * 设置隐藏加速图片 */
			}
		}
		SetControlPosition({ Moved.X, Moved.Y });
	}
}
