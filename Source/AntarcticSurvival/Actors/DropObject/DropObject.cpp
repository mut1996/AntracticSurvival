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

	// StaticMeshComponent 와 어떠한 액터가 겹칠 경우 호출시킬 메서드를 등록합니다.
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

	// Fish 타입이라면 회전하지 않도록 합니다.
	RotatingMovement->RotationRate = (ObjectType == EDropObjectType::DT_Fish) ?
		FRotator::ZeroRotator : FRotator(0.0f, 0.0f, -180.0f);
}

void ADropObject::InitializeComponents()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(
		TEXT("STATIC_MESH"));

	// StaticMesh Component 를 Root Component 로 지정합니다
	SetRootComponent(StaticMeshComponent);
	/// - Root 로 등록한 컴포넌트는 액터를 대표하게 됩니다.

	// Collision Presets 를 설정합니다.
	StaticMeshComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	/// - OverlapAllDynamic : 모든 액터롸 겹칠 수 있는 동적 오브젝트입니다.
	/// - OverlapAll : 모든 액터와 겹칠 수 있는 WorldStatic 오브젝트입니다.

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(
		TEXT("ROTATING_MOVEMENT"));
}

void ADropObject::FallDown(float dt)
{
	// 해당 액터의 다음 위치를 저장합니다.
	FVector newLocation = GetActorLocation() +
		(FVector::DownVector * FallDownSpeed * dt);

	SetActorLocation(newLocation);
}


void ADropObject::AddDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	// 겹친 액터가 플레이어가 아니라면 실행시키지 않습니다.
	if (OtherActor != PlayerCharacter) return;

	// 가할 대미지 / 증가시킬 체력을 정의합니다.
	float addDamage = (ObjectType == EDropObjectType::DT_Fish) ?
		ChangeHungryValue : -ChangeHungryValue;

	// 플레이어에게 대미지를 가합니다.
	UGameplayStatics::ApplyDamage(PlayerCharacter, addDamage,
		nullptr, this, UDamageType::StaticClass());
	/// - ApplyDamage(AActor *					DamagedActor 
	///				  float						BaseDamage
	///				  AController *				EventInstigator
	///				  AActor *					DamageCauser
	///				  TSubclassOf<UDamageType>	DamageTypeClass)
	/// - DamagedActor 에게 대미지를 가합니다.
	///   이 때 해당 객체의 OnTakeAnyDamage 대리자가 호출됩니다.
	/// - DamagedActor : 대미지를 가할 액터
	/// - BaseDamage : 가할 대미지
	/// - EventInstigator : 피해를 가한 컨트롤러
	/// - DamageCauser : 피해를 입히는 객체
	/// - DamageTypeClass : 대미지 타입을 설명하는 UClass

	// 해당 액터를 제거합니다.
	Destroy();
}