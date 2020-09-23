// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "../Enums/DropObjectType.h"
#include "DropObjectInfo.generated.h"

// - DataTable ������ ��� ���·� ���� ����ü�� �����մϴ�.
// - DataTable : ���� ���߽� ������ �Ӹ��� �ƴ�, ��ȹ�ڵ� �ս��� �ٲ� �� �־�� �ϴ� 
//   �����͵��� �����Ͽ� �����ִ� �ּ��� �ǹ��մϴ�
// - �̷��� ������ ���̺��� �����Ϸ��� �׻� ��� ���°� �Ǵ� ����ü�� �����ؾ� �ϸ�,
//   ��� ���°� �� ����ü�� �׻� FTableRowBase Ŭ������ ��ӹ޾ƾ� �մϴ�.
// - FTableRowBase : ���̺� �࿡ ǥ�õ� �������� ��� ���¸� �ۼ��� �� �ִ� Ÿ���� �ǹ��մϴ�.
//   �ش� Ÿ���� DataTable.h ���ο� ���ǵǾ� �ֽ��ϴ�.

// �ش� ����ü Ÿ�Կ� ���� ���÷��� �ý����� �����ϵ��� �մϴ�.
/// - BlueprintType : ��� ����Ʈ������ ��� �����ϵ��� �մϴ�
USTRUCT(BlueprintType)
struct ANTARCTICSURVIVAL_API FDropObjectInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	// ����ü�� ��� GENERATED_USTRUCT_BODY() �� ����մϴ�.

public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDropObjectType DropObjectType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMesh * DropObjectStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ChangeHungryValue;
};
