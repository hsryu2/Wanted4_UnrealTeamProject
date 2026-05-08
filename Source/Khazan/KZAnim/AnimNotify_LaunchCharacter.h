// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_LaunchCharacter.generated.h"

/**
 * 
 */
UCLASS()
class KHAZAN_API UAnimNotify_LaunchCharacter : public UAnimNotify
{
	GENERATED_BODY()
	
protected:
	virtual void Notify(
		USkeletalMeshComponent* MeshComp,
		UAnimSequenceBase* Animation,
		const FAnimNotifyEventReference& EventReference) override;
public:
	UPROPERTY(EditAnywhere, Category = Launch)
	float LaunchForce = 500.0f;
};
