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

	// 등록한 GameInstance 객체를 얻습니다.
	GameInst = Cast<UASGameInstance>(GetWorld()->GetGameInstance());

	InitializeDropObjInfos();

	// 딜레이 초기화
	CurrentDelay = MinDelay;

	CreateDropObject();
}

void USpawnDropObjectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USpawnDropObjectComponent::LoadAsset()
{
	// UDataTable 형식의 애셋을 로드합니다.
	static ConstructorHelpers::FObjectFinder<UDataTable> DROP_OBJECT_DATATABLE(
		TEXT("DataTable'/Game/Resources/DataTables/DT_DropObjectInfo.DT_DropObjectInfo'"));

	// 로드에 성공했다면
	if (DROP_OBJECT_DATATABLE.Succeeded())
		DropObjectDataTable = DROP_OBJECT_DATATABLE.Object;
	else
	{ UE_LOG(LogTemp, Error, TEXT("DropObjectDataTable is not Loaded!")); }
}

void USpawnDropObjectComponent::InitializeDropObjInfos()
{
	// 애셋 로드에 성공했는지 확인
	if (!IsValid(DropObjectDataTable)) return;

	// DataTable 에서 행의 이름들을 얻습니다.
	for (FName rowName : DropObjectDataTable->GetRowNames())
	{
		// FindRow 메서드를 이용하여 행을 찾을 때 문제가 생길 경우
		// 문제 내용을 알릴 문자열 변수를 선언합니다.
		FString contextString;

		// DataTable 에서 이름을 이용하여 행을 찾습니다.
		FDropObjectInfo* findDropObjInfo = 
			DropObjectDataTable->FindRow<FDropObjectInfo>(rowName, contextString);

		// 찾은 데이터의 DropObjectType 이 물고기라면
		if (findDropObjInfo->DropObjectType == EDropObjectType::DT_Fish)
			FishObjInfos.Add(*findDropObjInfo);

		// 쓰레기 타입이라면
		else TrashObjInfos.Add(*findDropObjInfo);
	}
}

void USpawnDropObjectComponent::CreateDropObject()
{
	// 생성할 DropObject 타입을 저장합니다.
	EDropObjectType dropObjType = GetRandomDropType();

	// 생성시킬 DropObj 정보를 저장합니다.
	FDropObjectInfo dropObjInfo = GetRandomDropObjInfo(dropObjType);

	// 액터를 생성할 위치를 저장합니다.
	FVector spawnLocation =
		GetOwner()->GetActorLocation() +
		FMath::FRandRange(-SpawnHalfDistanceX, SpawnHalfDistanceX) * 
		FVector::RightVector;

	// 액터를 생성합니다.
	ADropObject * dropObj = GetWorld()->SpawnActor<ADropObject>(
		spawnLocation, FRotator::ZeroRotator);
	/// - SpawnActor<T>() : T 형식의 액터를 생성합니다.

	dropObj->InitializeDropObject(dropObjType, dropObjInfo.ChangeHungryValue,
		dropObjInfo.DropObjectStaticMesh, GameInst->GetPlayerCharacter());

	// 타이머를 실행시킵니다.
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this,
		&USpawnDropObjectComponent::CreateDropObject, CurrentDelay, false);
	/// - 타이머 : 정의한 시간마다 특정한 동작을 수행하는 기능을 의미합니다.
	///   타이머가 수행할 행동을 등록할 때 가능한 형식 : void()
}

EDropObjectType USpawnDropObjectComponent::GetRandomDropType() const
{
	return (FMath::FRandRange(1.0f, 100.0f) <= FishDropPercentage) ?
		EDropObjectType::DT_Fish : EDropObjectType::DT_Trash;
}

FDropObjectInfo USpawnDropObjectComponent::GetRandomDropObjInfo(
	EDropObjectType dropObjectType) const
{
	// Fish 정보중 랜덤한 정보를 리턴합니다.
	if (dropObjectType == EDropObjectType::DT_Fish)
		return (FishObjInfos[FMath::RandRange(0, FishObjInfos.Num() - 1)]);

	// Trash 정보중 랜덤한 정보를 리턴합니다.
	else return (TrashObjInfos[FMath::RandRange(0, TrashObjInfos.Num() - 1)]);
}