// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "../../Components/HorizontalMovement/HorizontalMovementComponent.h"
#include "../PlayerController/Game/GamePlayerController.h"
#include "../../AnimInstances/PlayerCharacterAnimInst.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitializeComponents();
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerController = Cast<AGamePlayerController>(GetController());

	// 대미지를 입었을 경우 호출할 메서드를 바인딩합니다.
	OnTakeAnyDamage.AddDynamic(this, &APlayerCharacter::OnHit);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerCharacter::InitializeComponents()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(
		TEXT("SkeletalMesh'/Game/Resources/Character/SK_Penguin.SK_Penguin'"));
	/// - ConstructorHelpers : 생성자에서 Resource 나 Blueprint Class 를 
	///   불러오는 작업을 도와주는 기능을 제공하는 클래스입니다.
	/// - FObjectFinder : Asset 의 내용물을 가져올 때 사용하는 타입

	// 해당 Asset 을 성공적으로 로드했다면
	if (SK_BODY.Succeeded())
	{
		// 캐릭터 Mesh 를 로드한 애셋으로 설정합니다.
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
		/// - GetMesh() : Character 클래스에 내장되어있는 SkeletalMesh Component
		///   객체를 얻습니다.
		/// - FObjectFinderInstance.Object : 로드한 애셋을 의미합니다.

		// Skeletal Mesh Component 의 스케일을 설정합니다.
		GetMesh()->SetRelativeScale3D(FVector::OneVector * 0.7f);

		// 위치와 회전을 설정합니다.
		//GetMesh()->SetRelativeLocation(FVector::UpVector * -88.0f);
		//GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
		GetMesh()->SetRelativeLocationAndRotation(
			(FVector::UpVector * -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	}
	else
	{ UE_LOG(LogTemp, Error, TEXT("SK_BODY Load Failed!")); }

	HorizontalMovement = CreateDefaultSubobject<UHorizontalMovementComponent>(TEXT("HORIZONTAL_MOVEMENT"));
	/// - CreateDefaultSubobject<TReturnType>(HASH)
	///   TReturnType 에 해당하는 클래스를 동적할당 시킵니다.
	/// - HASH : 액터에 속한 객체들을 구별하기 위해 사용됩니다.

	static ConstructorHelpers::FClassFinder<UPlayerCharacterAnimInst> ANIM_PLAYER(
		TEXT("AnimBlueprint'/Game/Resources/Blueprints/AnimBP_PlayerCharater.AnimBP_PlayerCharater_C'"));

	if (ANIM_PLAYER.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(ANIM_PLAYER.Class);
	}
}

void APlayerCharacter::OnHit(AActor* DamagedActor, float Damage,
	const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerCharacter OnHit Call!!!"));


}