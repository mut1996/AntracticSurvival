// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AntarcticSurvival.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ANTARCTICSURVIVAL_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()


private :
	// 수평 축 입력값을 저장할 변수
	float HorizontalInputValue;

	class TSubclassOf<class UGameWidget> GameWidgetClass;

public :
	AGamePlayerController();

protected :
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

public :
	virtual void Tick(float DeltaTime) override;
	
private :
	// 카메라 뷰를 설정합니다.
	void SetCameraView();

	// GameWidget 을 띄웁니다.
	void CreateWidgetInScreen();

	void HorizontalInput(float newAxisValue);

	void LoadAsset();

public :
	FORCEINLINE float GetHorizontalInputValue() const
	{ return HorizontalInputValue; }
};
