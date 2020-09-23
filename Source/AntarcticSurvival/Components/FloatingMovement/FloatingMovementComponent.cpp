#include "FloatingMovementComponent.h"

UFloatingMovementComponent::UFloatingMovementComponent()
{
	// 해당 컴포넌트에서 Tick 메서드 호출을 사용하도록 할 것인지를 설정합니다.
	PrimaryComponentTick.bCanEverTick = true;

	FloatingSpeed = 200.0f;
	FloatingValue = 40.0f;

	// 시작 시간대를 설정합니다.
	StartTime = FMath::FRandRange(0.0f, 1.0f);
	/// - FMath : 수학과 관련된 정적 함수들을 제공하는 구조체
	/// - FMath::FRandRange(float min, float max) : min 과 max 사이의 난수를 반환합니다.
}


void UFloatingMovementComponent::BeginPlay()
{
	// 기반 클래스의 BeginPlay() 를 호출합니다.
	Super::BeginPlay();

	// 액터의 초기 위치를 저장합니다.
	ActorBeginLocation = GetOwner()->GetActorLocation();
	/// - GetOwner() : 해당 컴포넌트를 소유하는 액터를 반환합니다.
	
}


void UFloatingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 둥둥 뜨는 움직임을 실행하도록 합니다.
	FloatingMovement(DeltaTime);
}


void UFloatingMovementComponent::FloatingMovement(float dt)
{
	// 액터의 초기 위치를 저장합니다.
	FVector newFloatingLocation = ActorBeginLocation;

	// 다음 Z 좌표를 설정합니다.
	newFloatingLocation.Z = FMath::Sin(
	(GetWorld()->GetTimeSeconds() + StartTime) * FloatingSpeed * dt) * FloatingValue;
	/// GetWorld() : World Instance 를 반환합니다.
	/// WorldInstance->GetTimeSeconds() : 게임을 실행시킨 후 얼만큼의 시간이 지났는지
	/// 초단위로 반환합니다.

	// 액터의 위치를 설정합니다.
	GetOwner()->SetActorLocation(newFloatingLocation);
	/// - SetActorLocation(FVector newLocation) : 액터의 위치를 newLocation 의 값으로 설정합니다.

//	UE_LOG(LogTemp, Warning, TEXT("newFloatingLocation.Z = %.2f"), newFloatingLocation.Z);
	/// - UE_LOG(카테고리, 로그 레벨, 내용, args...) : 에디터 출력 로그창이나, 로그 파일에 로그를 출력합니다.
	/// - 카테고리 : 로그의 카테고리를 설정합니다.
	/// - 로그 레벨 : 로그의 수준을 설정합니다.
	///   - Fatal : 로그파일과 콘솔에 항상 출력되며 프로그램이 종료됩니다.
	///   - Error : 적생으로 콘솔과 파일에 출력됩니다.
	///   - Warning : 황색으로 콘솔과 파일에 출력됩니다.
	///   - Display : 콘솔과 파일에 출력됩니다.
	///   - Log : 파일에 출력됩니다. 에디터에서 실행할 때에는 콘솔에 출력됩니다.
	///   - Verbose : 로그 파일에만 출력됩니다.
	///   - VeryVerbose : 로그 파일에만 출력되며 매우 상세한 메시지가 출력됩니다.

}