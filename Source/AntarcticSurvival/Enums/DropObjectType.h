// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DropObjectType.generated.h"


// �������� �����մϴ�.
/// - BlueprintType : ��� ����Ʈ������ ��� �����ϵ��� �մϴ�.
/// - Unreal C++ ���� �������Ʈ������ ��� ������ ���� Ÿ���� ������ ���
///   BlueprintType �� �Բ� ������� Ÿ���� uint8 �������� �����ؾ� �մϴ�.

UENUM(BluePrintType)
enum class EDropObjectType : uint8
{
	DT_Trash		UMETA(DisplayName = "Trash"),
	DT_Fish			UMETA(DisplayName = "Fish")
};

// UMETA()
/// Ŭ������ �������̽�, ����ü, ���� Ÿ��, ���� Ÿ�� ���, �Լ�, �Ӽ� ����
/// �����ϴ� ����� ������ �� ����ϴ� ��Ÿ ������ �������Դϴ�.

