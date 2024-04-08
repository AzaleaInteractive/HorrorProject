// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvironmentMechanics/PowerButton.h"

// Sets default values
APowerButton::APowerButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APowerButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

