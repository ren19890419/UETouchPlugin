// Fill out your copyright notice in the Description page of Project Settings.


#include "TouchControlWidget.h"

void UTouchControlWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (ImageWidget)
	{
		TouchLocations.SetNum(10); /** * ���ô���λ�������������� */
		ImageWidget->SetBrush(SlateBrush); /** * ���ô��ر��� */
	}
}


void UTouchControlWidget::TouchIndex(FVector Moved, uint8 FingerIndex)
{
	if (Moved.Z)
	{
		if (IsTouchLocation(Moved) && TouchFingerIndexs.Find(FingerIndex) == -1)
		{
			int32 Index = TouchFingerIndexs.Add(FingerIndex); /** * ��Ӵ�������������� */
			if (Index != -1 && TouchLocations.Num() > Index)
			{
				TouchLocations[Index] = { Moved.X, Moved.Y }; /** * ���ô���λ�����λ�� */
			}
			SetIndexTouchDelegate(true, FingerIndex); /** * ���ƶ�λ�õ����� */
		}
	}
	else
	{
		if (TouchFingerIndexs.Find(FingerIndex) != -1 && TouchLocations.Num() >= TouchFingerIndexs.Find(FingerIndex))
		{
			int32 Index = TouchFingerIndexs.Remove(FingerIndex);
			if (Index != -1 && TouchLocations.Num() > Index)
			{
				TouchLocations[Index] = { 0.0, 0.0 }; /** * �������λ�����λ�� */
			}
			SetIndexTouchDelegate(false, FingerIndex); /** * ������ƶ�λ�õ����� */
		}
	}
}

void UTouchControlWidget::TouchMoved(FVector Moved)
{
	int32 Index = TouchFingerIndexs.Find(uint8(Moved.Z)); /** * ��ȡѰ�Ҷ�Ӧ������ */
	if (Index != -1 && TouchLocations.Num() > Index) /** * �ж��Ƿ�Ѱ�ҳɹ� */
	{
		FVector2D TouchMoved = { Moved.X, Moved.Y };
		TouchMoved -= TouchLocations[Index]; /** * �����ƶ�λ�� */
		TouchLocations[Index] = { Moved.X, Moved.Y }; /** * ���Ǿ�λ�� */
		OnPressedLocation.Broadcast({ TouchMoved.X, TouchMoved.Y,Moved.Z + 1}); /** * �ַ��ƶ�λ�� */
	}
}