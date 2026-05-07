// Fill out your copyright notice in the Description page of Project Settings.


#include "KZWeapon.h"

// Sets default values
AKZWeapon::AKZWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKZWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKZWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

