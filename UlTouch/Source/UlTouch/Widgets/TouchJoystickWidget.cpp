// Fill out your copyright notice in the Description page of Project Settings.


#include "TouchJoystickWidget.h"
#include "UMG/Public/Components/CanvasPanelSlot.h"
#include "Runtime/UMG/Public/Blueprint/WidgetLayoutLibrary.h"

void UTouchJoystickWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (BackdropImageWidget)
	{
		BackdropImageWidget->SetBrush(BackdropSlateBrush);  /** * ���òٿظ˱�����ͼƬ */
	}
	if (ControlImageWidget)
	{
		ControlImageWidget->SetBrush(ControlSlateBrush);  /** * ���òٿظ˵�ͼƬ */
		UCanvasPanelSlot* CanvasPanelSlot = Cast<UCanvasPanelSlot>(ControlImageWidget->Slot);  /** * ��ȡ���� */
		if (CanvasPanelSlot)
		{
			CanvasPanelSlot->SetSize(ControlSlateBrush.GetImageSize());  /** * ���ô�С */
		}
	}
}

void UTouchJoystickWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UCanvasPanelSlot* CanvasPanelSlot = Cast<UCanvasPanelSlot>(ControlImageWidget->Slot);
	if (CanvasPanelSlot)
	{
		CanvasPanelSlot->SetAnchors(FAnchors(0.0, 0.0));  /** * ���ö��� */
		CanvasPanelSlot->SetAlignment({0.0, 0.0});  /** * ����ê�� */
		CanvasPanelSlot->SetPosition(BackdropSlateBrush.GetImageSize() / 2- ControlSlateBrush.GetImageSize() / 2);  /** * ����λ��(��ҪUI�����С��ͼƬ��С��ͬ) */
	}
}


void UTouchJoystickWidget::TouchIndex(FVector Moved, uint8 FingerIndex)
{
	if (TouchFingerIndex == 255 && Moved.Z > 0.0)
	{
		if (IsTouchLocation(Moved))  /** * �жϽ��봥��λ�� */
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
		SetControlPosition(LocalWidgetLocation + GetPaintSpaceGeometry().GetLocalSize() / 2 * UWidgetLayoutLibrary::GetViewportScale(this));  /** * ���òٿظ˹���λ�� */
		return;
	}
	return;
}

void UTouchJoystickWidget::TouchMoved(FVector Moved)
{
	if (TouchFingerIndex != 255)
	{
		float ViewportScale = UWidgetLayoutLibrary::GetViewportScale(this);
		FVector2D SizeLocation = GetPaintSpaceGeometry().GetLocalSize() * ViewportScale / 2;
		FVector2D OffLocation = { Moved.X, Moved.Y };
		OffLocation = OffLocation - (LocalWidgetLocation + SizeLocation);  /** * ��ȡƫ��ֵ */
		/** * ���Ƶ�ֵ */
		OnPressedLocation.Broadcast({ FMath::Clamp(OffLocation.X / SizeLocation.X,-1.0,1.0),  FMath::Clamp(OffLocation.Y / SizeLocation.Y * YShaftTimes,-1.0, 1.0), Moved.Z + 1 });
		SetControlPosition({ Moved.X, Moved.Y });
	}
}

void UTouchJoystickWidget::SetControlPosition(FVector2D Position)
{
	UCanvasPanelSlot* CanvasPanelSlot = Cast<UCanvasPanelSlot>(ControlImageWidget->Slot);
	if (CanvasPanelSlot)
	{
		float ViewportScale = UWidgetLayoutLibrary::GetViewportScale(this);
		FVector2D LocalPositionAtCoordinates = GetPaintSpaceGeometry().GetLocalPositionAtCoordinates({ 0.0,0.0 });
		FVector2D Size = CanvasPanelSlot->GetAutoSize() ? ControlImageWidget->Brush.GetImageSize() : CanvasPanelSlot->GetSize();
		FVector Vector = FVector(Size, 0.0);  /** * ת������ */
		FVector2D SizeLocationPosition = { Vector.X / 2, Vector.Y / 2 }; 
		FVector2D SetLocationPosition = Position / ViewportScale - SizeLocationPosition - LocalPositionAtCoordinates;  /** * ��ȡ��������λ�� */
		FVector2D LocalSize = GetPaintSpaceGeometry().GetLocalSize();
		/** * ���Ʋٿظ�λ�� */
		CanvasPanelSlot->SetPosition({ FMath::Clamp(SetLocationPosition.X, (Size / 2 * -1).X, LocalSize.X + (Size / 2 * -1).X), FMath::Clamp(SetLocationPosition.Y,(Size / 2 * -1).Y, LocalSize.Y + (Size / 2 * -1).Y) });
	}
}

/* * ��ȡ��ͼ����

ObjectProperty = FindField<UObjectProperty>(GetClass(), "JianBianXianShiAnimation"); //Objectָ�����ͱ���
		Object = Cast<UWidgetAnimation>(ObjectProperty->GetObjectPropertyValue_InContainer(this)); //ת��Object����
		if (Object)
		{
			WidgetAnimation = Cast<UWidgetAnimation>(Object);
			if (WidgetAnimation)
			{
				PlayAnimation(WidgetAnimation, 0.0f, 1, EUMGSequencePlayMode::Forward);
			}
		}

*/