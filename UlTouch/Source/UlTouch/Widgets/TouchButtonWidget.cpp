// Fill out your copyright notice in the Description page of Project Settings.


#include "TouchButtonWidget.h"

void UTouchButtonWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (ImageWidget)
	{
		if (ImageWidget)
		{
			if (bDisabled)
			{
				ImageWidget->SetBrush(DisabledSlateBrush);  /** * 设置按下的图片 */
			}
			else
			{
				ImageWidget->SetBrush(bPressed ? PressedSlateBrush : SlateBrush);  /** * 设置按下的图片 */
			}
		}
	}
}

void UTouchButtonWidget::TouchIndex(FVector Moved, uint8 FingerIndex)
{
	if (bDisabled)  /** * 是否禁用 */
	{
		return;
	}
	if (TouchFingerIndex == 255)  /** * 触控索引是否空 */
	{
		if (IsTouchLocation(Moved))  /** * 是否进入触控区域 */
		{
			if (bPressedHandover)
			{
				if (Moved.Z)
				{
					bPressed = !bPressed;
					Moved.Z = bPressed ? Moved.Z : 0.0;
					OnPressedLocation.Broadcast(Moved);
					if (ImageWidget)
					{
						ImageWidget->SetBrush(bPressed ? PressedSlateBrush : SlateBrush);
					}
				}
				return;
			}
			else
			{
				TouchFingerIndex = FingerIndex;
				OnPressedLocation.Broadcast(Moved);
				SetIndexTouchDelegate(true, FingerIndex);
			}
			if (ImageWidget)
			{
				ImageWidget->SetBrush(PressedSlateBrush);
			}
			return;
		}
	}
	if (TouchFingerIndex == FingerIndex)  /** * 判断是否是第二次松下触控 */
	{
		TouchFingerIndex = 255;
		OnPressedLocation.Broadcast(Moved);
		SetIndexTouchDelegate(false, FingerIndex);
		if (ImageWidget)
		{
			ImageWidget->SetBrush(SlateBrush);
		}
	}
	return;
}