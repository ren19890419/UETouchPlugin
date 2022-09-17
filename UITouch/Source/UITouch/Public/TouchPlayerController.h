/**
 * ��Ȩ����Ȩ: Aimo_��ī
 * ��ֹ��ȡ������ӯ��
 * ��ֹ�޸�δ��������ͬ�ⷢ��������
 * BiLiBiLi(��������)��ַ: https://space.bilibili.com/146962867
 * GitHub��ַ: https://github.com/AimoTvT/UETouchPlugin
 * ��ӭ��ʵ���Ĵ���/���¼��뱾����Ĺ���
 * һ�����ǿ��Ĳ��!!!
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "../Components/TouchComponent.h"

#include "TouchPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UITOUCH_API ATouchPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:

	ATouchPlayerController();

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Aimo|Variable")
		TObjectPtr <UTouchComponent> TouchComponent;

protected:

	/** ��д ������� */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * ���òٿظ�λ�� */
		virtual void TouchPressed(ETouchIndex::Type FingerIndex, FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * ���òٿظ�λ�� */
		virtual void TouchReleased(ETouchIndex::Type FingerIndex, FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
		/** * ���òٿظ�λ�� */
		virtual void TouchMove(ETouchIndex::Type FingerIndex, FVector Location);

};
