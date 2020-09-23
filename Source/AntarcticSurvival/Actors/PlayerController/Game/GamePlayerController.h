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
	// ���� �� �Է°��� ������ ����
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
	// ī�޶� �並 �����մϴ�.
	void SetCameraView();

	// GameWidget �� ���ϴ�.
	void CreateWidgetInScreen();

	void HorizontalInput(float newAxisValue);

	void LoadAsset();

public :
	FORCEINLINE float GetHorizontalInputValue() const
	{ return HorizontalInputValue; }
};
