// Fill out your copyright notice in the Description page of Project Settings.


#include "KZBossCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Navigation/PathFollowingComponent.h"

// Sets default values
AKZBossCharacter::AKZBossCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentMovementSpeed = 0.0f;
	CurrentPhase = EBossPhase::Phase1A;

	// 루트 모션 사용 시 물리 회전/이동 허용
	GetCharacterMovement()->bAllowPhysicsRotationDuringAnimRootMotion = true;
}

// Called when the game starts or when spawned
void AKZBossCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKZBossCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 현재 속도를 계산하여 저장 (애니메이션 블루프린트에서 참조됨)
	CurrentMovementSpeed = GetVelocity().Size();

}

// Called to bind functionality to input
void AKZBossCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AKZBossCharacter::PlayAttackMontage()
{
	if (BasicAttackMontage)
	{
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		if (AnimInstance)
		{
			// 랜덤 섹션 이름 결정
			// 1: 회전 후 1타, 2: 2연속 타격, 3: 연속 찌르기
			int32 RandomIdx = FMath::RandRange(1, 4);
			FName SectionName = FName(*FString::Printf(TEXT("BAtk%d"), RandomIdx));

			// 몽타주 재생
			AnimInstance->Montage_Play(BasicAttackMontage);
		
			AnimInstance->Montage_JumpToSection(SectionName, BasicAttackMontage);

			// 몽타주가 끝났을 때 실행될 함수(람다) 연결
			FOnMontageEnded EndDelegate;
			EndDelegate.BindLambda([this](UAnimMontage* Montage, bool bInterrupted)
				{
	
					AAIController* AIC = Cast<AAIController>(GetController());

					// 공격이 끝났을 때 BB의 isAttacking 값을 false로 설정하여 공격 상태 종료
					if (AIC && AIC->GetBlackboardComponent())
					{
						AIC->GetBlackboardComponent()->SetValueAsBool(FName("isAttacking"), false);
					}

				});

			// 몽타주가 끝났을 때 호출될 델리게이트 설정
			AnimInstance->Montage_SetEndDelegate(EndDelegate, BasicAttackMontage);
		}
	}
}

void AKZBossCharacter::ExecuteBackStep(float Distance, float UpForce)
{
	AAIController* AIC = Cast<AAIController>(GetController());
	if (AIC)
	{
		if (AIC->GetPathFollowingComponent())
		{
			AIC->GetPathFollowingComponent()->AbortMove(*AIC, FPathFollowingResultFlags::MovementStop);
		}

		//if (AIC->GetBrainComponent())
		//{
		//	AIC->GetBrainComponent()->PauseLogic("Backstepping");
		//}

		// UPathFollowingComponent를 완전한 형식으로 인식시키기 위해 헤더를 반드시 포함해야 함
		//UPathFollowingComponent* PathComp = AIC->GetPathFollowingComponent();
		//if (PathComp)
		//{
		//	PathComp->AbortMove(*AIC, FPathFollowingResultFlags::MovementStop);
		//}
	}

	GetCharacterMovement()->SetMovementMode(MOVE_Falling);
	FVector BackDir = -GetActorForwardVector();
	FVector LaunchVelocity = BackDir * Distance + FVector(0, 0, UpForce);
	UE_LOG(LogTemp, Warning, TEXT("BackStep Execute! Vector: %s"), *LaunchVelocity.ToString());
	LaunchCharacter(LaunchVelocity, true, true);
}

