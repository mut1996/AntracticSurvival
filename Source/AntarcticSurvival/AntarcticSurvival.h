// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



//#include "CoreMinimal.h"
/// - �𸮾� ������Ʈ�� ������ �� �ִ� �ּ� ��ɸ� ����� ����Դϴ�.

#include "EngineMinimal.h"

// Native C++ �� �ٸ��� Unreal C++ �� ���÷��� �ý���(������Ƽ �ý���)�� �����մϴ�.
/// - ���÷���
/// - ���α׷��� �ǻ� �ð��� �ڱ� �ڽ��� ������ �� �ִ� ����� �ǹ��մϴ�.
/// - �𸮾󿡼��� ��ü������ class, structure, method, field, enumType �� ���õ� ��������
///   �����̳� �����ϴ� �ý����� ����Ǿ�������, �̷��� ���÷����� Property System �̶�� �մϴ�.

// ����� �� �ִ� ��ũ�� ����
/// - UENUM(), UCLASS(), USTRUCT(), UFUNCTION(), UPROPERTY()

// ����� Property System �� �����ϴ� �������� ��ŷ ��Ű�� ���
/// - "filename.generated.h" �� include �� ���ϴܿ� ���Խ�ŵ�ϴ�.
///   ex) #include "PlayerCharacter.generated.h"

// Unreal �� GC System
/// - UObject �������� �� �̻� �ʿ䰡 ������ ��ü�� �������ִ� �ý����Դϴ�.
/// - �޸𸮸� �ڵ����� �������ֱ� ������ �������� ������ ���� �޸� ������ ���� ������ �����ݴϴ�.

// UObject (�𸮾� ������Ʈ)
/// - �𸮾� ������ ������ �޴� ��ü�� �ǹ��մϴ�.
/// - C++ ǥ���� �ƴϸ�, Unreal �� ��ü������ �����Ͽ� �����ϴ� �����ӿ�ũ�̹Ƿ�
///   �Ϲ����� ������δ� ���� �� ������, UHT(Unreal Header Tool) �̶�� ���α׷��� ������ �޾ƾ� �մϴ�.
///   - UHT : Unreal Object �� �����ϴ� �ڵ� ���� ��

// UObject �԰ݿ� �°� �ۼ��Ͽ� UHT �� ������ �޴� ���
/// - filename.generated.h include
/// - ��ũ�� �ۼ� (ex : UCLASS())
/// - UOBJECT ���λ� �ۼ�
///   U, A, F ���...
/// - UObject �� UObject �� ������� �δ� Ŭ������ ����մϴ�.
/// - GENERATED_BODY(), GENERATED_UCLASS_BODY() ... �ۼ�

// C++ ��ü�� �𸮾� ������Ʈ�� �Ǹ� ���Ǵ� ���
/// - Ŭ���� �⺻ ��ü (Class Default Object) : ��ü�� �ʱ� ���� ��ü������ �����մϴ�.
/// - ���÷��� : ��Ÿ���� ��ü�� ������ �ǽð����� ��ȸ�� �� �ֽ��ϴ�.
/// - ������ �÷��� (GC) : �������� ���� ��ü�� �����մϴ�.
/// - ����ȭ (Serialization) : ��ü�� �Ӽ� ������ ��°�� �����ϸ� �ε��մϴ�.
/// - �븮�� (Delegate) : �Լ��� ��� ȿ�������� �����ϰ� ȣ���� �� �ֽ��ϴ�.
/// - Editor Integration : Unreal ������ �������̽��� ���Ͽ� ���� ������ �� �ֽ��ϴ�.


// unreal C++ ���� ����ϴ� �ڷ���
/// int8   : ����
/// int16  : ����
/// int32  : ����
/// int64  : ����
/// uint8  : ����
/// uint16 : ����
/// uint32 : ����
/// uint64 : ����
/// TCHAR  : ����
/// FString : �Ϲ����� ���ڿ��� ������ �� �ִ� Ÿ��
/// FName   : ��� ��ü�� �̸��� ���Ǵ� Ÿ��
///           - ��ҹ��ڸ� �������� �ʽ��ϴ�.
/// FText   : ����ȭ ���� �ؽ�Ʈ�� ���Ǵ� Ÿ��
///           - ���� UI �� ǥ�õǴ� ���ڿ��� ���Ǹ�,
///             ����ڿ��� �ٸ� ���� ������ �� �ֵ��� �մϴ�.

// ���ڿ� ��ȯ
/// - FName to FString : FNameInstance.ToString();
/// - FName to FText : FText::FromName(FNameInstance);

/// - FString to FName : FName(*FStringInstance);
///   - ��ҹ��ڸ� ������ �� ���� ��.
/// - FString to FText : FText::FromString(FStringInstance);
///   - ��ȯ �� �ڵ� ����ȭ�� �������� ���� �� ����.
/// - FText to FString : FTextInstance.ToString();
///   - �Ϻ� ���� ���������� ��ȯ���� ���� �� ����.
/// - FText to FName : FName(*FTextInstance.ToString());
///   - �Ϻ� ���� ���������� ��ȯ���� ���� �� ����.
///   - ��ҹ��ڸ� ������ �� ���� ��.

// Unreal Project Files...
/// ���� ���Ѿ� �ϴ� ���� / ����
/// - ~~~.uproject : �𸮾� ������ ������ ������Ʈ�� ���� ������ �����ϰ� �ִ� json ����
/// - Config : ������Ʈ ȯ�� ���� ���ϵ��� ��� �ִ� ����
/// - Plugin : ������Ʈ���� ����ϰ��� �ϴ� �ܺ� �÷����ε��� ��� ���� ����
/// - Source : ������

/// ���� ���ѵ� �Ǵ� ���� / ����
/// - ~~~.sln : Visual Studio ����
/// - .vs : Visual Studio �ΰ� ���� ����
/// - Binaries : C++ �ڵ� ������ ������� ����Ǵ� ����
/// - Intermediate : ������Ʈ ������ ���� �ӽ� ���ϵ��� �����ϴ� ����
/// - Saved : ������Ʈ ����� ����Ǵ� ���ϵ鿡 ���� ������ ��� ����

/// - ������ �� ���������� ������Ʈ�� ���� ���
///   - uproject ���� ��Ŭ��
///   - Generated Visual Project Files Ŭ��
///   - ~~~.sln ���� ���� Ŭ��
///   - ����ϴ� ������Ʈ�� ���� ������Ʈ�� ����
///   - ���� : Ctrl + Shift + B
///   - ������ ���� : Ctrl + F5
