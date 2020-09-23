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

	// ī�޶� �� ����
	SetCameraView();


	CreateWidgetInScreen();
}

void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(TEXT("Horizontal"), this, &AGamePlayerController::HorizontalInput);
	/// - UInputComponent : ���Ϳ� �Է� �̺�Ʈ�� ����ϴ� ����� �����ϴ� ������Ʈ�Դϴ�.
}

void AGamePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGamePlayerController::SetCameraView()
{
	TArray<AActor*> findActors;
	/// - �𸮾󿡼� �����ϴ� �����̳�
	/// - TArray : �������� ũ�⸦ ������ �� �ִ� �迭
	///   - UPROPERTY() �� �Բ� ����� �� �ֽ��ϴ�.
	/// - TSet : ���� ������ �����Ǹ�, �ߺ� ������� �ʽ��ϴ�.
	/// - TMap : Ű�� ���� �Բ� ����Ǹ�, Ű�� �ߺ� ������� �ʽ��ϴ�.


	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Camera"), findActors);
	/// - UGameplayStatics : ��ƿ�� ���� �޼������ �����ϴ� Ŭ�����Դϴ�.
	/// - GetAllActorsWithTag(WorldContextObject, Tag, OutActors)
	///   - Tag �� ��ġ�ϴ� Tag �� ���� ���͸� WorldContextObject �� ������ ���忡�� ã��
	///     OutActors �� �����մϴ�.

	SetViewTargetWithBlend(findActors[0]);
	/// - SetViewTargetWithBlend(NewViewTarget)
	///   �� Ÿ���� NewViewTarget ���� �����մϴ�.
}

void AGamePlayerController::CreateWidgetInScreen()
{
	// UGameWidget ������ ���� ��ü�� �����Ͽ� ȭ�鿡 ���ϴ�.
	CreateWidget<UGameWidget>(this, GameWidgetClass)->AddToViewport();
}

void AGamePlayerController::HorizontalInput(float newAxisValue)
{
	HorizontalInputValue = newAxisValue;

	// �Է� ���� �̿��Ͽ� ��Ʈ�ѷ��� ȸ����ŵ�ϴ�.
	/// - ���� ��Ʈ�ѷ� Yaw ȸ������ ��ӹ޾� ����� �� �ֵ��� �ϱ� ���� �ۼ��մϴ�.
	SetControlRotation(FRotator(0.0f, (newAxisValue * -90.0f), 0.0f));
}

void AGamePlayerController::LoadAsset()
{

	static ConstructorHelpers::FClassFinder<UGameWidget> WIDGETBP_GAMEWIDGET(
		TEXT("WidgetBlueprint'/Game/Resources/Blueprints/Widgets/WidgetBP_Game.WidgetBP_Game_C'"));

	if (WIDGETBP_GAMEWIDGET.Succeeded())
		GameWidgetClass = WIDGETBP_GAMEWIDGET.Class;
}