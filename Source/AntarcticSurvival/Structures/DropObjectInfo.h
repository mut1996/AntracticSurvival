// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "../Enums/DropObjectType.h"
#include "DropObjectInfo.generated.h"

// - DataTable 생성시 기반 형태로 사용될 구조체를 선언합니다.
// - DataTable : 게임 개발시 개발자 뿐만이 아닌, 기획자도 손쉽게 바꿀 수 있어야 하는 
//   데이터들을 나열하여 보여주는 애셋을 의미합니다
// - 이러한 데이터 테이블을 생성하려면 항상 기반 형태가 되는 구조체가 존재해야 하며,
//   기반 형태가 될 구조체는 항상 FTableRowBase 클래스를 상속받아야 합니다.
// - FTableRowBase : 테이블 행에 표시될 데이터의 기반 형태를 작성할 수 있는 타입을 의미합니다.
//   해당 타입은 DataTable.h 내부에 정의되어 있습니다.

// 해당 구조체 타입에 대한 리플렉션 시스템을 지원하도록 합니다.
/// - BlueprintType : 블루 프린트에서도 사용 가능하도록 합니다
USTRUCT(BlueprintType)
struct ANTARCTICSURVIVAL_API FDropObjectInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	// 구조체의 경우 GENERATED_USTRUCT_BODY() 를 사용합니다.

public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDropObjectType DropObjectType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMesh * DropObjectStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ChangeHungryValue;
};
