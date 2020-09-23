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

	// ������� �Ծ��� ��� ȣ���� �޼��带 ���ε��մϴ�.
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
	/// - ConstructorHelpers : �����ڿ��� Resource �� Blueprint Class �� 
	///   �ҷ����� �۾��� �����ִ� ����� �����ϴ� Ŭ�����Դϴ�.
	/// - FObjectFinder : Asset �� ���빰�� ������ �� ����ϴ� Ÿ��

	// �ش� Asset �� ���������� �ε��ߴٸ�
	if (SK_BODY.Succeeded())
	{
		// ĳ���� Mesh �� �ε��� �ּ����� �����մϴ�.
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
		/// - GetMesh() : Character Ŭ������ ����Ǿ��ִ� SkeletalMesh Component
		///   ��ü�� ����ϴ�.
		/// - FObjectFinderInstance.Object : �ε��� �ּ��� �ǹ��մϴ�.

		// Skeletal Mesh Component �� �������� �����մϴ�.
		GetMesh()->SetRelativeScale3D(FVector::OneVector * 0.7f);

		// ��ġ�� ȸ���� �����մϴ�.
		//GetMesh()->SetRelativeLocation(FVector::UpVector * -88.0f);
		//GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
		GetMesh()->SetRelativeLocationAndRotation(
			(FVector::UpVector * -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	}
	else
	{ UE_LOG(LogTemp, Error, TEXT("SK_BODY Load Failed!")); }

	HorizontalMovement = CreateDefaultSubobject<UHorizontalMovementComponent>(TEXT("HORIZONTAL_MOVEMENT"));
	/// - CreateDefaultSubobject<TReturnType>(HASH)
	///   TReturnType �� �ش��ϴ� Ŭ������ �����Ҵ� ��ŵ�ϴ�.
	/// - HASH : ���Ϳ� ���� ��ü���� �����ϱ� ���� ���˴ϴ�.

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