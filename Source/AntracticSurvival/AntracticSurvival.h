// Fill out your copyright notice in the Description page of Project Settings.

#pragma once





//#include "CoreMinimal.h"
/// - 언리얼 오브젝트가 동작할 수있는 최소 기능만 선언된 헤더입니다. 


#include "EngineMinimal.h"

// Native C++ 과 다르게 Unreal C++ 리플렉션 시스템(프로퍼티 시스템)을 지원합니다.
/// - 리플랙션 
/// - 프로그램이 실행 시간에 자기 자신을 조사할 수 있는 기능을 의미합니다. 
/// - 언리얼에서는 자체적으로 Class ,structure , method , field , enumType 과 관련된 정보들을 
/// - 수집이나 좆가하는 시스템이 구축되어있으며 , 이러한 리플렉션을 Property System이라고 합니다.


// 사용할수 있는 마크업 종류 
/// - UENUM() , UCLASS(), USRUCT(), UFUCNTION(), UPROPERTY() 

// 해더에 Property System 을 지원한느 유형으로 마킹 시키는 방법 
/// - "filename.generated.h" 를 include 문 최하단에 포함 시킵니다. 
/// ex) #include "PlayerCharacter.generated.h"


// unreal 의 GC System
/// - UObject 한정으로 더 이상 필요가 없어진 객체를  해제해주는 시스템입니다. 
/// - 메모리를 자동으로 관리해주기 때문에 해제하지 않음에 대한 메모리 누수와 같은 걱정을 덜어줍니다. 

// UObjecet (언리얼 오브젝트)
/// -언리얼 엔진의 관리를 받는 객체를 의미합니다. 
/// - C++ 표준이 아니며 , Unreal 이 자체적으로 제작하여 제고앟는  프레임 워크이므로 
///   일반적인 방식으로는 만들 수 없으며 , UHT(Unreal Header Tool 이라는 프로그램의 도움을 받아야합니다. 
/// - UHT : Unreal Object 를 지원하는 코드 생성 툴입니다.


// UObject 규격에 맞게 작성하여 UHT 의 지원을 받는 방법 
/// - filename.generated.h include
/// - 마크업 작성 (ex: UCLASS())
/// - UObject 접두사 작성 
///   U , A  , F 등등....
/// - UObject 나 Uobject 를 기반으로 두는 클래스를 상속합니다. 
/// - GENERATED_BODY() , GENERATED_UCLASS_BODY() ... 작성 

// C++ 객체가 언리얼 오븢게트가 되면 향상되는 긴으
/// - 클래스 기본객체 (CLass Default Object ) : 객체의 초기 값을 자체적으로 관리합니다. 
/// - 리플렉션 ; 런타임중 객체의 정보를 실시간으로 조회할 수 있습니다.
/// - 가비지 컬렉터 (GC) : 참조되지 않은 객체를 해제합니다. 
/// - 직렬화 (Serialization) : 객체와 속성 정보를 통쨰로 보관하며 로드합니다.
/// - 대리자 ( Delegate) : 함수를 묶어서 효과저긍로 관리하고 호출할 수 있습니다. 
/// - Editor Intergration : Unreal 에디터 인터페이스를 통하여 값을 편집할수 있습니다. 


// unreal C++ 에서 사용하는 자료형 
/// int8			: 정수
/// int16			: 정수
/// int32			: 정수
/// int64			: 정수
/// Uint8			: 정수
/// Uint16			: 정수
/// Uint32			: 정수
/// Uint64			: 정수
/// TCHAR			: 문자열 
/// FString			: 일반적인 문자열을 저장할 수 있는 타입 
/// FName			: 어떠한 객체의 이름에 사용되는 타입
///					- 대소문자를 구별하지않습니다. 
/// FText			: 현지화 가능 텍스트에 사용된느 타입 
///						- 보통 UI 에표시되는 문자열에 사용되며 사용자에게 다른언어로 번역될 수 있도록 합니다.


// 문자열 변환 
/// -FName to Fstring :  FNameInstance.ToString();
/// - FName to Ftext : FTExt::FromName(FNameInstance);

/// - FString to FName : FName(*FstringInstacne);
/// - 대소문자 구분을 할수 없게 됨 

/// - FString to FText : FText::FromString(FStringInstance);
/// - 변환후 자동 현지화가 지원 되지 않을 수있음 .

/// - FText to FString : FTextInsctance.ToString();
/// - 일부언어에서 정상적으로 변환 되지 않을 수 있음.

/// - FText to FName : FName (*FTextInstance.ToString());
/// - 일부 언어에서 정상적으로 변환됮않을 수있음 
/// - 대소문자를 구분할 수 없게됨 


// Unreal Project File..

/// 유지 시켜야 하는 폴더 / 파일 
/// -  ~~~~.uproject : 언리얼 에디터 구동시 프로젝트에 대한 정보를 포함하고 있는 json 파일 
/// - Config : 프로젝트 환경 설정 파일들을 담고 있는 폴더 
/// - PlugIn : 프로젝트 에서 사용하고자 하는 외부 플러그인들을 모아 놓은 폴더 
/// - Source : 생명줄  ㅋㄷㅋㄷ 

///  삭제시켜도 되는 폴더 / 파일 
/// - ~~~.sln : 비쥬얼 스튜디오 파일 
/// - .vs : 비쥬얼 스튜디오 부가 정보 파일 
/// - Vinaries : C++ 코드 컴파일 결과물이 저장되는 폴더 
/// - Intermediate : 프로젝트 관리를 위한 임시 파일들을 저장하는 폴더 
/// - Saved : 프로젝트 상요중 저장되는 파일들에 대한 내용르 담는 폴더 

/// - 제거 한 후 정상적으로 프로젝트를 여는 방법 
/// - uproject 파일 우클릭 
/// - Generated Visual Project Files 클릭  
/// - ~~~.sln 파일 클릭 
/// - 사용하는 프로젝트를 시작 프로젝트로 설정 
/// - Ctrl + Shift + B 
/// - Ctrl + f5


