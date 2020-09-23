#include "DropObject.h"

#include "../PlayerCharacter/PlayerCharacter.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/DamageType.h"

ADropObject::ADropObject()
{
	PrimaryActorTick.bCanEverTick = true;

	FallDownSpeed = 700.0f;

	InitializeComponents();
}

void ADropObject::BeginPlay()
{
	Super::BeginPlay();

	// StaticMeshComponent �� ��� ���Ͱ� ��ĥ ��� ȣ���ų �޼��带 ����մϴ�.
	StaticMeshComponent->OnComponentBeginOverlap.AddDynamic(
		this, &ADropObject::AddDamage);
}

void ADropObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FallDown(DeltaTime);
}

void ADropObject::InitializeDropObject(EDropObjectType objType, 
	float changeHungryValue, UStaticMesh* staticMesh, class APlayerCharacter * playerCharacter)
{
	ObjectType = objType;
	ChangeHungryValue = changeHungryValue;
	PlayerCharacter = playerCharacter;

	StaticMeshComponent->SetStaticMesh(staticMesh);

	// Fish Ÿ���̶�� ȸ������ �ʵ��� �մϴ�.
	RotatingMovement->RotationRate = (ObjectType == EDropObjectType::DT_Fish) ?
		FRotator::ZeroRotator : FRotator(0.0f, 0.0f, -180.0f);
}

void ADropObject::InitializeComponents()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(
		TEXT("STATIC_MESH"));

	// StaticMesh Component �� Root Component �� �����մϴ�
	SetRootComponent(StaticMeshComponent);
	/// - Root �� ����� ������Ʈ�� ���͸� ��ǥ�ϰ� �˴ϴ�.

	// Collision Presets �� �����մϴ�.
	StaticMeshComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	/// - OverlapAllDynamic : ��� ���ͷ� ��ĥ �� �ִ� ���� ������Ʈ�Դϴ�.
	/// - OverlapAll : ��� ���Ϳ� ��ĥ �� �ִ� WorldStatic ������Ʈ�Դϴ�.

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(
		TEXT("ROTATING_MOVEMENT"));
}

void ADropObject::FallDown(float dt)
{
	// �ش� ������ ���� ��ġ�� �����մϴ�.
	FVector newLocation = GetActorLocation() +
		(FVector::DownVector * FallDownSpeed * dt);

	SetActorLocation(newLocation);
}


void ADropObject::AddDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	// ��ģ ���Ͱ� �÷��̾ �ƴ϶�� �����Ű�� �ʽ��ϴ�.
	if (OtherActor != PlayerCharacter) return;

	// ���� ����� / ������ų ü���� �����մϴ�.
	float addDamage = (ObjectType == EDropObjectType::DT_Fish) ?
		ChangeHungryValue : -ChangeHungryValue;

	// �÷��̾�� ������� ���մϴ�.
	UGameplayStatics::ApplyDamage(PlayerCharacter, addDamage,
		nullptr, this, UDamageType::StaticClass());
	/// - ApplyDamage(AActor *					DamagedActor 
	///				  float						BaseDamage
	///				  AController *				EventInstigator
	///				  AActor *					DamageCauser
	///				  TSubclassOf<UDamageType>	DamageTypeClass)
	/// - DamagedActor ���� ������� ���մϴ�.
	///   �� �� �ش� ��ü�� OnTakeAnyDamage �븮�ڰ� ȣ��˴ϴ�.
	/// - DamagedActor : ������� ���� ����
	/// - BaseDamage : ���� �����
	/// - EventInstigator : ���ظ� ���� ��Ʈ�ѷ�
	/// - DamageCauser : ���ظ� ������ ��ü
	/// - DamageTypeClass : ����� Ÿ���� �����ϴ� UClass

	// �ش� ���͸� �����մϴ�.
	Destroy();
}