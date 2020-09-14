// Fill out your copyright notice in the Description page of Project Settings.

#pragma once





//#include "CoreMinimal.h"
/// - �𸮾� ������Ʈ�� ������ ���ִ� �ּ� ��ɸ� ����� ����Դϴ�. 


#include "EngineMinimal.h"

// Native C++ �� �ٸ��� Unreal C++ ���÷��� �ý���(������Ƽ �ý���)�� �����մϴ�.
/// - ���÷��� 
/// - ���α׷��� ���� �ð��� �ڱ� �ڽ��� ������ �� �ִ� ����� �ǹ��մϴ�. 
/// - �𸮾󿡼��� ��ü������ Class ,structure , method , field , enumType �� ���õ� �������� 
/// - �����̳� �����ϴ� �ý����� ����Ǿ������� , �̷��� ���÷����� Property System�̶�� �մϴ�.


// ����Ҽ� �ִ� ��ũ�� ���� 
/// - UENUM() , UCLASS(), USRUCT(), UFUCNTION(), UPROPERTY() 

// �ش��� Property System �� �����Ѵ� �������� ��ŷ ��Ű�� ��� 
/// - "filename.generated.h" �� include �� ���ϴܿ� ���� ��ŵ�ϴ�. 
/// ex) #include "PlayerCharacter.generated.h"


// unreal �� GC System
/// - UObject �������� �� �̻� �ʿ䰡 ������ ��ü��  �������ִ� �ý����Դϴ�. 
/// - �޸𸮸� �ڵ����� �������ֱ� ������ �������� ������ ���� �޸� ������ ���� ������ �����ݴϴ�. 

// UObjecet (�𸮾� ������Ʈ)
/// -�𸮾� ������ ������ �޴� ��ü�� �ǹ��մϴ�. 
/// - C++ ǥ���� �ƴϸ� , Unreal �� ��ü������ �����Ͽ� ����۴�  ������ ��ũ�̹Ƿ� 
///   �Ϲ����� ������δ� ���� �� ������ , UHT(Unreal Header Tool �̶�� ���α׷��� ������ �޾ƾ��մϴ�. 
/// - UHT : Unreal Object �� �����ϴ� �ڵ� ���� ���Դϴ�.


// UObject �԰ݿ� �°� �ۼ��Ͽ� UHT �� ������ �޴� ��� 
/// - filename.generated.h include
/// - ��ũ�� �ۼ� (ex: UCLASS())
/// - UObject ���λ� �ۼ� 
///   U , A  , F ���....
/// - UObject �� Uobject �� ������� �δ� Ŭ������ ����մϴ�. 
/// - GENERATED_BODY() , GENERATED_UCLASS_BODY() ... �ۼ� 

// C++ ��ü�� �𸮾� ������Ʈ�� �Ǹ� ���Ǵ� ����
/// - Ŭ���� �⺻��ü (CLass Default Object ) : ��ü�� �ʱ� ���� ��ü������ �����մϴ�. 
/// - ���÷��� ; ��Ÿ���� ��ü�� ������ �ǽð����� ��ȸ�� �� �ֽ��ϴ�.
/// - ������ �÷��� (GC) : �������� ���� ��ü�� �����մϴ�. 
/// - ����ȭ (Serialization) : ��ü�� �Ӽ� ������ �뤊�� �����ϸ� �ε��մϴ�.
/// - �븮�� ( Delegate) : �Լ��� ��� ȿ������� �����ϰ� ȣ���� �� �ֽ��ϴ�. 
/// - Editor Intergration : Unreal ������ �������̽��� ���Ͽ� ���� �����Ҽ� �ֽ��ϴ�. 


// unreal C++ ���� ����ϴ� �ڷ��� 
/// int8			: ����
/// int16			: ����
/// int32			: ����
/// int64			: ����
/// Uint8			: ����
/// Uint16			: ����
/// Uint32			: ����
/// Uint64			: ����
/// TCHAR			: ���ڿ� 
/// FString			: �Ϲ����� ���ڿ��� ������ �� �ִ� Ÿ�� 
/// FName			: ��� ��ü�� �̸��� ���Ǵ� Ÿ��
///					- ��ҹ��ڸ� ���������ʽ��ϴ�. 
/// FText			: ����ȭ ���� �ؽ�Ʈ�� ���ȴ� Ÿ�� 
///						- ���� UI ��ǥ�õǴ� ���ڿ��� ���Ǹ� ����ڿ��� �ٸ����� ������ �� �ֵ��� �մϴ�.


// ���ڿ� ��ȯ 
/// -FName to Fstring :  FNameInstance.ToString();
/// - FName to Ftext : FTExt::FromName(FNameInstance);

/// - FString to FName : FName(*FstringInstacne);
/// - ��ҹ��� ������ �Ҽ� ���� �� 

/// - FString to FText : FText::FromString(FStringInstance);
/// - ��ȯ�� �ڵ� ����ȭ�� ���� ���� ���� ������ .

/// - FText to FString : FTextInsctance.ToString();
/// - �Ϻξ��� ���������� ��ȯ ���� ���� �� ����.

/// - FText to FName : FName (*FTextInstance.ToString());
/// - �Ϻ� ���� ���������� ��ȯ����� ������ 
/// - ��ҹ��ڸ� ������ �� ���Ե� 


// Unreal Project File..

/// ���� ���Ѿ� �ϴ� ���� / ���� 
/// -  ~~~~.uproject : �𸮾� ������ ������ ������Ʈ�� ���� ������ �����ϰ� �ִ� json ���� 
/// - Config : ������Ʈ ȯ�� ���� ���ϵ��� ��� �ִ� ���� 
/// - PlugIn : ������Ʈ ���� ����ϰ��� �ϴ� �ܺ� �÷����ε��� ��� ���� ���� 
/// - Source : ������  �������� 

///  �������ѵ� �Ǵ� ���� / ���� 
/// - ~~~.sln : ����� ��Ʃ��� ���� 
/// - .vs : ����� ��Ʃ��� �ΰ� ���� ���� 
/// - Vinaries : C++ �ڵ� ������ ������� ����Ǵ� ���� 
/// - Intermediate : ������Ʈ ������ ���� �ӽ� ���ϵ��� �����ϴ� ���� 
/// - Saved : ������Ʈ ����� ����Ǵ� ���ϵ鿡 ���� ���븣 ��� ���� 

/// - ���� �� �� ���������� ������Ʈ�� ���� ��� 
/// - uproject ���� ��Ŭ�� 
/// - Generated Visual Project Files Ŭ��  
/// - ~~~.sln ���� Ŭ�� 
/// - ����ϴ� ������Ʈ�� ���� ������Ʈ�� ���� 
/// - Ctrl + Shift + B 
/// - Ctrl + f5


