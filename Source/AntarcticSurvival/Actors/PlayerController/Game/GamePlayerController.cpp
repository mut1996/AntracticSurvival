// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayerController.h"

#include "../../../Widgets/GameWidget.h"

AGamePlayerController::AGamePlayerController()
{
	LoadAsset();
}

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 카메라 뷰 설정
	SetCameraView();


	CreateWidgetInScreen();
}

void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(TEXT("Horizontal"), this, &AGamePlayerController::HorizontalInput);
	/// - UInputComponent : 액터에 입력 이벤트를 등록하는 기능을 제공하는 컴포넌트입니다.
}

void AGamePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGamePlayerController::SetCameraView()
{
	TArray<AActor*> findActors;
	/// - 언리얼에서 제공하는 컨테이너
	/// - TArray : 동적으로 크기를 조절할 수 있는 배열
	///   - UPROPERTY() 와 함께 선언될 수 있습니다.
	/// - TSet : 저장 순서가 유지되며, 중복 저장되지 않습니다.
	/// - TMap : 키와 값이 함께 저장되며, 키는 중복 저장되지 않습니다.


	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Camera"), findActors);
	/// - UGameplayStatics : 유틸정 정적 메서드들을 제공하는 클래스입니다.
	/// - GetAllActorsWithTag(WorldContextObject, Tag, OutActors)
	///   - Tag 와 일치하는 Tag 를 가진 액터를 WorldContextObject 에 전달한 월드에서 찾아
	///     OutActors 에 저장합니다.

	SetViewTargetWithBlend(findActors[0]);
	/// - SetViewTargetWithBlend(NewViewTarget)
	///   뷰 타깃을 NewViewTarget 으로 설정합니다.
}

void AGamePlayerController::CreateWidgetInScreen()
{
	// UGameWidget 형식의 위젯 객체를 생성하여 화면에 띄웁니다.
	CreateWidget<UGameWidget>(this, GameWidgetClass)->AddToViewport();
}

void AGamePlayerController::HorizontalInput(float newAxisValue)
{
	HorizontalInputValue = newAxisValue;

	// 입력 값을 이용하여 컨트롤러를 회전시킵니다.
	/// - 폰이 컨트롤러 Yaw 회전값을 상속받아 사용할 수 있도록 하기 위해 작성합니다.
	SetControlRotation(FRotator(0.0f, (newAxisValue * -90.0f), 0.0f));
}

void AGamePlayerController::LoadAsset()
{

	static ConstructorHelpers::FClassFinder<UGameWidget> WIDGETBP_GAMEWIDGET(
		TEXT("WidgetBlueprint'/Game/Resources/Blueprints/Widgets/WidgetBP_Game.WidgetBP_Game_C'"));

	if (WIDGETBP_GAMEWIDGET.Succeeded())
		GameWidgetClass = WIDGETBP_GAMEWIDGET.Class;
}