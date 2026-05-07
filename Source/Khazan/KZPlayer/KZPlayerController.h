// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KZPlayerController.generated.h"

// 전방 선언
class UInputMappingContext;
class UInputAction;


/**
 * 
 */
UCLASS()
class KHAZAN_API AKZPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AKZPlayerController();
};
