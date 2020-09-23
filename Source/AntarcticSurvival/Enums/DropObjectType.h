// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DropObjectType.generated.h"


// 열거형을 선언합니다.
/// - BlueprintType : 블루 프린트에서도 사용 가능하도록 합니다.
/// - Unreal C++ 에서 블루프린트에서도 사용 가능한 열거 타입을 선언할 경우
///   BlueprintType 과 함께 언더라잉 타입을 uint8 형식으로 지정해야 합니다.

UENUM(BluePrintType)
enum class EDropObjectType : uint8
{
	DT_Trash		UMETA(DisplayName = "Trash"),
	DT_Fish			UMETA(DisplayName = "Fish")
};

// UMETA()
/// 클래스나 인터페이스, 구조체, 열거 타입, 열거 타입 요소, 함수, 속성 등의
/// 동작하는 방식을 제거할 때 사용하는 메타 데이터 지정자입니다.

