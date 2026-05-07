// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_EnableMovement.h"
#include "../Interface/KZAnimationAttackInterface.h"

void UAnimNotify_EnableMovement::Notify(
	USkeletalMeshComponent* MeshComp,
	UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp)
	{
		IKZAnimationAttackInterface* AttackPawn = Cast<IKZAnimationAttackInterface>(MeshComp->GetOwner());
		if (AttackPawn)
		{
			AttackPawn->AttackEndCheck();
		}
	}
}
