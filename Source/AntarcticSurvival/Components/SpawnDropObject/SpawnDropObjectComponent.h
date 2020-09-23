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
	// DropObject ���� ������ ������ �ִ� DataTable �ּ��� ��Ÿ�� ����
	class UDataTable* DropObjectDataTable;

	// ����� ������Ʈ ������ ������ �迭
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	TArray<FDropObjectInfo> FishObjInfos;

	// ������ ������Ʈ ������ ������ �迭
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	TArray<FDropObjectInfo> TrashObjInfos;

	// ����� ���� Ȯ��
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", ClampMin = 10.0, ClampMax = 50.0, UIMin = 10.0, UIMax = 50.0))
	float FishDropPercentage;
	/// - ClampMin, Max : �ش� �Ӽ��� ������ �� �ִ� �ּ�, �ִ� ���� �����մϴ�.
	///   �ش� �Ӽ��� ������ �ʰ��ϴ� ���� �����Ϳ��� �Է����� ��� ���� ���� ������ �����˴ϴ�.
	/// - UIMin, Max : �����̴��� ���Ͽ� ������ �� �ִ� ���� �ּ�, �ִ� ���� �����մϴ�.
	///   �����̴��� �����ϴ� ���� �ƴ�, ���� �Է��� ��� ������ �ʰ��� ���� �ԷµǾ
	///   ���� ���� ������ �������� �ʽ��ϴ�.

	// �÷��̾���� �� ������������ �Ÿ�
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float SpawnHalfDistanceX;

	// Ÿ�̸� �ڵ��� �����մϴ�.
	FTimerHandle SpawnTimerHandle;
	/// - �����Ų Ÿ�̸Ӹ� ������ �� ����� �� �ֽ��ϴ�.

	// ���� �����̸� ��Ÿ�� ����
	UPROPERTY()
	float CurrentDelay;

	// DropObject ���� �ּ� ������
	/// (MaxDelay ���� �������ϴ�.) 
	UPROPERTY(EditAnywhere)
	float MinDelay;

	// DropObject ���� �ִ� ������
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
	// ���Ǵ� �ּ��� �ε��մϴ�.
	void LoadAsset();

	// DropObjInfos �迭�� �ʱ�ȭ�մϴ�.
	void InitializeDropObjInfos();

	// DropObejct �� �����ϴ� �޼���
	/// - Ÿ�̸ӿ� ���� ȣ��˴ϴ�.
	void CreateDropObject();

	// ������ DropObejct �� Ÿ���� FishDropPercentage �� ���� ��ȯ�մϴ�.
	EDropObjectType GetRandomDropType() const;

	// dropObjectType �� ���� ������ DropObj ������ ��ȯ�մϴ�.
	FDropObjectInfo GetRandomDropObjInfo(EDropObjectType dropObjectType) const;
};
