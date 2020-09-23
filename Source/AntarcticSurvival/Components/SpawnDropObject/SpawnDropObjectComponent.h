#pragma once

#include "AntarcticSurvival.h"
#include "Components/ActorComponent.h"
#include "../../Structures/DropObjectInfo.h"
#include "SpawnDropObjectComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ANTARCTICSURVIVAL_API USpawnDropObjectComponent : public UActorComponent
{
	GENERATED_BODY()

private :
	// DropObject 들의 정보를 가지고 있는 DataTable 애셋을 나타낼 변수
	class UDataTable* DropObjectDataTable;

	// 물고기 오브젝트 정보를 저장할 배열
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	TArray<FDropObjectInfo> FishObjInfos;

	// 쓰레기 오브젝트 정보를 저장할 배열
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	TArray<FDropObjectInfo> TrashObjInfos;

	// 물고기 생성 확률
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", ClampMin = 10.0, ClampMax = 50.0, UIMin = 10.0, UIMax = 50.0))
	float FishDropPercentage;
	/// - ClampMin, Max : 해당 속성에 설정될 수 있는 최소, 최대 값을 지정합니다.
	///   해당 속성에 범위를 초과하는 값을 에디터에서 입력했을 경우 범위 내의 값으로 설정됩니다.
	/// - UIMin, Max : 슬라이더를 총하여 설정될 수 있는 값의 최소, 최대 값을 지정합니다.
	///   슬라이더를 조종하는 것이 아닌, 값을 입력할 경우 범위를 초과한 값이 입력되어도
	///   범위 내의 값으로 설정되지 않습니다.

	// 플레이어부터 양 끝지점까지의 거리
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float SpawnHalfDistanceX;

	// 타이머 핸들을 선언합니다.
	FTimerHandle SpawnTimerHandle;
	/// - 실행시킨 타이머를 제어할 떄 사용할 수 있습니다.

	// 현재 딜레이를 나타낼 변수
	UPROPERTY()
	float CurrentDelay;

	// DropObject 생성 최소 딜레이
	/// (MaxDelay 까지 빨라집니다.) 
	UPROPERTY(EditAnywhere)
	float MinDelay;

	// DropObject 생성 최대 딜레이
	UPROPERTY(EditAnywhere)
	float MaxDelay;

	// UASGameInstance
	class UASGameInstance* GameInst;
	
	

public:	
	USpawnDropObjectComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private :
	// 사용되는 애셋을 로드합니다.
	void LoadAsset();

	// DropObjInfos 배열을 초기화합니다.
	void InitializeDropObjInfos();

	// DropObejct 를 생성하는 메서드
	/// - 타이머에 의해 호출됩니다.
	void CreateDropObject();

	// 생성할 DropObejct 의 타입을 FishDropPercentage 에 따라 반환합니다.
	EDropObjectType GetRandomDropType() const;

	// dropObjectType 에 따라 랜덤한 DropObj 정보를 반환합니다.
	FDropObjectInfo GetRandomDropObjInfo(EDropObjectType dropObjectType) const;
};
