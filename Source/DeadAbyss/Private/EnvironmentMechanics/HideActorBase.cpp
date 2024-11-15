// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvironmentMechanics/HideActorBase.h"

// Sets default values
AHideActorBase::AHideActorBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHideActorBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AHideActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

