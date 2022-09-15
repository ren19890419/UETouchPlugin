// Fill out your copyright notice in the Description page of Project Settings.


#include "TouchWidget.h"
#include "../Components/TouchComponent.h"

#include "Runtime/UMG/Public/Blueprint/WidgetLayoutLibrary.h"



void UTouchWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (GetOwningPlayer())
	{
		UTouchComponent* TouchComponent =  Cast<UTouchComponent>(GetOwningPlayer()->GetComponentByClass(UTouchComponent::StaticClass()));
		if (TouchComponent)
		{
			TScriptDelegate<FWeakObjectPtr> OnSetDragPrt; //�����Խӱ���
			OnSetDragPrt.BindUFunction(this, "TouchIndex"); //�Խӱ����󶨺���
			TouchComponent->OnPressedTouch.Add(OnSetDragPrt); //�󶨶Խӱ���
		}
	}
}

void UTouchWidget::TouchIndex(FVector Moved, uint8 FingerIndex)
{
	if (IsTouchLocation(Moved))
	{
		OnPressedLocation.Broadcast(Moved); /** * ��������λ�� */
	}
}

void UTouchWidget::SetIndexTouchDelegate(bool bDelegateBind, uint8 FingerIndex)
{
	UTouchComponent* TouchComponent = Cast<UTouchComponent>(GetOwningPlayer()->GetComponentByClass(UTouchComponent::StaticClass()));
	if (TouchComponent)
	{
		TScriptDelegate<FWeakObjectPtr> OnSetDragPrt; //�����Խӱ���
		OnSetDragPrt.BindUFunction(this, "TouchMoved"); //�Խӱ����󶨺���
		
		switch (FingerIndex)
		{
		case 0:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch1.Add(OnSetDragPrt); //�󶨶Խӱ���
			}
			else
			{
				TouchComponent->OnTouch1.Remove(OnSetDragPrt);
			}
			break;
		case 1:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch2.Add(OnSetDragPrt); //�󶨶Խӱ���
			}
			else
			{
				TouchComponent->OnTouch2.Remove(OnSetDragPrt);
			}
			break;
		case 2:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch3.Add(OnSetDragPrt); //�󶨶Խӱ���
			}
			else
			{
				TouchComponent->OnTouch3.Remove(OnSetDragPrt);
			}
			break;
		case 3:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch4.Add(OnSetDragPrt); //�󶨶Խӱ���
			}
			else
			{
				TouchComponent->OnTouch4.Remove(OnSetDragPrt);
			}
			break;
		case 4:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch5.Add(OnSetDragPrt); //�󶨶Խӱ���
			}
			else
			{
				TouchComponent->OnTouch5.Remove(OnSetDragPrt);
			}
			break;
		case 5:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch6.Add(OnSetDragPrt); //�󶨶Խӱ���
			}
			else
			{
				TouchComponent->OnTouch6.Remove(OnSetDragPrt);
			}
			break;
		case 6:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch7.Add(OnSetDragPrt); //�󶨶Խӱ���
			}
			else
			{
				TouchComponent->OnTouch7.Remove(OnSetDragPrt);
			}
			break;
		case 7:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch8.Add(OnSetDragPrt); //�󶨶Խӱ���
			}
			else
			{
				TouchComponent->OnTouch8.Remove(OnSetDragPrt);
			}
			break;
		case 8:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch9.Add(OnSetDragPrt); //�󶨶Խӱ���
			}
			else
			{
				TouchComponent->OnTouch9.Remove(OnSetDragPrt);
			}
			break;
		case 9:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch10.Add(OnSetDragPrt); //�󶨶Խӱ���
			}
			else
			{
				TouchComponent->OnTouch10.Remove(OnSetDragPrt);
			}
			break;
		default:
			break;
		}
	}
}

void UTouchWidget::TouchMoved(FVector Moved)
{
	/** * ����̳���дʹ�� */
}

/** * �ж��Ƿ񴥿�λ���Ƿ���봥������ */

bool UTouchWidget::IsTouchLocation(FVector Moved)
{
	float ViewportScale = UWidgetLayoutLibrary::GetViewportScale(this); /** * �ӿڴ������� */
	FVector2D SizeLocation = GetPaintSpaceGeometry().GetLocalSize() * ViewportScale; /** * ��ȡ�ؼ���С */
	LocalWidgetLocation = GetPaintSpaceGeometry().GetLocalPositionAtCoordinates({0.0,0.0}) * ViewportScale; /** * ��ȡ�ؼ����Ͻ�λ�� */
	return Moved.X >= LocalWidgetLocation.X && Moved.X <= LocalWidgetLocation.X + SizeLocation.X  \
		&& Moved.Y >= LocalWidgetLocation.Y && Moved.Y <= LocalWidgetLocation.Y + SizeLocation.Y; 
}
