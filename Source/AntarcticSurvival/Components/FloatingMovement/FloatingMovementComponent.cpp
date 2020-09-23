#include "FloatingMovementComponent.h"

UFloatingMovementComponent::UFloatingMovementComponent()
{
	// �ش� ������Ʈ���� Tick �޼��� ȣ���� ����ϵ��� �� �������� �����մϴ�.
	PrimaryComponentTick.bCanEverTick = true;

	FloatingSpeed = 200.0f;
	FloatingValue = 40.0f;

	// ���� �ð��븦 �����մϴ�.
	StartTime = FMath::FRandRange(0.0f, 1.0f);
	/// - FMath : ���а� ���õ� ���� �Լ����� �����ϴ� ����ü
	/// - FMath::FRandRange(float min, float max) : min �� max ������ ������ ��ȯ�մϴ�.
}


void UFloatingMovementComponent::BeginPlay()
{
	// ��� Ŭ������ BeginPlay() �� ȣ���մϴ�.
	Super::BeginPlay();

	// ������ �ʱ� ��ġ�� �����մϴ�.
	ActorBeginLocation = GetOwner()->GetActorLocation();
	/// - GetOwner() : �ش� ������Ʈ�� �����ϴ� ���͸� ��ȯ�մϴ�.
	
}


void UFloatingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// �յ� �ߴ� �������� �����ϵ��� �մϴ�.
	FloatingMovement(DeltaTime);
}


void UFloatingMovementComponent::FloatingMovement(float dt)
{
	// ������ �ʱ� ��ġ�� �����մϴ�.
	FVector newFloatingLocation = ActorBeginLocation;

	// ���� Z ��ǥ�� �����մϴ�.
	newFloatingLocation.Z = FMath::Sin(
	(GetWorld()->GetTimeSeconds() + StartTime) * FloatingSpeed * dt) * FloatingValue;
	/// GetWorld() : World Instance �� ��ȯ�մϴ�.
	/// WorldInstance->GetTimeSeconds() : ������ �����Ų �� ��ŭ�� �ð��� ��������
	/// �ʴ����� ��ȯ�մϴ�.

	// ������ ��ġ�� �����մϴ�.
	GetOwner()->SetActorLocation(newFloatingLocation);
	/// - SetActorLocation(FVector newLocation) : ������ ��ġ�� newLocation �� ������ �����մϴ�.

//	UE_LOG(LogTemp, Warning, TEXT("newFloatingLocation.Z = %.2f"), newFloatingLocation.Z);
	/// - UE_LOG(ī�װ�, �α� ����, ����, args...) : ������ ��� �α�â�̳�, �α� ���Ͽ� �α׸� ����մϴ�.
	/// - ī�װ� : �α��� ī�װ��� �����մϴ�.
	/// - �α� ���� : �α��� ������ �����մϴ�.
	///   - Fatal : �α����ϰ� �ֿܼ� �׻� ��µǸ� ���α׷��� ����˴ϴ�.
	///   - Error : �������� �ְܼ� ���Ͽ� ��µ˴ϴ�.
	///   - Warning : Ȳ������ �ְܼ� ���Ͽ� ��µ˴ϴ�.
	///   - Display : �ְܼ� ���Ͽ� ��µ˴ϴ�.
	///   - Log : ���Ͽ� ��µ˴ϴ�. �����Ϳ��� ������ ������ �ֿܼ� ��µ˴ϴ�.
	///   - Verbose : �α� ���Ͽ��� ��µ˴ϴ�.
	///   - VeryVerbose : �α� ���Ͽ��� ��µǸ� �ſ� ���� �޽����� ��µ˴ϴ�.

}