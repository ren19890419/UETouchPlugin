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
				ImageWidget->SetBrush(DisabledSlateBrush);  /** * ���ð��µ�ͼƬ */
			}
			else
			{
				ImageWidget->SetBrush(bPressed ? PressedSlateBrush : SlateBrush);  /** * ���ð��µ�ͼƬ */
			}
		}
	}
}

void UTouchButtonWidget::TouchIndex(FVector Moved, uint8 FingerIndex)
{
	if (bDisabled)  /** * �Ƿ���� */
	{
		return;
	}
	if (TouchFingerIndex == 255)  /** * ���������Ƿ�� */
	{
		if (IsTouchLocation(Moved))  /** * �Ƿ���봥������ */
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
	if (TouchFingerIndex == FingerIndex)  /** * �ж��Ƿ��ǵڶ������´��� */
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