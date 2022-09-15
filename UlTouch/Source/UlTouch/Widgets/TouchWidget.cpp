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
			TScriptDelegate<FWeakObjectPtr> OnSetDragPrt; //建立对接变量
			OnSetDragPrt.BindUFunction(this, "TouchIndex"); //对接变量绑定函数
			TouchComponent->OnPressedTouch.Add(OnSetDragPrt); //绑定对接变量
		}
	}
}

void UTouchWidget::TouchIndex(FVector Moved, uint8 FingerIndex)
{
	if (IsTouchLocation(Moved))
	{
		OnPressedLocation.Broadcast(Moved); /** * 触发触摸位置 */
	}
}

void UTouchWidget::SetIndexTouchDelegate(bool bDelegateBind, uint8 FingerIndex)
{
	UTouchComponent* TouchComponent = Cast<UTouchComponent>(GetOwningPlayer()->GetComponentByClass(UTouchComponent::StaticClass()));
	if (TouchComponent)
	{
		TScriptDelegate<FWeakObjectPtr> OnSetDragPrt; //建立对接变量
		OnSetDragPrt.BindUFunction(this, "TouchMoved"); //对接变量绑定函数
		
		switch (FingerIndex)
		{
		case 0:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch1.Add(OnSetDragPrt); //绑定对接变量
			}
			else
			{
				TouchComponent->OnTouch1.Remove(OnSetDragPrt);
			}
			break;
		case 1:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch2.Add(OnSetDragPrt); //绑定对接变量
			}
			else
			{
				TouchComponent->OnTouch2.Remove(OnSetDragPrt);
			}
			break;
		case 2:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch3.Add(OnSetDragPrt); //绑定对接变量
			}
			else
			{
				TouchComponent->OnTouch3.Remove(OnSetDragPrt);
			}
			break;
		case 3:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch4.Add(OnSetDragPrt); //绑定对接变量
			}
			else
			{
				TouchComponent->OnTouch4.Remove(OnSetDragPrt);
			}
			break;
		case 4:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch5.Add(OnSetDragPrt); //绑定对接变量
			}
			else
			{
				TouchComponent->OnTouch5.Remove(OnSetDragPrt);
			}
			break;
		case 5:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch6.Add(OnSetDragPrt); //绑定对接变量
			}
			else
			{
				TouchComponent->OnTouch6.Remove(OnSetDragPrt);
			}
			break;
		case 6:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch7.Add(OnSetDragPrt); //绑定对接变量
			}
			else
			{
				TouchComponent->OnTouch7.Remove(OnSetDragPrt);
			}
			break;
		case 7:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch8.Add(OnSetDragPrt); //绑定对接变量
			}
			else
			{
				TouchComponent->OnTouch8.Remove(OnSetDragPrt);
			}
			break;
		case 8:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch9.Add(OnSetDragPrt); //绑定对接变量
			}
			else
			{
				TouchComponent->OnTouch9.Remove(OnSetDragPrt);
			}
			break;
		case 9:
			if (bDelegateBind)
			{
				TouchComponent->OnTouch10.Add(OnSetDragPrt); //绑定对接变量
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
	/** * 子类继承重写使用 */
}

/** * 判断是否触控位置是否进入触控区域 */

bool UTouchWidget::IsTouchLocation(FVector Moved)
{
	float ViewportScale = UWidgetLayoutLibrary::GetViewportScale(this); /** * 视口触控缩放 */
	FVector2D SizeLocation = GetPaintSpaceGeometry().GetLocalSize() * ViewportScale; /** * 获取控件大小 */
	LocalWidgetLocation = GetPaintSpaceGeometry().GetLocalPositionAtCoordinates({0.0,0.0}) * ViewportScale; /** * 获取控件左上角位置 */
	return Moved.X >= LocalWidgetLocation.X && Moved.X <= LocalWidgetLocation.X + SizeLocation.X  \
		&& Moved.Y >= LocalWidgetLocation.Y && Moved.Y <= LocalWidgetLocation.Y + SizeLocation.Y; 
}
