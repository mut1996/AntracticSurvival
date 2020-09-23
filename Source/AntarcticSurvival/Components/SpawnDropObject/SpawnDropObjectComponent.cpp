#include "SpawnDropObjectComponent.h"

#include "../../Single/ASGameInstance.h"

#include "../../Actors/PlayerCharacter/PlayerCharacter.h"
#include "../../Actors/DropObject/DropObject.h"


USpawnDropObjectComponent::USpawnDropObjectComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	LoadAsset();
}

void USpawnDropObjectComponent::BeginPlay()
{
	Super::BeginPlay();

	// ����� GameInstance ��ü�� ����ϴ�.
	GameInst = Cast<UASGameInstance>(GetWorld()->GetGameInstance());

	InitializeDropObjInfos();

	// ������ �ʱ�ȭ
	CurrentDelay = MinDelay;

	CreateDropObject();
}

void USpawnDropObjectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USpawnDropObjectComponent::LoadAsset()
{
	// UDataTable ������ �ּ��� �ε��մϴ�.
	static ConstructorHelpers::FObjectFinder<UDataTable> DROP_OBJECT_DATATABLE(
		TEXT("DataTable'/Game/Resources/DataTables/DT_DropObjectInfo.DT_DropObjectInfo'"));

	// �ε忡 �����ߴٸ�
	if (DROP_OBJECT_DATATABLE.Succeeded())
		DropObjectDataTable = DROP_OBJECT_DATATABLE.Object;
	else
	{ UE_LOG(LogTemp, Error, TEXT("DropObjectDataTable is not Loaded!")); }
}

void USpawnDropObjectComponent::InitializeDropObjInfos()
{
	// �ּ� �ε忡 �����ߴ��� Ȯ��
	if (!IsValid(DropObjectDataTable)) return;

	// DataTable ���� ���� �̸����� ����ϴ�.
	for (FName rowName : DropObjectDataTable->GetRowNames())
	{
		// FindRow �޼��带 �̿��Ͽ� ���� ã�� �� ������ ���� ���
		// ���� ������ �˸� ���ڿ� ������ �����մϴ�.
		FString contextString;

		// DataTable ���� �̸��� �̿��Ͽ� ���� ã���ϴ�.
		FDropObjectInfo* findDropObjInfo = 
			DropObjectDataTable->FindRow<FDropObjectInfo>(rowName, contextString);

		// ã�� �������� DropObjectType �� �������
		if (findDropObjInfo->DropObjectType == EDropObjectType::DT_Fish)
			FishObjInfos.Add(*findDropObjInfo);

		// ������ Ÿ���̶��
		else TrashObjInfos.Add(*findDropObjInfo);
	}
}

void USpawnDropObjectComponent::CreateDropObject()
{
	// ������ DropObject Ÿ���� �����մϴ�.
	EDropObjectType dropObjType = GetRandomDropType();

	// ������ų DropObj ������ �����մϴ�.
	FDropObjectInfo dropObjInfo = GetRandomDropObjInfo(dropObjType);

	// ���͸� ������ ��ġ�� �����մϴ�.
	FVector spawnLocation =
		GetOwner()->GetActorLocation() +
		FMath::FRandRange(-SpawnHalfDistanceX, SpawnHalfDistanceX) * 
		FVector::RightVector;

	// ���͸� �����մϴ�.
	ADropObject * dropObj = GetWorld()->SpawnActor<ADropObject>(
		spawnLocation, FRotator::ZeroRotator);
	/// - SpawnActor<T>() : T ������ ���͸� �����մϴ�.

	dropObj->InitializeDropObject(dropObjType, dropObjInfo.ChangeHungryValue,
		dropObjInfo.DropObjectStaticMesh, GameInst->GetPlayerCharacter());

	// Ÿ�̸Ӹ� �����ŵ�ϴ�.
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this,
		&USpawnDropObjectComponent::CreateDropObject, CurrentDelay, false);
	/// - Ÿ�̸� : ������ �ð����� Ư���� ������ �����ϴ� ����� �ǹ��մϴ�.
	///   Ÿ�̸Ӱ� ������ �ൿ�� ����� �� ������ ���� : void()
}

EDropObjectType USpawnDropObjectComponent::GetRandomDropType() const
{
	return (FMath::FRandRange(1.0f, 100.0f) <= FishDropPercentage) ?
		EDropObjectType::DT_Fish : EDropObjectType::DT_Trash;
}

FDropObjectInfo USpawnDropObjectComponent::GetRandomDropObjInfo(
	EDropObjectType dropObjectType) const
{
	// Fish ������ ������ ������ �����մϴ�.
	if (dropObjectType == EDropObjectType::DT_Fish)
		return (FishObjInfos[FMath::RandRange(0, FishObjInfos.Num() - 1)]);

	// Trash ������ ������ ������ �����մϴ�.
	else return (TrashObjInfos[FMath::RandRange(0, TrashObjInfos.Num() - 1)]);
}