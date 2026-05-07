// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BossAIController.generated.h"

/**
 * 
 */
UCLASS()
class KHAZAN_API ABossAIController : public AAIController
{
	GENERATED_BODY()

public:
	ABossAIController();

protected:

	// 보스가 스폰되어 이 컨트롤러가 빙의했을 때 실행
	
};
