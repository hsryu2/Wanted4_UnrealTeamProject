// Fill out your copyright notice in the Description page of Project Settings.


#include "KZBossCharacter.h"

// Sets default values
AKZBossCharacter::AKZBossCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

// Called to bind functionality to input
void AKZBossCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

